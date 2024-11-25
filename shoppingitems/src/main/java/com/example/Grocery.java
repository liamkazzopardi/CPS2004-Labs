package com.example;

public class Grocery extends ShoppingItems {
    private String expirationDate;

    public Grocery(String name, double price, int quantity, String expirationDate) {
        super(name, price, quantity);
        this.expirationDate = expirationDate;
    }

    // Getter for expirationDate
    public String getExpirationDate() {
        return expirationDate;
    }

    // Setter for expirationDate
    public void setExpirationDate(String expirationDate) {
        this.expirationDate = expirationDate;
    }

    @Override
    public void getDetails() {
        System.out.println("Item: " + getName() + ", Price: €" + getPrice() + ", Quantity: " + getQuantity() +
                           ", Expiration Date: " + expirationDate);
    }
}
