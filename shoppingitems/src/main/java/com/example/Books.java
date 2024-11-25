package com.example;

class Books extends ShoppingItems {
    private String ISBN;

    public Books(String name, double price, int quantity, String ISBN) {
        super(name, price, quantity);
        this.ISBN = ISBN;
    }

    // Getter for ISBN
    public String getISBN() {
        return ISBN;
    }

    // Setter for ISBN
    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    @Override
    public void getDetails() {
        System.out.println("Item: " + name + ", Price: €" + price + ", Quantity: " + quantity + ", ISBN: " + ISBN);
    }
}
