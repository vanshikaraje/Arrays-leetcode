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

// Delete head node
Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
    return head;
}

// Delete last node
Node* deleteTail(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) { // only 1 node
        delete head;
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
    return head;
}

// Delete k-th position node
Node* deleteAtPosition(Node* head, int k) {
    if (head == NULL) return NULL;
    if (k == 1) return deleteHead(head);

    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) return head; // out of range

    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    delete temp;

    return head;
}

int main() {
    // Create DLL from array
    vector<int> arr = {10, 20, 30, 40, 50};
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

    // Delete head
    head = deleteHead(head);
    cout << "After deleting head: ";
    printList(head);

    // Delete tail
    head = deleteTail(head);
    cout << "After deleting tail: ";
    printList(head);

    // Delete k-th node (e.g., k = 2 -> 3rd element originally)
    int k = 2;
    head = deleteAtPosition(head, k);
    cout << "After deleting at position " << k << ": ";
    printList(head);

    return 0;
}
