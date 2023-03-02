#include<iostream>
using namespace std;

#define MAX 1000

class stack
{
    int top;

    public:
        int a[MAX];
        Stack() {top=-1;}
        bool push(int x);
        int pop();
        int peek();
        bool isempty();
};

bool stack::push(int x)
{
    if(top>=(MAX-1))
    {
        cout<<"\nStack Overflow\n";
        return false;
    }
    else
    {
        a[++top]=x;
        cout<<x<<" is pushed into the stack\n";
        return true;
    }
}

int stack::pop()
{
    if(top<=0)
    {
        cout<<"\nStack underflow\n";
        return 0;
    }
    else
    {
        int x=a[top--];
        return x;
    }
}

int stack::peek()
{
    if(top<=0)
    {
        cout<<"\nStack is empty\n";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool stack::isempty()
{
    return (top<=0);
}

int main()
{
    class stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);

    cout<<s.pop()<<" is popped from stack\n";
    cout<<s.peek()<<" is top element of stack\n";
    
    cout<<"\nElements present in stack: \n";
    while(!s.isempty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
    return 0;
}