package org.life;

public class Scientist extends Organism {
    public Scientist(int energy, int numer, String nazwaKlasy){
        super(energy,numer,nazwaKlasy);
    }
    //Wygrywa w przypadku remisu umiejetnosc Scientist
    public int fight(Organism organism2) {
        if (this.getEnergy() >= organism2.getEnergy() && this.isDead == false && organism2.isDead == false) {
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
            System.out.println("Gracz o numerze: " + organism2.getNumber() + " wygrywa pojedynek z graczem o numerze: " + this.getNumber() + "\n" + "\n" + "R.I.P numer: " + this.getNumber() + " to: " + this.getNazwaKlasy() + "\n" + "Liczba zwycieskich walk gracza numerze: " + organism2.getNumber() + " to: " + organism2.getCountBattles() + "\n");
            return 2;
        }
        return 0;
    }
}
