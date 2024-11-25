package com.example;

public class Electronics extends ShoppingItems {
    private String warrantyPeriod;

    public Electronics(String name, double price, int quantity, String warrantyPeriod) {
        super(name, price, quantity);
        this.warrantyPeriod = warrantyPeriod;
    }

    // Getter for warrantyPeriod
    public String getWarrantyPeriod() {
        return warrantyPeriod;
    }

    // Setter for warrantyPeriod
    public void setWarrantyPeriod(String warrantyPeriod) {
        this.warrantyPeriod = warrantyPeriod;
    }

    @Override
    public void getDetails() {
        System.out.println("Item: " + name + ", Price: €" + price + ", Quantity: " + quantity + ", Warranty Period: " + warrantyPeriod);
    }
}
