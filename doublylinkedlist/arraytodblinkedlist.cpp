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

Node *deleteFromBeg(Node *&head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node *deleteFromEnd(Node *&head)
{
    Node *tail = head;
    if (head == nullptr)
    {
        return nullptr;
    }
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    // case 1: only one node in the list .
    if (tail->back == nullptr)
    {
        delete tail;
        return nullptr;
    }
    // case 2: more than one node in the list.
    Node *prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
Node *deletekthnode(Node *&head, int position)
{
    // calculating the position
    int count = 0;
    Node *temp = head;
    if (head == nullptr)
    {
        return nullptr;
    }
    while (temp != nullptr)
    {
        count++;
        if (count == position)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "out of bound " << endl;
        return head;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    if (prev == nullptr && front == nullptr)
    {
        return nullptr;
    }
    if (prev == nullptr)
    {
        head = deleteFromBeg(head);
        return head;
    }
    if (front == nullptr)
    {
        head = deleteFromEnd(head);
        return head;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;

    delete temp;
    return head;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    Node *head = createlistFromArray(array);
    print(head);
    // head = deleteFromBeg(head);
    // print(head);
    // head = deleteFromEnd(head);
    head = deletekthnode(head,1);
    print(head);
    return 0;
}