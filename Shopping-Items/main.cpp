#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class shoppingItems {
protected:
    string name;
    float price;
    int quantity;

public:
    shoppingItems(string name, float price, int quantity) : name(name), price(price), quantity(quantity) {}

    virtual ~shoppingItems() {}

    virtual void getDetails() {
        cout << "Item: " << name << ", Price: €" << price << ", Quantity: " << quantity;
    }

    virtual double getTotalPrice() {
        return price * quantity;
    }

    virtual void persist(ofstream &out) const = 0; 

    static shoppingItems* restore(ifstream &in);
};

class Grocery : public shoppingItems {
    string expirationDate;

public:
    Grocery(string name, double price, int quantity, string expirationDate)
        : shoppingItems(name, price, quantity), expirationDate(expirationDate) {}

    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", Expiration Date: " << expirationDate << endl;
    }

    void persist(ofstream &out) const override {
        out << "Grocery " << name << " " << price << " " << quantity << " " << expirationDate << endl;
    }

    static Grocery* restore(ifstream &in) {
        string name, expirationDate;
        double price;
        int quantity;
        in >> name >> price >> quantity >> expirationDate;
        return new Grocery(name, price, quantity, expirationDate);
    }
};

class Electronics : public shoppingItems {
    string warrantyPeriod;

public:
    Electronics(string name, double price, int quantity, string warrantyPeriod)
        : shoppingItems(name, price, quantity), warrantyPeriod(warrantyPeriod) {}

    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", Warranty Period: " << warrantyPeriod << endl;
    }

    void persist(ofstream &out) const override {
        out << "Electronics " << name << " " << price << " " << quantity << " " << warrantyPeriod << endl;
    }

    static Electronics* restore(ifstream &in) {
        string name, warrantyPeriod;
        double price;
        int quantity;
        in >> name >> price >> quantity >> warrantyPeriod;
        return new Electronics(name, price, quantity, warrantyPeriod);
    }
};

class Books : public shoppingItems {
    string ISBN;

public:
    Books(string name, double price, int quantity, string ISBN)
        : shoppingItems(name, price, quantity), ISBN(ISBN) {}

    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", ISBN: " << ISBN << endl;
    }

    void persist(ofstream &out) const override {
        out << "Books " << name << " " << price << " " << quantity << " " << ISBN << endl;
    }

    static Books* restore(ifstream &in) {
        string name, ISBN;
        double price;
        int quantity;
        in >> name >> price >> quantity >> ISBN;
        return new Books(name, price, quantity, ISBN);
    }
};

class Clothing : public shoppingItems {
    string size;
    string color;

public:
    Clothing(string name, double price, int quantity, string size, string color)
        : shoppingItems(name, price, quantity), size(size), color(color) {}

    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", Size: " << size << ", Color: " << color << endl;
    }

    void persist(ofstream &out) const override {
        out << "Clothing " << name << " " << price << " " << quantity << " " << size << " " << color << endl;
    }

    static Clothing* restore(ifstream &in) {
        string name, size, color;
        double price;
        int quantity;
        in >> name >> price >> quantity >> size >> color;
        return new Clothing(name, price, quantity, size, color);
    }
};

class ToyItems : public shoppingItems {
    int suitableAge;

public:
    ToyItems(string name, double price, int quantity, int suitableAge)
        : shoppingItems(name, price, quantity), suitableAge(suitableAge) {}

    void getDetails() override {
        shoppingItems::getDetails();
        cout << ", Suitable Age: " << suitableAge << endl;
    }

    void persist(ofstream &out) const override {
        out << "ToyItems " << name << " " << price << " " << quantity << " " << suitableAge << endl;
    }

    static ToyItems* restore(ifstream &in) {
        string name;
        double price;
        int quantity, suitableAge;
        in >> name >> price >> quantity >> suitableAge;
        return new ToyItems(name, price, quantity, suitableAge);
    }
};

shoppingItems* shoppingItems::restore(ifstream &in) {
    string type;
    in >> type;

    if (type == "Grocery") return Grocery::restore(in);
    if (type == "Electronics") return Electronics::restore(in);
    if (type == "Books") return Books::restore(in);
    if (type == "Clothing") return Clothing::restore(in);
    if (type == "ToyItems") return ToyItems::restore(in);

    return nullptr; //null pointer returned
}

void saveToFile(const vector<shoppingItems*> &items, const string &filename) {
    ofstream out(filename);
    for (const auto &item : items) {
        item->persist(out);
    }
}

vector<shoppingItems*> loadFromFile(const string &filename) {
    ifstream in(filename);
    vector<shoppingItems*> items;
    while (in) {
        shoppingItems* item = shoppingItems::restore(in);
        if (item) items.push_back(item);
    }
    return items;
}

int main() {
    vector<shoppingItems*> items;
    int option;

    do {
        cout << "\n1. Add item\n2. Display all items\n3. Save to file\n4. Load from file\n5. Exit\n";
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
                cout << "Enter warranty period (years): ";
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
                cout << "Enter suitable age (in years): ";
                cin >> suitableAge;
                items.push_back(new ToyItems(name, price, quantity, suitableAge));
            } 
            else {
                cout << "Invalid item type! Please try again." << endl;
            }
        
        } else if (option == 2) {
            for (const auto &item : items) item->getDetails();
        } else if (option == 3) {
            saveToFile(items, "shopping_list.txt");
            cout << "Items saved to file.\n";
        } else if (option == 4) {
            items = loadFromFile("shopping_list.txt");
            cout << "Items loaded from file.\n";
        }
    } while (option != 5);

    for (auto &item : items) delete item;
    return 0;
}
