package com.example;

class ToyItems extends ShoppingItems {
    private int suitableAge;

    public ToyItems(String name, double price, int quantity, int suitableAge) {
        super(name, price, quantity);
        this.suitableAge = suitableAge;
    }

    // Getter for suitableAge
    public int getSuitableAge() {
        return suitableAge;
    }

    // Setter for suitableAge
    public void setSuitableAge(int suitableAge) {
        this.suitableAge = suitableAge;
    }

    @Override
    public void getDetails() {
        System.out.println("Item: " + name + ", Price: €" + price + ", Quantity: " + quantity + ", Suitable Age: " + suitableAge);
    }
}
