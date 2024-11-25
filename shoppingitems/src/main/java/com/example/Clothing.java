package com.example;

public class Clothing extends ShoppingItems {
    private String size;
    private String color;

    public Clothing(String name, double price, int quantity, String size, String color) {
        super(name, price, quantity);
        this.size = size;
        this.color = color;
    }

    // Getter for size
    public String getSize() {
        return size;
    }

    // Setter for size
    public void setSize(String size) {
        this.size = size;
    }

    // Getter for color
    public String getColor() {
        return color;
    }

    // Setter for color
    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public void getDetails() {
        System.out.println("Item: " + name + ", Price: €" + price + ", Quantity: " + quantity + ", Size: " + size + ", Color: " + color);
    }
}
