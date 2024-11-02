package org.ticketsystem.ticketdecorator;

import org.ticketsystem.Ticket;

// TODO dokończ implementację dekoratora dodającego posiłek do biletu
public class MealTicketDecorator extends TicketDecorator {
    public MealTicketDecorator(Ticket ticket) {
        super(ticket);
    }

    public String getDescription() {
        return super.getDescription() + ", with Meal";
        // TODO dodaje ", with Meal" do opisu
    }

    public double getPrice() {
        return super.getPrice() + 20;
        // TODO dodaje 20 do ceny biletu
    }
}
