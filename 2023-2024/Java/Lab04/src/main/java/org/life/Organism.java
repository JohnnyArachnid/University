package org.life;

import java.util.Random;

public class Organism {

  protected int energy;
  protected Position position;
  protected static Random random = new Random();

  protected int countBattles;

  protected int number;

  protected boolean isDead = false;

  private String nazwaKlasy;

  public Organism(int energy, int number, String nazwaKlasy) {
    this.energy = energy;
    this.number = number;
    this.nazwaKlasy = nazwaKlasy;
    this.countBattles = 0;
    System.out.println("Stworzono gracza o klasie: "+this.getNazwaKlasy()+" o numerze: "+this.getNumber()+" wartosc energi: "+this.getEnergy()+"\n");
  }

  public void move() {
    if (!isDead && this.getEnergy() != 0) {
      int newX = position.getX();
      int newY = position.getY();


      // Decide whether to move vertically or horizontally
      boolean moveVertically = random.nextBoolean();

      if (moveVertically) {
        // Move up or down by 1
        newY += random.nextBoolean() ? 1 : -1;
      } else {
        // Move left or right by 1
        newX += random.nextBoolean() ? 1 : -1;
      }
      Board.moveOrganism(this, newX, newY);
    }
    else {
      this.position.setX(0);
      this.position.setY(0);
    }
  }

  public void setPosition(Position position) {
    this.position = position;
  }

  public Position getPosition() {
    return position;
  }

  public int getEnergy() { return energy; }

  public int getCountBattles() { return countBattles; }

  public void upCountBattles() { this.countBattles += 1; }

  public int getNumber() { return number;}

  public String getNazwaKlasy() { return nazwaKlasy; }

  public void death() { this.energy = 0; this.position.setX(0); this.position.setY(0); this.isDead = true;}

  public void setNazwaKlasy(String nazwa) {
    if(nazwa == "SportsMan") {
      this.nazwaKlasy = nazwa;
    } else if (nazwa == "Scientist") {
      this.nazwaKlasy = nazwa;
    } else {
      this.nazwaKlasy = nazwa;
    }
  }

  public void setEnergy(int energy) { this.energy = energy; }

  public int fight(Organism organism2){
    if(this.getEnergy() > organism2.getEnergy() && this.isDead == false && organism2.isDead == false) {
      System.out.println("\nPojedynek!");
      this.setEnergy(this.getEnergy() + organism2.getEnergy());
      this.upCountBattles();
      organism2.death();
      System.out.println("Gracz o numerze: " + this.getNumber() + " wygrywa pojedynek z graczem o numerze: " + organism2.getNumber() + "\n" + "R.I.P numer: " + organism2.getNumber() + " to: " + organism2.getNazwaKlasy() + "\n" + "Liczba zwycieskich walk gracza numerze: " + this.getNumber() + " to: " + this.getCountBattles() + "\n");
      return 1;
    } else if (this.getEnergy() < organism2.getEnergy() && this.isDead == false && organism2.isDead == false) {
      System.out.println("\nPojedynek!");
      organism2.setEnergy(this.getEnergy() + organism2.getEnergy());
      organism2.upCountBattles();
      this.death();
      System.out.println("Gracz o numerze: "+ organism2.getNumber() +" wygrywa pojedynek z graczem o numerze: " +this.getNumber() + "\n"+ "\n" + "R.I.P numer: " +this.getNumber() + " to: "+ this.getNazwaKlasy() +"\n"+"Liczba zwycieskich walk gracza numerze: "+organism2.getNumber()+" to: "+organism2.getCountBattles()+"\n");
      return 2;
    } else {
      if (!(this.getEnergy() == 0 || organism2.getEnergy() == 0)) {
        if (random.nextBoolean() == true) {
          this.setEnergy(this.getEnergy() + 1);
        } else {
          organism2.setEnergy(organism2.getEnergy() + 1);
        }
        System.out.println("Remis, powtarzamy walkę!");
        fight(organism2);
      }
    }
      return 0;
  }
}

