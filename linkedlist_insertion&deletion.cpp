#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void pushstart(Node*& head_ref,int new_data)
{
    Node* head = new Node();
    head->data=new_data;
    head->next=head_ref;
    head_ref=head;
}

void pushmiddle(Node*& prev,int new_data)
{
    Node* new_node = new Node();
    new_node->next=prev->next;
    prev->next=new_node;
    new_node->data=new_data;
}

void pushend(Node*& temp,int new_data)
{
    Node* new_node = new Node();
    new_node->data=new_data;
    new_node->next=NULL;
    if(temp=NULL)
    {
        temp=new_node;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    return;
}

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
    Node* head = new Node();
    head->next=NULL;

    cout<<"\n";
    printlist(head);
    cout<<"\n";
    pushstart(head,2);
    pushstart(head,8);
    pushstart(head,5);
    printlist(head);
    cout<<"\n";
    pushmiddle(head->next,7);
    printlist(head);
    cout<<"\n";
    pushend(head,20);
    printlist(head);
}