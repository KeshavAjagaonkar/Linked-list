#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *back;
    Node *next;
    Node(int d1, Node *nxt, Node *bck) : data(d1), next(nxt), back(bck) {}
    Node(int d1) : data(d1), next(nullptr), back(nullptr) {}
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *createlistFromArray(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    Node *head = createlistFromArray(array);
    print(head);

    return 0;
}


