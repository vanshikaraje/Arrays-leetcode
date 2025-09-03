#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert at the end (last index)
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode; // if list is empty

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert at k-th index (1-based index)
Node* insertAtK(Node* head, int k, int val) {
    if (k <= 0) {
        cout << "Invalid position!" << endl;
        return head;
    }

    // insert at head if k == 1
    if (k == 1) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        return head;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Insert before a given value
Node* insertBeforeValue(Node* head, int target, int val) {
    if (head == NULL) return NULL;

    // if target is at head
    if (head->data == target) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value " << target << " not found in list!" << endl;
        return head;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main() {
    // Build a linked list manually: 12 -> 5 -> 8 -> 7
    Node* head = new Node(12);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    cout << "Original Linked List: ";
    printList(head);

    // Insert at last
    head = insertAtEnd(head, 99);
    cout << "After Inserting 99 at End: ";
    printList(head);

    // Insert at k-th index (3rd position)
    head = insertAtK(head, 3, 55);
    cout << "After Inserting 55 at 3rd Position: ";
    printList(head);

    // Insert before value 8
    head = insertBeforeValue(head, 8, 44);
    cout << "After Inserting 44 before 8: ";
    printList(head);

    return 0;
}
