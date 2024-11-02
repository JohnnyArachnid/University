package org.ticketsystem;

// TODO uzupełnij implementację (same ciała getterów są już OK)
public class BasicTicket implements Ticket {
    private final double price;

    public BasicTicket(double price) {
        this.price = price;
    }

    public String getDescription() {
        return "Basic Ticket";
    }

    public double getPrice() {
        return this.price;
    }
}
