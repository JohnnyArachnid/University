package org.chatbot.client;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class ChatClient {
    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;
    private BufferedReader userInputReader;

    public ChatClient(String address, int port) throws Exception {
        // Zainicjuj połączenie z serwerem chatu
        this.socket = new Socket(address, port);
        this.out = new PrintWriter(socket.getOutputStream(), true);
        this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.userInputReader = new BufferedReader(new InputStreamReader(System.in));
    }

    public void send(String message) {
        this.out.println(message);
    }

    public String receive() throws Exception {
        return in.readLine();
    }

    public void close() throws Exception {
        this.in.close();
        this.out.close();
        this.socket.close();
        this.userInputReader.close();
    }

    public static void main(String[] args) throws Exception {
        ChatClient client = new ChatClient("localhost", 1234);

        System.out.println("Connected to chatbot. Type your messages:");
        System.out.println(client.receive());
        // Zaimplementuj pętlę do komunikacji z serwerem
        // która wczytuje input z konsoli, przesyła do serwera i odbiera odpowiedź
        try {
            String userInput;
            while ((userInput = client.userInputReader.readLine()) != null) {
                client.send(userInput);
                System.out.println("Chatbot says: \n" + client.receive());
            }
        } finally {
            client.close();
        }
    }
}
