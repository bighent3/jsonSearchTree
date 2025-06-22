#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store user data
struct User {
    string name;
    string age;
    string address;
    string phone;
};

// Node for Binary Search Tree
struct Node {
    User user;
    Node* left;
    Node* right;

    Node(User u) : user(u), left(nullptr), right(nullptr) {}
};

// Class to manage the Binary Search Tree
class UserBST {
private:
    Node* root;

    // Helper function to insert a node recursively
    Node* insert(Node* node, User user) {
        if (node == nullptr) {
            return new Node(user);
        }

        // Compare names to determine where to insert
        if (user.name < node->user.name) {
            node->left = insert(node->left, user);
        } else {
            node->right = insert(node->right, user);
        }

        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(Node* node, vector<User>& result) {
        if (node != nullptr) {
            inOrderTraversal(node->left, result);
            result.push_back(node->user); // visit current user
            inOrderTraversal(node->right, result);
        }
    }

public:
    UserBST() : root(nullptr) {}

    // Public insert function
    void insert(User user) {
        root = insert(root, user);
    }

    // Public function to return sorted users
    vector<User> getSortedUsers() {
        vector<User> result;
        inOrderTraversal(root, result);
        return result;
    }
};

// Function to collect user input
User collectUser() {
    User user;
    cout << "Enter your name: ";
    getline(cin, user.name);

    cout << "Enter your age: ";
    getline(cin, user.age);

    cout << "Enter your address: ";
    getline(cin, user.address);

    cout << "Enter your phone number: ";
    getline(cin, user.phone);

    return user;
}

// Function to display users
void displayUsers(const vector<User>& users) {
    cout << "\n--- Sorted Users by Name ---\n";
    for (const auto& user : users) {
        cout << "Name: " << user.name << "\n";
        cout << "Age: " << user.age << "\n";
        cout << "Address: " << user.address << "\n";
        cout << "Phone: " << user.phone << "\n";
        cout << "--------------------------\n";
    }
}

// Main program loop
int main() {
    UserBST userTree;
    string command;

    while (true) {
        cout << "\nType 'add' to add a user, 'show' to display users, or 'exit' to quit:\n";
        getline(cin, command);

        if (command == "add") {
            User newUser = collectUser();
            userTree.insert(newUser);
            cout << "User \"" << newUser.name << "\" added!\n";
        } else if (command == "show") {
            vector<User> users = userTree.getSortedUsers();
            displayUsers(users);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command. Try 'add', 'show', or 'exit'.\n";
        }
    }

    return 0;
}
