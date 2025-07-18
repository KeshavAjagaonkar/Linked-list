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

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = creatLinkListFromArray(arr);
    printList(head);
}