package org.starmap.model;

// Represents a star in the star map
public class Star {
    private String name;
    private double xPosition;
    private double yPosition;
    private double brightness;

    public Star(String name, double xPosition, double yPosition, double brightness) {
        this.name = name;
        this.xPosition = xPosition;
        this.yPosition = yPosition;
        this.brightness = brightness;
    }

    // Getters and setters
    public String getName() {
        return name;
    }

    public double getXPosition() {
        return xPosition;
    }

    public void setxPosition(double x) {
        this.xPosition = x;
    }

    public double getYPosition() {
        return yPosition;
    }

    public void setyPosition(double y) {
        this.yPosition = y;
    }

    public double getBrightness() {
        return brightness;
    }

    public void setBrightness(double Britghness) {this.brightness = Britghness;}

    public void setName(String name) {
        this.name = name;
    }

}
