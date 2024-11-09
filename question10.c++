#include <iostream>
#include <cstring>
using namespace std;

// Structure to store contact information
struct Contact {
    char name[50];
    char mobile[15];
};

// Node class to represent each element in the linked list
class ContactNode {
public:
    Contact contact;
    ContactNode* next;

    // Constructor to initialize node
    ContactNode(const char* name, const char* mobile) {
        strcpy(this->contact.name, name);
        strcpy(this->contact.mobile, mobile);
        this->next = nullptr;
    }
};

// LinkedList class to implement the operations
class ContactList {
private:
    ContactNode* head;

public:
    // Constructor to initialize the head
    ContactList() {
        head = nullptr;
    }

    // Get the length of the linked list
    int getLength() {
        int length = 0;
        ContactNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // Add a node at the beginning of the linked list
    void addAtBeg(const char* name, const char* mobile) {
        ContactNode* newNode = new ContactNode(name, mobile);
        newNode->next = head;
        head = newNode;
    }

    // Add a node at the end of the linked list
    void append(const char* name, const char* mobile) {
        ContactNode* newNode = new ContactNode(name, mobile);
        if (head == nullptr) {
            head = newNode;
        } else {
            ContactNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Add a node at a specific position in the linked list
    void addAtPOS(const char* name, const char* mobile, int pos) {
        if (pos <= 0) {
            cout << "Invalid position" << endl;
            return;
        }

        ContactNode* newNode = new ContactNode(name, mobile);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            ContactNode* current = head;
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
        ContactNode* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->contact.name << ", Mobile: " << current->contact.mobile << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Display detailed information about the linked list
    void displayMORE() {
        ContactNode* current = head;
        while (current != nullptr) {
            cout << "Address: " << current << " | Name: " << current->contact.name << " | Mobile: " << current->contact.mobile << " | Next: " << current->next << endl;
            current = current->next;
        }
    }

    // Remove the first node of the linked list
    void removeFirst() {
        if (head != nullptr) {
            ContactNode* temp = head;
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
            ContactNode* current = head;
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
            ContactNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ContactNode* current = head;
            for (int i = 1; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current == nullptr || current->next == nullptr) {
                cout << "Position out of bounds" << endl;
            } else {
                ContactNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }
};

int main() {
    ContactList list;

    // Test operations
    list.addAtBeg("Alice", "1234567890");
    list.append("Bob", "0987654321");
    list.addAtPOS("Charlie", "1112223333", 2);
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
