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

// Function to print Doubly Linked List (forward)
void printList(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List (forward): ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to print Doubly Linked List (reverse)
void printReverse(Node* tail) {
    Node* temp = tail;
    cout << "Doubly Linked List (reverse): ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// ✅ Function to convert array to doubly linked list
Node* convertArrToDLL(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        prev->next = newNode;
        newNode->prev = prev;
        prev = newNode;
    }

    return head;
}

int main() {
    // Example array
    vector<int> arr = {10, 20, 30, 40, 50};

    // Convert array to DLL
    Node* head = convertArrToDLL(arr);

    // Print list
    printList(head);

    // Find tail for reverse printing
    Node* tail = head;
    while (tail->next != NULL) tail = tail->next;

    printReverse(tail);

    return 0;
}
