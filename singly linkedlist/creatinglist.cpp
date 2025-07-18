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
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
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
void insertAtBeg(Node* &head,int val){
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
// creating link list from an array 
Node* creatLinkListFromArray(vector<int>&arr){
    Node *head =nullptr;
    for(auto val:arr){
        insertAtTail(head, val);
    }
    return head;
}
//
void insertAtPosition(Node* &head, int position, int val) {
    if(position <= 0) {
        cout << "Invalid position\n";
        return;
    }

    if(position == 1) {
        insertAtBeg(head, val);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if(temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// deletion 
Node* deletefrombeg(Node* &head){
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* deleteAtTail(Node* &head){
    Node *temp=head;
    //case 1:
    if(head==nullptr){
        return head;

    }
    //case 2:
   if(head->next==nullptr){
       Node *t1 = head;
       head = nullptr;
       delete t1;
       return head;
   }
   while(temp->next->next!=nullptr){
       temp = temp->next;
   }
    Node *t1 = temp->next;
    temp->next = nullptr;
    delete t1;
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = creatLinkListFromArray(arr);
    
    insertAtPosition(head,4, 99);
    printList(head);
    head=deletefrombeg(head);
    printList(head);
    head = deleteAtTail(head);
    printList(head);
}