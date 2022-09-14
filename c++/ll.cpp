#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data)
    {
        next = NULL;
    }
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int data)
    {
        head = new Node(data);
    }
    void insert(int data)
    {
        Node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
    bool find(int data)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == data)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void del(int data){
        Node* temp = head;
        if(temp->data == data){
            head = head->next;
            delete temp;
        }else{
            while (temp->next!=NULL)
            {
                if(temp->next->data == data){
                    Node* toDelete = temp->next;
                    temp->next = toDelete->next;
                    delete toDelete;
                    return;
                }
                temp=temp->next;
            }
        }
    }
    void print(){
        Node* temp = head;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    LinkedList ll(3);
    ll.insert(4);
    ll.insert(5);
    ll.print();
    ll.del(3);
    ll.print();
    
    return 0;
}