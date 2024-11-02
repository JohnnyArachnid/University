package org.simplestore.service;

import org.simplestore.model.Inventory;
import org.simplestore.model.Product;
import org.simplestore.model.ProductNotFoundException;

import java.util.HashMap;
import java.util.Map;

public class ShoppingCart {
    // TODO Finish implementation. eg. add needed constructor

    // Remember of synchronization logic!
    // It could be achieved in many ways.
    private final Inventory inventory;
    private final Map<Integer, Integer> cartItems = new HashMap<>();

    public ShoppingCart(Inventory inventory) {
        this.inventory = inventory;
    }

    public synchronized void addItem(int productId, int quantity) throws ProductNotFoundException {
        if (productId <= 0) {
            throw new ProductNotFoundException("ID cannot be less than 0");
        }
        cartItems.merge(productId, quantity, Integer::sum);  // Equivalent of lambda (a, b) -> Integer.sum(a, b)
    }

    public int getItemQuantity(int productId) {
        if (cartItems.get(productId) == null) {
            return 0;
        }
        return cartItems.get(productId);
    }

    public synchronized void removeItem(int productId, int quantity) throws ProductNotFoundException {
        if (cartItems.get(productId) == null) {
            throw new ProductNotFoundException("Product with this ID doesn't exist");
        }
        if (quantity >= cartItems.get(productId)) {
            cartItems.remove(productId);
        } else {
            cartItems.replace(productId, cartItems.get(productId) - quantity);
        }
    }

    public synchronized void clearCart() {
        cartItems.clear();
    }

    public double calculateTotalCost() throws ProductNotFoundException {
        double totalCost = 0;
        for (int productId : cartItems.keySet()) {
            try {
                inventory.getProduct(productId);
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                totalCost += (cartItems.get(productId) * inventory.getProduct(productId).getPrice());
            }
        }
        return totalCost;
    }

    public void printAllOProductsInShoppingCart() {
        if (cartItems.isEmpty()) {
            System.out.println("Empty shopping card!");
            return;
        }
        try {
            for (int productId : cartItems.keySet()) {
                inventory.printProduct(productId);
                System.out.println(" Quantity: " + cartItems.get(productId));
            }
        } catch (ProductNotFoundException e) {
            e.printStackTrace();
        }
    }

    // See file: src/test/java/org/simplestore/service/ShoppingCartTest.java
    // TODO: Implement a method to remove a product from the cart
    // TODO: Implement a method to calculate the total price of the cart
    // TODO: Implement a method to clear the cart

}
