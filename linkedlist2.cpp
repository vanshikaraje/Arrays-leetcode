#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void printList(Node* head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
Node* insertAtHead(Node* head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head =newNode;
    return head;
}
int main(){
       Node* head = new Node(12);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    cout<<"original linked list:";
    printList(head);

    head  = insertAtHead(head,99);
    cout<<"after inserting at head:";
     printList(head);

     return 0;

}