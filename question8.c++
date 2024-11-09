#include <iostream>
#include <cstring>
using namespace std;

// Node class to represent each element in the linked list
class FriendNode {
public:
    char name[50];
    FriendNode* next;

    // Constructor to initialize node
    FriendNode(const char* name) {
        strcpy(this->name, name);
        this->next = nullptr;
    }
};

// LinkedList class to implement the operations
class FriendList {
private:
    FriendNode* head;

public:
    // Constructor to initialize the head
    FriendList() {
        head = nullptr;
    }

    // Get the length of the linked list
    int getLength() {
        int length = 0;
        FriendNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // Add a node at the beginning of the linked list
    void addAtBeg(const char* name) {
        FriendNode* newNode = new FriendNode(name);
        newNode->next = head;
        head = newNode;
    }

    // Add a node at the end of the linked list
    void append(const char* name) {
        FriendNode* newNode = new FriendNode(name);
        if (head == nullptr) {
            head = newNode;
        } else {
            FriendNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Add a node at a specific position in the linked list
    void addAtPOS(const char* name, int pos) {
        if (pos <= 0) {
            cout << "Invalid position" << endl;
            return;
        }

        FriendNode* newNode = new FriendNode(name);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            FriendNode* current = head;
            for (int i = 1; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Position out of bounds" << endl;
            } else {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    // Display the linked list
    void display() {
        FriendNode* current = head;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Display detailed information about the linked list
    void displayMORE() {
        FriendNode* current = head;
        while (current != nullptr) {
            cout << "Address: " << current << " | Name: " << current->name << " | Next: " << current->next << endl;
            current = current->next;
        }
    }

    // Remove the first node of the linked list
    void removeFirst() {
        if (head != nullptr) {
            FriendNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "List is empty" << endl;
        }
    }

    // Remove the last node of the linked list
    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            FriendNode* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    // Remove a node at a specific position in the linked list
    void removePOS(int pos) {
        if (pos <= 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1 && head != nullptr) {
            FriendNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            FriendNode* current = head;
            for (int i = 1; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current == nullptr || current->next == nullptr) {
                cout << "Position out of bounds" << endl;
            } else {
                FriendNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }
};

int main() {
    FriendList list;

    // Test operations
    list.addAtBeg("Alice");
    list.append("Bob");
    list.addAtPOS("Charlie", 2);
    list.display();
    list.displayMORE();

    list.removeFirst();
    list.display();

    list.removeLast();
    list.display();

    list.removePOS(1);
    list.display();

    cout << "Length of the list: " << list.getLength() << endl;

    return 0;
}
