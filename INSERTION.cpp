#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Function to insert data at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert data at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert data at a specific location within the list
    void insertAtLocation(int value, int position) {
        if (position <= 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node at a specific location
    void deleteAtLocation(int position) {
        if (head == nullptr)
            return;
        Node* temp = head;
        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)
            return;
        Node* nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
    }

    // Function to display the contents of the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList myList;

    // Inserting elements at the beginning
    myList.insertAtBeginning(1);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(3);

    // Inserting elements at the end
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);

    // Inserting elements at specific locations
    myList.insertAtLocation(10, 2); // Insert 10 at index 2

    // Displaying the list
    cout << "List after insertion: ";
    myList.display();

    // Deleting element at specific location
    myList.deleteAtLocation(2); // Delete element at index 2

    // Displaying the list after deletion
    cout << "List after deletion: ";
    myList.display();

    return 0;
}
