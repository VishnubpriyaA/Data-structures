//C++ Program to find whether the given elements of a singly linked list is a Palindrome
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void push(Node** head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head=new_node;
}
Node* reverseList(Node* head) {
    Node* p = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        current->next = p;
        p = current;
        current = next;
    }
    return p;
}
bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true;

    // Find the middle of the linked list
    Node* t1 = head;
    Node* t2 = head;
    while (t2 != NULL && t2->next != NULL) {
        t1 = t1->next;
        t2 = t2->next->next;
    }

    // Reverse the second half of the linked list
    Node* secondHalf = reverseList(t1);

    // Compare the first half and the reversed second half
    Node* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}
void print(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<"\n";
}
int main()
{
    Node* head = NULL;

    push(&head, 5);
    push(&head,4);
    push(&head, 3);
    push(&head,2);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    print(head);
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
