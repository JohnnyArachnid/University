package org.simplestore.model;

import java.util.*;

public class Inventory {
    // TODO: Remember of synchronization logic!
    // There is several methods to achieve this.
    private final Map<Integer, Product> products = new HashMap<>();

    public synchronized void addProduct(Product product) {
        products.put(product.getId(), product);
    }

    public Product getProduct(int productId) throws ProductNotFoundException {
        Product product = products.get(productId);
        if (product == null) {
            throw new ProductNotFoundException("Product with ID " + productId + " not found.");
        }
        return product;
    }

    public synchronized ArrayList<Product> listAllProducts() {
        ArrayList<Product> arraylist = new ArrayList<>();
        for (Product product : products.values()) {
            arraylist.add(product);
        }
        return arraylist;
    }

    public synchronized void removeProduct(int productId) throws ProductNotFoundException {
        if (products.remove(productId) == null)
            throw new ProductNotFoundException("Product with ID " + productId + " not found.");
    }

    public void printProduct(int productId) throws ProductNotFoundException {
        if (products.get(productId) == null)
            throw new ProductNotFoundException("Product with ID " + productId + " not found.");
        System.out.print(productId + " | " + products.get(productId).toString());
    }

    public void printAllProducts() {
        if (products.isEmpty()) {
            System.out.println("None of products to print.");
            return;
        }
        for (int productId : products.keySet()) {
            System.out.println(productId + " | " + products.get(productId).toString());
        }
    }

    // See file: src/test/java/org/simplestore/model/InventoryTest.java
    // TODO: Implement a method to list all products
    // TODO: Implement a method to remove a product by id
}
