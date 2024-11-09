#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class to implement the operations
class OddEvenList {
private:
    Node* head;
    Node* oddTail;
    Node* evenTail;

public:
    // Constructor to initialize the head
    OddEvenList() {
        head = nullptr;
        oddTail = nullptr;
        evenTail = nullptr;
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
    void addAtBeg(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            if (data % 2 != 0) {
                oddTail = newNode;
            } else {
                evenTail = newNode;
            }
        } else {
            newNode->next = head;
            head = newNode;
            if (data % 2 != 0) {
                if (oddTail == nullptr) {
                    oddTail = newNode;
                }
            } else {
                if (evenTail == nullptr) {
                    evenTail = newNode;
                }
            }
        }
    }

    // Add a node at the end of the linked list
    void append(int data) {
        Node* newNode = new Node(data);
        if (data % 2 != 0) { // Odd number
            if (oddTail == nullptr) { // First odd element
                addAtBeg(data);
            } else {
                newNode->next = oddTail->next;
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else { // Even number
            if (evenTail == nullptr) { // First even element
                if (oddTail == nullptr) { // No odd elements yet
                    addAtBeg(data);
                } else {
                    evenTail = newNode;
                    oddTail->next = evenTail;
                }
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
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
            oddTail = nullptr;
            evenTail = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            if (current->data % 2 != 0) {
                evenTail = nullptr;
                oddTail = current;
            } else {
                evenTail = current;
            }
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
    OddEvenList list;

    // Test operations
    list.addAtBeg(5);
    list.append(2);
    list.addAtBeg(3);
    list.append(4);
    list.addAtBeg(1);
    list.display();
    list.displayMORE();

    list.removeFirst();
    list.display();

    list.removeLast();
    list.display();

    list.removePOS(2);
    list.display();

    cout << "Length of the list: " << list.getLength() << endl;

    return 0;
}
