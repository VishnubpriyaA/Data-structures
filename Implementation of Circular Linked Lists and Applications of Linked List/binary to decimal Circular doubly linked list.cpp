//Convert a binary number which is stored in a linked list to decimal. Use Circular doubly linked list.
#include <iostream>
#include <cmath>

// Node structure for Circular Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Function to convert binary number in circular doubly linked list to decimal
int convertBinaryToDecimal(Node* head) {
    if (head == nullptr) {
        return 0; // Empty list
    }

    Node* current = head;
    int decimalValue = 0;
    int position = 0;

    do {
        // Binary to Decimal conversion: decimalValue = decimalValue + (bit * 2^position)
        decimalValue += current->data * std::pow(2, position);
        current = current->next;
        position++;
    } while (current != head);

    return decimalValue;
}

// Helper function to create a circular doubly linked list from an array
Node* createCircularDoublyLinkedList(const int* binaryArray, int size) {
    if (size == 0) return nullptr;

    Node* head = new Node(binaryArray[0]);
    Node* tail = head;

    for (int i = 1; i < size; ++i) {
        Node* newNode = new Node(binaryArray[i]);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    tail->next = head;
    head->prev = tail;

    return head;
}

// Helper function to print the circular doubly linked list (for testing)
void printCircularDoublyLinkedList(Node* head) {
    if (head == nullptr) return;

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

// Helper function to free the circular doubly linked list (for cleanup)
void deleteCircularDoublyLinkedList(Node* head) {
    if (head == nullptr) return;

    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
}

int main() {
    int binaryArray[] = {0, 0, 0, 1}; // Example binary number (1011)
    int size = sizeof(binaryArray) / sizeof(binaryArray[0]);

    Node* head = createCircularDoublyLinkedList(binaryArray, size);

    std::cout << "Circular Doubly Linked List: ";
    printCircularDoublyLinkedList(head);

    int decimalValue = convertBinaryToDecimal(head);
    std::cout << "Decimal Value: " << decimalValue << std::endl;

    deleteCircularDoublyLinkedList(head);

    return 0;
}
