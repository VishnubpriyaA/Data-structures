// C++ implementation for Sorted merge of two
// sorted doubly circular linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

// A utility function to insert a new node at the
// beginning of doubly circular linked list
void insert(Node** head_ref, int data)
{
    // Allocate space for new node
    Node* new_node = new Node;
    new_node->data = data;

    // If the list is empty
    if (*head_ref == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }

    Node* current = *head_ref;

    // Traverse the list to find the end (node before head)
    while (current->next != *head_ref) {
        current = current->next;
    }

    // Insert the node at the end
    new_node->next = *head_ref;
    new_node->prev = current;
    current->next = new_node;
    (*head_ref)->prev = new_node;
}


// function for Sorted merge of two
// sorted doubly linked list
Node* merge(Node* first, Node* second)
{
    // If first list is empty
    if (!first)
        return second;

    // If second list is empty
    if (!second)
        return first;

    // Pick the smaller value and adjust
    // the links
    if (first->data < second->data) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// function for Sorted merge of two sorted
// doubly circular linked list
Node* mergeUtil(Node* head1, Node* head2)
{
    // if 1st list is empty
    if (!head1)
        return head2;

    // if 2nd list is empty
    if (!head2)
        return head1;

    // get pointer to the node which will be the
    // last node of the final list
    Node* last_node;
    if (head1->prev->data < head2->prev->data)
        last_node = head2->prev;
    else
        last_node = head1->prev;

    // store NULL to the 'next' link of the last nodes
    // of the two lists
    head1->prev->next = head2->prev->next = NULL;

    // sorted merge of head1 and head2
    Node* finalHead = merge(head1, head2);

    // 'prev' of 1st node pointing the last node
    // 'next' of last node pointing to 1st node
    finalHead->prev = last_node;
    last_node->next = finalHead;

    return finalHead;
}

// function to print the list
void printList(Node* head)
{
    Node* temp = head;

    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}

// Driver program to test above
int main()
{
    Node *head1 = NULL, *head2 = NULL;
    int n1,n2,arr1[100],arr2[100];
    cout<<"-----------------HARD:1---------------"<<endl;
    // list 1:
    cout<<"Enter number of elements in list1:"<<endl;
    cin>>n1;
    cout<<"Enter elements of list1:"<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
        insert(&head1,arr1[i]);
    }

    //insert(&head1, 1);
    //insert(&head1, 3);
    //insert(&head1, 5);
    //insert(&head1, 7);

    // list 2:
    cout<<"Enter number of elements in list2:"<<endl;
    cin>>n2;
    cout<<"Enter elements of list2:"<<endl;
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
        insert(&head2,arr2[i]);
    }

    //insert(&head2, 2);
    //insert(&head2, 4);
    //insert(&head2, 6);
    //insert(&head2, 8);

    Node* newHead = mergeUtil(head1, head2);

    cout << "Final Sorted List: ";
    printList(newHead);

    return 0;
}



