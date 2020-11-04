// Data Structures | Stack Implementation using Linked List in C++

#include<iostream>

using namespace std;

template<class T>
// Stack Class
class Stack
{
    private:
        class Node
        {
            public:
                T object;
                Node* next;
        };
        int size;
        Node *top;
    public:
        // constructor
        Stack() 
        {
            size = 0;
            top = nullptr;
        }
        // destructor
        ~Stack() { }

        // add items in stack
        void push(T obj)
        {   
            Node *newNode = new Node();
            newNode -> object = obj;
            if(top == nullptr)
            {
                newNode -> next = nullptr;
                top = newNode;
            }
            else
            {
                newNode -> next = top;
                top = newNode;
            }
            size++;
        }

        // delete item from stack
        T pop()
        {  
            if(IsEmpty())
                throw invalid_argument("Stack is already Empty!");
            else
            {
                T data;
                Node *temp = new Node();
                temp = top -> next;
                data = top -> object;
                delete top;
                top = temp;
                size--;
                return data;  
            }
        }

        // fetch top item of stack
        T peek() { return top -> object; }

        void display()
        {
            Node *temp = new Node();
            temp = top;
            while(temp)
            {
                cout<<temp -> object<<" ";
                temp = temp -> next;
            }
        }
        // check stack is empty or not
        bool IsEmpty()
        {
            if(size == 0)
                return true;
            else
                return false;
        }
};


int main()
{
    // stack 
    Stack<int> s1;

    // adding some items
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    // display items
    s1.display();

    // pop an item
    cout<<"\nPoped item : "<<s1.pop()<<endl;

    // display items
    s1.display(); 

    // fetch top
    cout<<"\nTop Item : "<<s1.peek()<<endl;

    // check stack is empty
    cout<<"Is Stack Empty : "<<s1.IsEmpty()<<endl;

    return 0;
}
