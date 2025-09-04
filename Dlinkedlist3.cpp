#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Print DLL forward
void printList(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert at head
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;
    newNode->next = head;
    head->prev = newNode;
    return newNode; // new head
}

// Insert at tail
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at k-th position
Node* insertAtPosition(Node* head, int k, int val) {
    if (k <= 1) return insertAtHead(head, val);

    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return head; // position out of range

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

int main() {
    // Create DLL from array
    vector<int> arr = {10, 20, 30};
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        prev->next = newNode;
        newNode->prev = prev;
        prev = newNode;
    }

    cout << "Original DLL: ";
    printList(head);

    // Insert at head
    head = insertAtHead(head, 5);
    cout << "After inserting 5 at head: ";
    printList(head);

    // Insert at tail
    head = insertAtTail(head, 40);
    cout << "After inserting 40 at tail: ";
    printList(head);

    // Insert at 3rd position
    head = insertAtPosition(head, 3, 15);
    cout << "After inserting 15 at position 3: ";
    printList(head);

    return 0;
}
