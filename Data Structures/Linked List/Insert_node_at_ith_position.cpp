#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newdata = new Node(data);
        if (head == NULL)
        {
            head = newdata;
            tail = newdata;
        }
        else
        {
            tail->next = newdata;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
Node *insertnode(Node *head, int i, int data)
{
    Node *newnode = new Node(data);
    Node *temp = head;
    int count = 0;
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    else
    {
        while (temp != NULL && count < i - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
        {
            Node *a = temp->next;
            temp->next = newnode;
            newnode->next = a;
        }
        return head;
    }
}
void print(Node *head)
{
    for (; head != NULL;)
    {
        cout << head->data << " " << head->next << endl;
        head = head->next;
    }
}
int main()
{
    Node *head = takeinput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertnode(head, i, data);
    print(head);
}