#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    char data;
    Node* next;

    // Constructor to initialize node
    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class to implement the operations
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize the head
    LinkedList() {
        head = nullptr;
    }

    // Get the length of the linked list
    int getLength() {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // Add a node at the beginning of the linked list
    void addAtBeg(char data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Add a node at the end of the linked list
    void append(char data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Add a node at a specific position in the linked list
    void addAtPOS(char data, int pos) {
        if (pos <= 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(data);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
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
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Display detailed information about the linked list
    void displayMORE() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Address: " << current << " | Value: " << current->data << " | Next: " << current->next << endl;
            current = current->next;
        }
    }

    // Remove the first node of the linked list
    void removeFirst() {
        if (head != nullptr) {
            Node* temp = head;
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
            Node* current = head;
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
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 1; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current == nullptr || current->next == nullptr) {
                cout << "Position out of bounds" << endl;
            } else {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }
};

int main() {
    LinkedList list;

    // Test operations
    list.addAtBeg('A');
    list.append('B');
    list.addAtPOS('C', 2);
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

      