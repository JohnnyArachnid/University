package org.simplestore.service;

import org.junit.jupiter.api.Test;
import org.simplestore.model.Inventory;
import org.simplestore.model.Product;
import org.simplestore.model.ProductNotFoundException;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

class MyThread1 extends Thread {
    public void run(ShoppingCart shoppingCart) {
        try {
            shoppingCart.addItem(1, 10);
            sleep(1000);
            shoppingCart.removeItem(1, 5);
        } catch (InterruptedException | ProductNotFoundException e) {
            e.printStackTrace();
        }
    }
}

class MyThread2 extends Thread {
    public void run(ShoppingCart shoppingCart) {
        try {
            shoppingCart.addItem(1, 10);
            sleep(1000);
        } catch (InterruptedException | ProductNotFoundException e) {
            e.printStackTrace();
        }
    }
}

public class ShoppingCartConcurrencyTest {
    private final Inventory inventory = new Inventory();

    @Test
    void addAndRemoveItemsConcurrently() throws InterruptedException, ProductNotFoundException {
        ShoppingCart shoppingCart = new ShoppingCart(inventory);
        inventory.addProduct(new Product(1, "Test Product", 10.0));
        ArrayList<MyThread1> arraylist = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            arraylist.add(new MyThread1());
        }
        for (MyThread1 thread : arraylist) {
            thread.run(shoppingCart);
        }
        for (MyThread1 thread : arraylist) {
            thread.join();
        }

        // Prepare tests with 10 threads. Next:

        // TODO Add 100 items concurrently

        // TODO Remove 50 items concurrently

        // TODO Await for threads termination, eg. join

        // Check if the final quantity is as expected
        assertEquals(50, shoppingCart.getItemQuantity(1));
    }

    @Test
    void calculateTotalCostConcurrently() throws InterruptedException, ProductNotFoundException {
        ShoppingCart shoppingCart = new ShoppingCart(inventory);
        inventory.addProduct(new Product(1, "Test Product", 10.0));

        // TODO Add 100 items concurrently
        // TODO Await for threads termination, eg. join

        ArrayList<MyThread2> arraylist = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            arraylist.add(new MyThread2());
        }
        for (MyThread2 thread : arraylist) {
            thread.run(shoppingCart);
        }
        for (MyThread2 thread : arraylist) {
            thread.join();
        }

        // Check if the total cost calculation is correct
        assertEquals(1000.0, shoppingCart.calculateTotalCost());
    }

    // Note for presenter: Discuss the importance of concurrency testing in a multi-threaded environment.
}
