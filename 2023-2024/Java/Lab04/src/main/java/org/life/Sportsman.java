package org.life;

public class Sportsman extends Organism {

    public Sportsman(int energy, int numer, String nazwaKlasy){
        super(energy,numer,nazwaKlasy);
        this.isDead = false;
    }

    public void move() {
        if (!isDead && this.getEnergy() != 0) {
            int newX = position.getX();
            int newY = position.getY();

            boolean wynik;

            // Decide whether to move vertically or horizontally
            boolean moveVertically = random.nextBoolean();

            if (moveVertically) {
                // Move up or down by 1
                newY += random.nextBoolean() ? 1 : -1;
                wynik = true;
            } else {
                // Move left or right by 1
                newX += random.nextBoolean() ? 1 : -1;
                wynik = false;
            }
            //Poruszanie się po L-ce, umiejetnosc Sportsman
            if (wynik && !isDead == true && this.getEnergy() != 0) {
                Board.moveOrganism(this, newX += random.nextBoolean() ? 1 : -1, newY);
            } else {
                Board.moveOrganism(this, newX, newY += random.nextBoolean() ? 1 : -1);
            }
        } else {
            this.position.setX(0);
            this.position.setY(0);
        }
    }
}

