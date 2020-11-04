// Data Structures - Doubly Linked List Implementation in C++

#include <iostream>

using namespace std;

// Node Class
class Node
{
    public:
        int object;
        Node *next, *prev;
};

// List Class
class List
{
    private:
        int size; // for length of the list
        Node *headNode, *currentNode, *tailNode;
    public:
        // constructor
        List()
        {
            size = 0;
            headNode = new Node();
            headNode -> next = nullptr;
            currentNode = nullptr;
            tailNode = nullptr;
        }
        // destructor
        ~List(){ }

        // add items in list
        void Add(int obj)
        {
            // create a temp node
            Node *newNode = new Node();
            // set object 
            newNode -> object = obj;
            // check if list is empty
            if(tailNode != nullptr)
            {
                // current is not null means list is not empty
                // so we add items from currentNode
                /*newNode -> next =(currentNode);
                newNode -> prev =(currentNode -> prev);
                (currentNode -> prev) -> next =(newNode);
                currentNode -> prev =(newNode);
                currentNode = newNode; */

                newNode -> next = nullptr;
                newNode -> prev = tailNode;
                tailNode -> next = newNode;
                tailNode = newNode;
                currentNode = tailNode;
            }
            else
            {
                // current is null means list is empty
                // so we add item from headNode's next
                newNode -> next = nullptr;
                newNode -> prev = headNode; 
                headNode -> next = newNode;
                headNode -> prev = nullptr;
                currentNode = newNode;
                tailNode = currentNode;
            }
            size++;
            
        }

        // access list item by index ( helps in accessing list items )
        int Index(int in)
        {
            this -> currentNode = this -> headNode; // start from headNode
            if(in < 0 || in > size - 1) // if given is greater than size of list or less thean 0 prompt a error msg
            { 
                cout<<"Invalid Index number!"<<endl;
                return 0;
            }
            else
            {
                for(int i = 0; i <= in; i++)
                    this -> currentNode = this -> currentNode -> next;
                return this -> currentNode -> object;
            }
        }

        // display all items available in list
        void Display()
        {
            // we will use currentnode to iterate throw items
            // headNode is just a dummy node so we start from next of head
            this -> currentNode = this -> headNode -> next;
            while(this -> currentNode)
            {
                cout<<currentNode -> object<<" ";
                this -> currentNode = this -> currentNode -> next;
            }
        }
        // display all item of list in reverse order
        void Reverse()
        {
            // we will use currentnode to iterate throw items 
            // but this time in reverse order using prev node
            this -> currentNode = this -> tailNode;
            while(this -> currentNode -> prev)
            {
                cout<<currentNode -> object<<" ";
                this -> currentNode = this -> currentNode -> prev;
            }
        }
        // remove an item from list ( will remove from end of list )
        void Remove()
        {
            // remove an item at the end of list
            // then reset the currentNode, lastcurrentNode according to current items in list
            currentNode = tailNode -> prev; // move currentnode to second last node
            currentNode -> next =(nullptr); // set next to null, because we want to access last node anymore
            delete tailNode; // delete the last node
            tailNode = currentNode; // set last node to currentnode
            size--;
        }

        // check length of list 
        int Length()
        {
            return this -> size;
        }
        
};

int main()
{
    // demo linked list
    // declaring a list
    List l1;

    // adding some items
    l1.Add(1);
    l1.Add(2);
    l1.Add(3);
    l1.Add(4);
    l1.Add(5);
    l1.Add(6);

    // displaying all items from list using display function
    cout<<"\n-- Items added in List --"<<endl;
    l1.Display();

    // displaying all items from list in reverse order
    cout<<"\n-- Reverse List --"<<endl;
    l1.Reverse();

    // length of list
    cout<<"\nLength of list : "<<l1.Length()<<endl;

    // removing some items from list
    l1.Remove();

    // removed two items from list, now let's see how many items left in list
    cout<<"\n-- After Removing an item -- "<<endl;
    l1.Display();

    // length of list
    cout<<"\nLength of list : "<<l1.Length()<<endl;

    // access list item by index
    cout<<"\n-- Access List item by index -- "<<endl;
    cout<<"Item on Index(3) : "<<l1.Index(3);

    return 0;
}