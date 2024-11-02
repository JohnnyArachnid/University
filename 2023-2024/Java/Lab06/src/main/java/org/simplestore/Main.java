package org.simplestore;

import org.simplestore.model.Inventory;
import org.simplestore.model.Product;
import org.simplestore.model.ProductNotFoundException;
import org.simplestore.service.ShoppingCart;
import org.simplestore.util.InventoryLoader;

public class Main {
    public static void main(String[] args) throws ProductNotFoundException{
        Inventory inventory = new Inventory();
        InventoryLoader.loadInventory("src/main/resources/inventory.txt", inventory);  // TODO: Change to proper path (example file is in project resources)
        ShoppingCart shoppingCart = new ShoppingCart(inventory);
        try {
            shoppingCart.addItem(1, 2);
            shoppingCart.addItem(2, 4);
            shoppingCart.addItem(3, 1);
            shoppingCart.printAllOProductsInShoppingCart();
            shoppingCart.removeItem(2, 5);
            shoppingCart.removeItem(1, 1);
            shoppingCart.printAllOProductsInShoppingCart();
            shoppingCart.clearCart();
            shoppingCart.printAllOProductsInShoppingCart();
            inventory.printAllProducts();
            inventory.removeProduct(1);
            inventory.removeProduct(2);
            inventory.removeProduct(3);
            inventory.addProduct(new Product(1,"Book",12.5));
            inventory.printAllProducts();
        } catch (ProductNotFoundException e){
            e.printStackTrace();
        }

        // Implement example usage of application components

        // TODO: Create shopping carts, add products,
        //  clear cart, handle exceptions, etc.

        // TODO: Add product to inventory, list all products
        // TODO: Remove product from inventory, list all products
    }
}

