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





int main(){
    Node *first = new Node(10);
    first->next = new Node(20);
    cout << first->data<<endl;
    cout << first->next->data;
}