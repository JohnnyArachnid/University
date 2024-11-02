package org.life;

public class LifeSimulator {

  public static void main(String[] args) {
    Board board = new Board(5, 5);
    Organism organism1 = new Organism(Organism.random.nextInt(100)+1, 1, "Basic");
    Sportsman organism2 = new Sportsman(Organism.random.nextInt(100)+1, 2, "Sportsman");
    Scientist organism3 = new Scientist(Organism.random.nextInt(100)+1, 3, "Scientist");
    board.addOrganism(organism1, 0, 0);
    board.addOrganism(organism2, 2, 2);
    board.addOrganism(organism3, 4, 4);
    for(int i = 0; i < 10; i++){
      organism1.move();
      organism2.move();
      organism3.move();
      System.out.println("Koniec tury numer: "+(i+1)+" Pozycja graczy: 1. x: "+ organism1.position.getX() + ", y: " + organism1.position.getY() + " ||| "+ " 2. x: " + organism2.position.getX() + ", y: " + organism2.position.getY() + " ||| "+" 3. x: "+organism3.position.getX()+", y: "+organism3.position.getY());
    }
    System.out.println("\nLiczba wygranych pojedynków graczy oraz końcowa energia:\n1. "+organism1.getCountBattles()+", "+organism1.getEnergy()+"\n2. "+organism2.getCountBattles()+", "+organism2.getEnergy()+"\n3. "+organism3.getCountBattles()+", "+organism3.getEnergy());
  }
}