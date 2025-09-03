#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL; // fixed ;
    }
};

void printList(Node* head) {  // fixed name
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
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

    return 0;
}
