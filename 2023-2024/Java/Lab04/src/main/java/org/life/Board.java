package org.life;

public class Board {

  private static int width;
  private static int height;
  private static Organism[][] organisms;

  public Board(int width, int height) {
    this.width = width;
    this.height = height;
    this.organisms = new Organism[width][height];
  }

  public void addOrganism(Organism organism, int x, int y) {
    if (organisms[x][y] == null) {
      organisms[x][y] = organism;
      organism.setPosition(new Position(x, y));
    } else {
      System.out.println("Position already occupied!");
    }
  }

  public static void moveOrganism(Organism organism, int newX, int newY) {
    if (newX >= 0 && newX < width && newY >= 0 && newY < height && organisms[newX][newY] == null) {
      organisms[organism.getPosition().getX()][organism.getPosition().getY()] = null;
      organisms[newX][newY] = organism;
      organism.setPosition(new Position(newX, newY));
    } else if (newX >= 0 && newX < width && newY >= 0 && newY < height && organisms[newX][newY] != null) {
      int numer = organism.fight(organisms[newX][newY]);
      if (numer == 1) {
        organisms[organism.getPosition().getX()][organism.getPosition().getY()] = null;
        organisms[newX][newY] = null;
        organisms[newX][newY] = organism;
        organism.setPosition(new Position(newX, newY));

      } else if (numer == 2) {
        organisms[organism.getPosition().getX()][organism.getPosition().getY()] = null;
      }
    }
    else if (newX == -1) {
      moveOrganism(organism, newX+2, newY);
    } else if (newX == width) {
      moveOrganism(organism, newX-2, newY);
    } else if (newY == -1) {
      moveOrganism(organism, newX, newY+2);
    } else if (newY == height) {
      moveOrganism(organism, newX, newY-2);
    }
  }
}
