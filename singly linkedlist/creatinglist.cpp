#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
void printList(Node* head){
    Node *temp = head;
    while(temp!=nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}
// here the change that may be small but very good impact when we pass it by reference . it avoid problem when the list is empty 
void insertAtTail(Node* &head,int val){
    Node *temp = head;
    if(head==nullptr){
        head = new Node(val);
        return;
    }
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new Node(val);
}


int main(){
    Node *first = new Node(10);
    first->next = new Node(20);

    insertAtTail(first, 30);
    printList(first);
}