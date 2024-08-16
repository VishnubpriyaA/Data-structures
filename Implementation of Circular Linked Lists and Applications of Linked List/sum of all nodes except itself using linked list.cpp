//Given a circular doubly linked list consisting of N nodes, the task is to modify every node of the
//given Linked List such that each node contains the sum of all nodes except that node
#include <iostream>
using namespace std;
// Definition for a doubly linked list node.
struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

void modifyCircularDoublyLinkedList(Node* head) {
    if (!head) return;

    Node* current = head;
    int totalSum = 0;
    int nodeCount = 0;

    // Compute the total sum of all nodes and count the nodes
    do {
        totalSum += current->data;
        nodeCount++;
        current = current->next;
    } while (current != head);

    // Modify each node
    current = head;
    do {
        current->data = totalSum - current->data;
        current = current->next;
    } while (current != head);
}

// Utility function to print the circular doubly linked list
void printCircularDoublyLinkedList(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Utility function to create a circular doubly linked list from an array
Node* createCircularDoublyLinkedList(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        prev->next = newNode;
        newNode->prev = prev;
        prev = newNode;
    }

    // Connect the last node to the head to form a circular doubly linked list
    prev->next = head;
    head->prev = prev;

    return head;
}

// Main function to test the implementation
int main() {
    int arr[100];
    int n ;
    cout<<"-----------------MEDIUM :1----------------"<<endl;
    cout<<"Enter number of elements :"<<endl;
    cin>>n;
    cout<<"Enter elements:"<<endl;
     for(int i;i<n;i++)
     {
         cin>>arr[i];
     }
    Node* head = createCircularDoublyLinkedList(arr, n);

    cout << "Original list: ";
    printCircularDoublyLinkedList(head);

    modifyCircularDoublyLinkedList(head);

    cout << "Modified list: ";
    printCircularDoublyLinkedList(head);

    return 0;
}



