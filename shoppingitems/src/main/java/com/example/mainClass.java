package com.example;

import java.util.ArrayList;
import java.util.Scanner;



public class mainClass {
    public static void main(String[] args) {
        ArrayList<ShoppingItems> items = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int option;

        do {
            System.out.println("\n1. Add item\n2. Display all items\n3. Exit");
            option = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            if (option == 1) {
                System.out.println("Choose item type:\n1. Grocery\n2. Electronics\n3. Books\n4. Clothing\n5. Toy");
                int itemType = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                System.out.print("Enter item name: ");
                String name = scanner.nextLine();

                System.out.print("Enter price: ");
                double price = scanner.nextDouble();

                System.out.print("Enter quantity: ");
                int quantity = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                switch (itemType) {
                    case 1: // Grocery
                        System.out.print("Enter expiration date: ");
                        String expirationDate = scanner.nextLine();
                        items.add(new Grocery(name, price, quantity, expirationDate));
                        break;

                    case 2: // Electronics
                        System.out.print("Enter warranty period (years): ");
                        String warrantyPeriod = scanner.nextLine();
                        items.add(new Electronics(name, price, quantity, warrantyPeriod));
                        break;

                    case 3: // Books
                        System.out.print("Enter ISBN: ");
                        String ISBN = scanner.nextLine();
                        items.add(new Books(name, price, quantity, ISBN));
                        break;

                    case 4: // Clothing
                        System.out.print("Enter size: ");
                        String size = scanner.nextLine();
                        System.out.print("Enter color: ");
                        String color = scanner.nextLine();
                        items.add(new Clothing(name, price, quantity, size, color));
                        break;

                    case 5: // Toy
                        System.out.print("Enter suitable age (in years): ");
                        int suitableAge = scanner.nextInt();
                        items.add(new ToyItems(name, price, quantity, suitableAge));
                        break;

                    default:
                        System.out.println("Invalid item type! Please try again.");
                }
            } else if (option == 2) {
                // Display all items
                for (ShoppingItems item : items) {
                    item.getDetails();
                }
            }
        } while (option != 3);

        System.out.println("Goodbye!");
        scanner.close();
    }
}
