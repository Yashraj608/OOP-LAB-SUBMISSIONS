//REAL WORLD USE CASE -INVENTORY MANAGEMENT SYSTEM//
#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    int price;
};

void addProduct(Product *&products, int &count) {
    Product *newProducts = new Product[count + 1];
    for (int i = 0; i < count; i++) {
        newProducts[i] = products[i];
    }
    cout << "Enter product id: ";
    cin >> newProducts[count].productID;
    cin.ignore();
    cout << "Enter product name: ";
    getline(cin, newProducts[count].name);
    cout << "Enter quantity:" << endl;
    cin >> newProducts[count].quantity;
    cout << "Enter price: ";
    cin >> newProducts[count].price;
    delete[] products;
    products = newProducts;
    count++;
    cout << "Product added" << endl;
}

void removeProduct(Product *&products, int &count, int id) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (products[i].productID == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Product not found" << endl;
        return;
    }
    Product *newProducts = new Product[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newProducts[j++] = products[i];
        }
    }
    delete[] products;
    products = newProducts;
    count--;
    cout << "Product removed" << endl;
}

void updateProduct(Product *products, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (products[i].productID == id) {
            cout << "Enter new quantity: ";
            cin >> products[i].quantity;
            cout << "Enter new price: ";
            cin >> products[i].price;
            cout << "Product updated" << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

void showProducts(Product *products, int count) {
    if (count == 0) {
        cout << "No products in inventory" << endl;
        return;
    }
    cout << "Inventory:\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << products[i].productID
             << ", Name: " << products[i].name
             << ", Quantity: " << products[i].quantity
             << ", Price: " << products[i].price << endl;
    }
}

void totalinventoryvalue(Product *products, int count) {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += products[i].price * products[i].quantity;
    }
    cout << "Total inventory value: " << total << endl;
}

int main() {
    Product *products = nullptr;
    int count = 0;
    int choice, id;
    while (true) {
        cout << "Enter your choice" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Remove product" << endl;
        cout << "3. Update product" << endl;
        cout << "4. Display product" << endl;
        cout << "5. Total Inventory Value" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                addProduct(products, count);
                break;
            case 2:
                cout << "Enter Product ID to remove: ";
                cin >> id;
                removeProduct(products, count, id);
                break;
            case 3:
                cout << "Enter Product ID to update: ";
                cin >> id;
                updateProduct(products, count, id);
                break;
            case 4:
                showProducts(products, count);
                break;
            case 5:
                totalinventoryvalue(products, count);
                break;
            case 6:
                delete[] products;
                cout << "24k-0737 exiting the program." << endl;
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}