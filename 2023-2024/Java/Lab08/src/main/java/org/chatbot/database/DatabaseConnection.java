package org.chatbot.database;

import java.sql.*;

public class DatabaseConnection implements IDatabaseConnection {
    private Connection connection;

    // TODO: Implementacja połączenia z bazą danych
    public DatabaseConnection(String url, String user, String password) throws SQLException {
        connection = DriverManager.getConnection(url, user, password);
    }

    @Override
    public void addReservation(String customerName, String reservationTime, int numberOfGuests) {
        // TODO: Implementacja metody dodającej rezerwację do bazy danych
        //  Użyj try with resource lub zamknij statement
        String sql = "INSERT INTO reservations (customer_name, reservation_time, number_of_guests) VALUES ('" + customerName + "', '" + reservationTime + "', '" + numberOfGuests + "')";
        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sql); }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void deleteReservation(int reservationId) {
        // TODO: Implementacja metody usuwającej rezerwację z bazy danych
        //  Użyj try with resource lub zamknij statement
        String sql = "DELETE FROM reservations WHERE id = '" + reservationId + "'";
        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sql); }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public ResultSet listReservations() throws SQLException {
        // TODO: Implementacja metody zwracającej listę rezerwacji z bazy danych
        //  Nie zamykaj w tym miejscu ResultSet.
        String sql = "SELECT * FROM reservations";
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        return resultSet;
        // ...
    }

    // TODO: Metoda do zamknięcia połączenia z bazą danych
    public void closeConnection() {
        try {
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}