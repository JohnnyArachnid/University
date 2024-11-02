package org.studentresource.decorator;

import org.studentresource.StudentResource;

public class RateableResource extends ResourceDecorator{
    private double rating;
    public RateableResource(StudentResource decoratedResource) { super(decoratedResource); }
    public double getRating() { return this.rating; }
    public void setRating(double rating) { this.rating = rating; }
}
