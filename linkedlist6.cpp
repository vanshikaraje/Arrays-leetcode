#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthOfList(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

bool searchElement(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    // Build linked list manually: 12 -> 5 -> 8 -> 7
    Node* head = new Node(12);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    cout << "Linked List: ";
    printLinkedList(head);

    cout << "Length of Linked List: " << lengthOfList(head) << endl;

    // 🔍 Search for elements
    int key1 = 8, key2 = 99;
    cout << "Searching " << key1 << ": "
         << (searchElement(head, key1) ? "Found" : "Not Found") << endl;
    cout << "Searching " << key2 << ": "
         << (searchElement(head, key2) ? "Found" : "Not Found") << endl;

    return 0;
}
