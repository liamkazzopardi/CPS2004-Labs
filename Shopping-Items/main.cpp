#include <iostream>
#include <vector>
using namespace std;
class shoppingItems{
private:
    string name;
    float price;
    int quantity;

public:

    shoppingItems(string name,float price,int quantity) : name(name), price(price), quantity(quantity) {}

    
    void setPrice(float price){
        this->price=price;
    }

    float getPrice(){
        return price;
    }

    void setName(const string name){
        this->name=name;
    }
    
    string getName(){
        return name;
    }

    void setQuantity(int quantity){
        this->quantity=quantity;
    }

    int getQuantity(){
        return quantity;
    }

    virtual void getDetails(){
        cout << "Item: " << name << ", Price: €" << price << ", Quantity: " << quantity;
    }

    virtual double getTotalPrice(){
        return price * quantity;
    }
};

class Grocery: public shoppingItems{
    string expirationDate;

public:
    Grocery(string name, double price, int quantity, string expirationDate)
        : shoppingItems(name, price, quantity), expirationDate(expirationDate) {}


    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", Expiration Date: " << expirationDate << endl;
    }
};

class Electronics: public shoppingItems{
    string warrantyPeriod;
public:
    Electronics(string name, double price, int quantity, string expirationDate)
        : shoppingItems(name, price, quantity), warrantyPeriod(expirationDate) {}

    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", Warranty Period: " << warrantyPeriod << endl;
    }
};

class Books: public shoppingItems{
    string ISBN;
public:
    Books(string name, double price, int quantity, string ISBN)
        : shoppingItems(name,price,quantity), ISBN(ISBN){}

    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", ISBN: " << ISBN << endl;
    }
};

class Clothing : public shoppingItems {
    string size;
    string color;

public:
    Clothing(string name, double price, int quantity, string size, string color)
        : shoppingItems(name, price, quantity), size(size), color(color) {}

    // Override to display both common and specialized info
    void getDetails() override {
        shoppingItems::getDetails();  // Display common info
        cout << "Size: " << size << "\n"
             << "Color: " << color << "\n";
    }
};

class ToyItems : public shoppingItems{
    int suitableAge;
public:
    ToyItems(string name, double price, int quantity, int suitableAge)
        : shoppingItems(name,price,quantity), suitableAge(suitableAge){}
    void getDetails() override {
            shoppingItems::getDetails();  
            cout << "Suitable Age: " << suitableAge << endl;
    }
};

int main(){
   vector<shoppingItems*> items; 
 int option;
    do {
        cout << "\n1. Add item\n2. Display all items\n3. Exit\n";
        cin >> option;

        if (option == 1) {
            int itemType;
            string name;
            double price;
            int quantity;

            cout << "Choose item type:\n1. Grocery\n2. Electronics\n3. Books\n4. Clothing\n5. Toy\n";
            cin >> itemType;

            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> quantity;

           
            if (itemType == 1) {
                string expirationDate;
                cout << "Enter expiration date: ";
                cin >> expirationDate;
                items.push_back(new Grocery(name, price, quantity, expirationDate));
            } 
            else if (itemType == 2) {
                string warrantyPeriod;
                cout << "Enter warranty period: ";
                cin >> warrantyPeriod;
                items.push_back(new Electronics(name, price, quantity, warrantyPeriod));
            } 
            else if (itemType == 3) {
                string ISBN;
                cout << "Enter ISBN: ";
                cin >> ISBN;
                items.push_back(new Books(name, price, quantity, ISBN));
            } 
            else if (itemType == 4) {
                string size, color;
                cout << "Enter size: ";
                cin >> size;
                cout << "Enter color: ";
                cin >> color;
                items.push_back(new Clothing(name, price, quantity, size, color));
            } 
            else if (itemType == 5) {
                int suitableAge;
                cout << "Enter suitable age: ";
                cin >> suitableAge;
                items.push_back(new ToyItems(name, price, quantity, suitableAge));
            } 
            else {
                cout << "Invalid item type! Please try again." << endl;
            }
        }
        else if (option == 2) {
            cout << "\nItems in the collection:\n";
            for (const auto& item : items) {
                item->getDetails();
                cout << "-------------------\n";
            }
        }
        else if (option == 3) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid option! Please try again." << endl;
        }
    } while (option != 3);

    // Clean up dynamically allocated memory
    for (auto& item : items) {
        delete item;
    }

    return 0;
}