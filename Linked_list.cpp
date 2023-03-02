#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void printlist(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main()
{
    Node*head=NULL;
    Node*second=NULL;
    Node*third=NULL;
    Node*fourth=NULL;

    head=new Node();
    second=new Node();
    third=new Node();
    fourth=new Node();

    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=NULL;

// we yave to break list in middle. so we will split it after node second

    // fourth->next=head;

    printlist(head);
    return 0;
}