def loss_function1(house):
    h = house[0]
    distances = h.get_distance()
    subgraph_count, unavaible_containers_count = h.check_connectivity_subgraphs()

    mean_kitchen = 0
    mean_sanitary = 0
    mean_common = 0
    #print(subgraph_count, unavaible_containers_count)
    for _,dist in distances:
        mean_kitchen += dist[0]
        mean_sanitary += dist[1]
        mean_common += dist[2]
    if( len(distances) == 0):
        pass
    else:
        mean_kitchen /= len(distances)
        mean_sanitary /= len(distances)
        mean_common /= len(distances)

    loss = (mean_kitchen + mean_sanitary + mean_common)*3 + (unavaible_containers_count)*100 + (subgraph_count-1)*500 + (1/((h.houses**2) +1))*1000
    loss = loss if loss>=0 else 0
    return loss,

def loss_function2(house, flag=False):
    h = house[0]
    distances = h.get_distance()
    h.count_block()
    subgraph_count, unavaible_containers_count = h.check_connectivity_subgraphs()

    mean_kitchen = 0
    mean_sanitary = 0
    mean_common = 0

    for _, dist in distances:
        mean_kitchen += dist[0]
        mean_sanitary += dist[1]
        mean_common += dist[2]

    if len(distances) > 0:
        mean_kitchen /= len(distances)
        mean_sanitary /= len(distances)
        mean_common /= len(distances)


    # Kara za niepołączone podgrafy i niedostępne kontenery
    connectivity_penalty = ((subgraph_count-1) * 10000) + (unavaible_containers_count * 10000)

    # Kara za odległość do pomieszczeń użytkowych
    distance_penalty = (mean_kitchen + mean_sanitary + mean_common) * 5

    # Nagroda za więcej mieszkań
    house_bonus = (1 / (h.houses ** 2)) * 10000 if h.houses != 0 else 90000

    # Funkcja celu
    loss = house_bonus + connectivity_penalty + distance_penalty

    return max(loss, 0),
