package org.chatbot.logic;

import org.chatbot.database.IDatabaseConnection;
import org.chatbot.response.Response;
import org.chatbot.response.ResponseType;

import java.sql.ResultSet;
import java.sql.SQLException;

public class ChatbotLogic {
    private IDatabaseConnection dbConnection;
    private boolean awaitingConfirmation;
    private int pendingReservationId;
    private boolean isFirstMessage = true;

    // TODO: Inicjalizacja logiki chatbota z połączeniem do bazy danych
    public ChatbotLogic(IDatabaseConnection dbConnection) {
        this.dbConnection = dbConnection;
        this.awaitingConfirmation = false;
        this.pendingReservationId = -1;
    }

    public Response processInput(String input) {
        if (isFirstMessage) {
            isFirstMessage = false;
            return new Response(ResponseType.WELCOME, ResponseType.WELCOME.getMessage());
        }
        try {
            if (input.equalsIgnoreCase(CommandConstants.RESERVE)) {
                // Logika dodawania rezerwacji, symulowane, nie bierze pod uwagę rzeczywistych danych z wejścia
                dbConnection.addReservation("Klient", "2023-01-01 19:00", 2);
                return new Response(ResponseType.RESERVATION_SUCCESS, ResponseType.RESERVATION_SUCCESS.getMessage());
            }
            //Show list of rows in database reservation
            if (input.equalsIgnoreCase(CommandConstants.SHOW_RESERVATIONS)) {
                ResultSet rs = dbConnection.listReservations();
                StringBuilder sb = new StringBuilder(ResponseType.RESERVATION_LIST.getMessage() + " ");
                // TODO Logika wyświetlania rezerwacji
                // ...
                while (rs.next()) {
                    int reservationId = rs.getInt("id");
                    String customerName = rs.getString("customer_name");
                    String reservationTime = rs.getString("reservation_time");
                    int numberOfGuests = rs.getInt("number_of_guests");
                    String message = "id: " + reservationId + ", customer_name:" + customerName + ", reservation_time: " + reservationTime + ", number_of_guests: " + numberOfGuests + " ";
                    sb.append(message);
                }
                rs.close();
                return new Response(ResponseType.RESERVATION_LIST, sb.toString());
            }

            // Potwierdzenie i anulowanie rezerwacji
            if (awaitingConfirmation) {
                if (input.equalsIgnoreCase(CommandConstants.CONFIRM)) {
                    dbConnection.deleteReservation(pendingReservationId);
                    Response response = new Response(ResponseType.RESERVATION_DELETED, ResponseType.RESERVATION_DELETED.getMessage(pendingReservationId));
                    resetConfirmationState();
                    return response;
                } else if (input.equalsIgnoreCase(CommandConstants.DENY)) {
                    resetConfirmationState();
                    return new Response(ResponseType.CANCELLATION_CONFIRMED, ResponseType.CANCELLATION_CONFIRMED.getMessage());
                } else {
                    return new Response(ResponseType.ERROR, ResponseType.ERROR.getMessage("Proszę odpowiedzieć 'tak' lub 'nie' na potwierdzenie usunięcia rezerwacji."));
                }
            }

            //Delete certain reservation
            if (input.startsWith(CommandConstants.DELETE_RESERVATION)) {
                try {
                    // TODO: Implementacja usuwania rezerwacji - przeparsuj reservationId z odpowiedzi klienta
                    int reservationId;
                    input = input.replaceAll("\\D", "");
                    if (!input.isEmpty()) {
                        reservationId = Integer.parseInt(input);
                        pendingReservationId = reservationId;
                        awaitingConfirmation = true;
                        return new Response(ResponseType.CONFIRMATION_REQUEST, ResponseType.CONFIRMATION_REQUEST.getMessage(reservationId));
                    } else {
                        return new Response(ResponseType.ERROR, ResponseType.ERROR.getMessage("Brak liczby całkowitej w podanej wiadomości"));
                    }
                } catch (NumberFormatException e) {
                    return new Response(ResponseType.INVALID_RESERVATION_ID_FORMAT, ResponseType.INVALID_RESERVATION_ID_FORMAT.getMessage());
                }
            }

        } catch (SQLException e) {
            return new Response(ResponseType.ERROR, ResponseType.ERROR.getMessage(e.getMessage()));
        }

        // Domyślna odpowiedź na nieznane komendy
        return new Response(ResponseType.INVALID_COMMAND, ResponseType.INVALID_COMMAND.getMessage());
    }

    public void exit() {
        try {
            dbConnection.closeConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    // Pomocnicza metoda do resetowania stanu potwierdzenia
    private void resetConfirmationState() {
        awaitingConfirmation = false;
        pendingReservationId = -1;
    }
}
