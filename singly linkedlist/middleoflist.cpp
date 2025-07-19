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
