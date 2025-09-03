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

// Function to remove the first node (head)
Node* removeHead(Node* head) {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return NULL;
    }
    Node* temp = head;   // store old head
    head = head->next;   // move head
    delete temp;         // free memory
    return head;         // return new head
}
Node* removeTail(Node* head){
    if(head ==NULL){
        cout<<"List is already empty!"<<endl;
        return NULL;
    }
    if(head ->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
    
}

Node* removeKth(Node* head, int k) {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return NULL;
    }
    if (k == 1) { // remove head
        return removeHead(head);
    }

    Node* temp = head;
    int count = 1;

    // move to (k-1)-th node
    while (temp != NULL && count < k - 1) {
        temp = temp->next;
        count++;
    }

    // if k is greater than length
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return head;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}

int main() {
    // Create linked list manually: 12 -> 5 -> 8 -> 7 -> NULL
    Node* head = new Node(12);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    cout << "Original Linked List: ";
    printList(head);

    // Remove first element
    head = removeHead(head);
    cout << "After Removing Head Node: ";
    printList(head);

    head = removeTail(head);
    cout << "After Removing Tail Node: ";
    printList(head);

    int k = 2;
    head = removeKth(head, k);
    cout << "After Removing " << k << "-th Node: ";
    printList(head);

    return 0;
}
