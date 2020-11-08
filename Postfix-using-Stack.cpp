// Data Structures | Postfix Implementation using Stack C++

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

// perform arithmethic operations on given input
int operation(int a, int b, char op)
{
    switch (op)
    {
    case '+': 
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*': 
        return a * b;
        break;
    default:
        throw invalid_argument("Invaid Operator!");
        return 0;
        break;
    }
}
int main()
{
    // postfix implementation
    // Simple Statement -> (2 + 3) * 6
    // Postfix Statement -> 6 3 2 + *
    Stack<int> s1;
    char ch, choice = 'y';
    cout<<"\nOperators [ + - / * ] , Numbers [ 0 - 9 ]"<<endl;
    cout<<"Enter a Number or an Operator as mentioned above"<<endl; 
    while(choice == 'y' || choice == 'Y')
    {
        cout<<"\nEnter : "; cin>>ch;
        if(ch >= 48 && ch <= 57) // filtering integers 0 - 9 using ASCII values
            s1.push((((int)ch)-((int)'0'))); // first convert char to int then push in stack
        else
        {   // pop two items from stack
            // operator which is given by user
            // pass both to the operation function
            // and the value operation function returns, push back into the stack
            s1.push(operation(s1.pop(), s1.pop(), ch));
        }

        // ask user if user wants to enter another input
        cout<<"Do you want to enter more [Y-N] : "; cin>>choice;
    }
    s1.display();
    return 0;
}
