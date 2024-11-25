package com.example;

public abstract class ShoppingItems {
    protected String name;
    protected double price;
    protected int quantity;

    public ShoppingItems(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    // Getters
    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setQuantity(int quantity) {
        if (quantity < 0) {
            throw new IllegalArgumentException("Quantity cannot be negative.");
        }
        this.quantity = quantity;
    }

    // Abstract method for displaying details (must be implemented by subclasses)
    public abstract void getDetails();

    // Method to calculate total price
    public double getTotalPrice() {
        return price * quantity;
    }
}
