package org.starmap.model;

import java.util.List;
import java.util.Objects;

// Represents a constellation made up of stars
public class Constellation {
    private String name;
    final private List<Star> stars;

    public Constellation(String name, List<Star> stars) {
        this.name = name;
        this.stars = stars;
    }

    // Getters
    public String getName() {
        return name;
    }

    public List<Star> getStars() {
        return stars;
    }

    public void addStar(Star star) {
        stars.add(star);
    }

    public void removeStar(String starName) {
        stars.removeIf(star -> star.getName().equalsIgnoreCase(starName));
    }

    public void setName(String name){
        this.name = name;
    }

}
