#include<iostream>
using namespace std;

class Node
{
    public: 
        int data;
        Node* next;
        Node* prev;
};

void printlistforward(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

void printlistbackward(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->prev;
    }
}

int main()
{
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();
    Node* fourth=new Node();

    head->data=1;
    head->next=second;
    head->prev=NULL;
    second->data=2;
    second->next=third;
    second->prev=head;
    third->data=3;
    third->next=fourth;
    third->prev=second;
    fourth->data=4;
    fourth->next=NULL;
    fourth->prev=third;
    cout<<"\nNormally\n";
    printlistforward(head);
    cout<<"\nBackwards\n";
    printlistbackward(fourth);
}