#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Product {
    int productID;
    string name;
    string category;
};

struct Order {
    int orderID;
    int ProductID;
    int quantity;
    string customerID;
   
};

// Function to print products
void printProducts(const vector<Product>& products) {
    cout << "Products:\n";
    for (const auto& product : products) {
        cout << "Product ID: " << product.productID
            << ", Name: " << product.name
            << ", Category: " << product.category << "\n";
    }
    cout << endl;
}

// Function to print recent customers
void printRecentCustomers(const deque<string>& recentCustomers) {
    cout << "Recent Customers:\n";
    for (const auto& customer : recentCustomers) {
        cout << customer << " ";
    }
    cout << endl << endl;
}

// Function to print order history
void printOrderHistory(const list<Order>& orderHistory) {
    cout << "Order History:\n";
    for (const auto& order : orderHistory) {
        cout << "Order ID: " << order.orderID
            << ", Product ID: " << order.ProductID
            << ", Quantity: " << order.quantity
            << ", Customer ID: " << order.customerID;
    }
    cout << endl;
}

// Function to print categories
void printCategories(const set<string>& categories) {
    cout << "Product Categories:\n";
    for (const auto& category : categories) {
        cout << category << " ";
    }
    cout << endl << endl;
}

// Function to print product stock
void printProductStock(const map<int, int>& productStock) {
    cout << "Product Stock:\n";
    for (const auto& stock : productStock) {
        cout << "Product ID: " << stock.first << ", Stock: " << stock.second << "\n";
    }
    cout << endl;
}

// Function to print customer orders
void printCustomerOrders(const multimap<string, Order>& customerOrders) {
    cout << "Customer Orders:\n";
    for (const auto& pair : customerOrders) {
        const auto& order = pair.second;
        cout << "Customer ID: " << pair.first
            << ", Order ID: " << order.orderID
            << ", Product ID: " << order.ProductID
            << ", Quantity: " << order.quantity;
    }
    cout << endl;
}

// Function to print customer data
void printCustomerData(const unordered_map<string, string>& customerData) {
    cout << "Customer Data:\n";
    for (const auto& customer : customerData) {
        cout << "Customer ID: " << customer.first
            << ", Name: " << customer.second << "\n";
    }
    cout << endl;
}

// Function to print unique product IDs
void printUniqueProductIDs(const unordered_set<int>& uniqueProductIDs) {
    cout << "Unique Product IDs:\n";
    for (const auto& id : uniqueProductIDs) {
        cout << id << " ";
    }
    cout << endl << endl;
}

int main() {
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "SmartPhone", "Electronics"},
        {103, "Coffe Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk lamp", "Home"},
    };

    deque<string> recentCustomers = { "C001", "C002", "C003" };
    recentCustomers.push_back("C004");
    recentCustomers.push_front("C005");

    list<Order> orderHistory;
    orderHistory.push_back({ 1, 101, 1, "C001"  });
    orderHistory.push_back({ 2, 102, 2, "C002"  });
    orderHistory.push_back({ 3, 103, 1, "C003"  });

    set<string> categories;
    for (const auto& product : products) {
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 5},
        {105, 7},
    };

    multimap<string, Order> customerOrders;
    for (const auto& order : orderHistory) {
        customerOrders.insert({ order.customerID, order });
    }

    unordered_map<string, string> customerData = {
        {"C001", "Alice"},
        {"C002", "Harsh"},
        {"C003", "Vidya"},
        {"C004", "max"},
        {"C005", "harry"},
    };

    unordered_set<int> uniqueProductIDs;
    for (const auto& product : products) {
        uniqueProductIDs.insert(product.productID);
    }

    // Print all data
    printProducts(products);
    printRecentCustomers(recentCustomers);
    printOrderHistory(orderHistory);
    printCategories(categories);
    printProductStock(productStock);
    printCustomerOrders(customerOrders);
    printCustomerData(customerData);
    printUniqueProductIDs(uniqueProductIDs);

    return 0;
}
