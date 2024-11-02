package org.ticketsystem.ticketdecorator;

import org.ticketsystem.Ticket;

// TODO dokończ implementację dekoratora
public abstract class TicketDecorator implements Ticket {
    private Ticket decoratedTicket;

    public TicketDecorator(Ticket decoratedTicket) {
        this.decoratedTicket = decoratedTicket;
    }

    public String getDescription() {
        return decoratedTicket.getDescription();
        // TODO zwraca opis udekorowanego biletu
    }

    public double getPrice() {
        return decoratedTicket.getPrice();
        // TODO zwraca opis udekorowanego biletu
    }

    public Ticket getDecoratedTicket() {
        return decoratedTicket;
        // TODO zwraca udekorowany bilet
    }
}
