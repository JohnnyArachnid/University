import itertools

import numpy as np
import random

from deap import base, creator, tools, algorithms

from representation import House
import operators as op
from visualization import visualize
from loss_functions import loss_function2


if __name__ == '__main__':
    creator.create("FitnessMin", base.Fitness, weights=(-1.0,))  # Minimizing fitness
    creator.create("Individual", list, fitness=creator.FitnessMin)  # Defining individual with fitness

    toolbox = base.Toolbox()

    def generate_house():
        rows, cols = 6, 6
        house = House(rows, cols)  # Create a house
        individual = creator.Individual([house])  # Create individual with the house inside
        loss = loss_function2(individual)
        individual.fitness.values = loss  # Evaluate fitness for the individual
        return individual

    # ========Operators========
    toolbox.register("individual", generate_house)
    toolbox.register("population", tools.initRepeat, list, toolbox.individual)
    toolbox.register("evaluate", loss_function2)

    #========crossover========
    toolbox.register("mate", op.crossover_swap_row_or_column)
    #toolbox.register("mate", op.crossover_chessboard)
    #toolbox.register("mate", op.crossover_diagonal)
    # ========mutation========
    toolbox.register("mutate1", op.mutation_row_or_column)
    toolbox.register("mutate2", op.mutate_individual)
    toolbox.register("mutate3", op.mutate_rotate_segment)
    toolbox.register("mutate4", op.mutation_change_doors)
    toolbox.register("mutate5", op.mutation_special_containers)
    toolbox.register("mutate", op.mutate_add_road)
    # ========select========
    toolbox.register("select", tools.selTournament, tournsize=9)
    #toolbox.register("select", tools.selBest)
    #toolbox.register("select", op.sel_roulette_inverted)

    # Algorytm ewolucyjny
    def run_algorithm():
        population = toolbox.population(n=200)
        for generation in range(100):  # Liczba generacji
            offspring = toolbox.select(population, len(population))
            offspring = list(map(toolbox.clone, offspring))

            # Krzyżowanie i mutacja
            CROSS_OVER_P = 0.8
            MUTATION_MAIN_P = 1
            MUTATION_ADDITIONAL_P = 0.25
            for child1, child2 in zip(offspring[::2], offspring[1::2]):
                if random.random() < CROSS_OVER_P:  # Prawdopodobieństwo krzyżowania
                    toolbox.mate(child1, child2)
                if random.random() < MUTATION_MAIN_P:
                    toolbox.mutate(child1)
                    toolbox.mutate(child2)
                if random.random() < MUTATION_ADDITIONAL_P:
                    toolbox.mutate1(child1)
                    toolbox.mutate1(child2)
                if random.random() < MUTATION_ADDITIONAL_P:
                    toolbox.mutate2(child1)
                    toolbox.mutate2(child2)
                if random.random() < MUTATION_ADDITIONAL_P:
                    toolbox.mutate3(child1)
                    toolbox.mutate3(child2)
                if random.random() < MUTATION_ADDITIONAL_P:
                    toolbox.mutate4(child1)
                    toolbox.mutate4(child2)
                if random.random() < MUTATION_ADDITIONAL_P:
                    toolbox.mutate5(child1)
                    toolbox.mutate5(child2)

            # Ocena nowego pokolenia
            for ind in offspring:
                ind.fitness.values = loss_function2(ind)

            # Selekcja najlepszych osobników
            population[:] = tools.selBest(offspring, len(population))

        # Zwróć najlepszego osobnika
        best_individual = tools.selBest(population, 1)[0]

        return best_individual

    # Uruchomienie algorytmu
    best_house = run_algorithm()

    # Selecting the best individual
    print(f"Najlepszy wynik:\n {best_house[0]},\n wartość celu: {best_house.fitness.values[0]}")
    visualize(best_house[0], showIDs=True)
    print(best_house[0].check_connectivity_subgraphs())