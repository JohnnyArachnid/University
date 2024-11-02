package org.ticketsystem.ticketdecorator;

import org.ticketsystem.Ticket;

// TODO dokończ implementację dekoratora dodającego miejsce siedzące VIP do biletu
public class VIPSeatDecorator extends TicketDecorator {
    public VIPSeatDecorator(Ticket ticket) {
        super(ticket);
    }

    public String getDescription() {
        return super.getDescription() + ", VIP Seat";
        // TODO dodaje ", VIP Seat" do opisu
    }

    public double getPrice() {
        return super.getPrice() + 50;
        // TODO dodaje 50 do ceny biletu
    }
}
