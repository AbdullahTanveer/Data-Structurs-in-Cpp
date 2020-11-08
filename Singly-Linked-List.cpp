// Data Structures - Singly Linked List Implementation in C++
#include <iostream>

using namespace std;

// Node Class
class Node
{
    private:
        int object;
        Node *next;
    public:
        // set object value
        void set(int object)
        {
            this -> object = object;
        }
        // get object value
        int get()
        {
            return this -> object;
        }
        // set next that points to next node
        void setNext(Node *next)
        {
            this -> next = next;
        }
        // get next that returns the address of next node
        Node* getNext()
        {
            return this -> next;
        }
};

// List Class
class List
{
    private:
        int size; // for length of the list
        Node *headNode, *lastcurrentNode, *currentNode;
    public:
        // constructor
        List()
        {
            size     = 0;
            headNode = new Node();
            headNode -> setNext(nullptr);
            currentNode     = nullptr;
            lastcurrentNode = nullptr;
        }
        // destructor
        ~List(){ }

        // add items in list
        void Add(int obj)
        {
            // create a temp node
            Node *newNode = new Node();
            // set object 
            newNode -> set(obj);
            // check if list is empty
            if(currentNode != nullptr)
            {
                // current is not null means list is not empty
                // so we add items from currentNode
                this -> currentNode = lastcurrentNode -> getNext(); // make sure currentNode is last item of list
                newNode -> setNext(currentNode -> getNext());
                currentNode -> setNext(newNode);
                lastcurrentNode = currentNode;
                currentNode = newNode;
            }
            else
            {
                // current is null means list is empty
                // so we add item from headNode's next
                newNode -> setNext(nullptr);
                headNode -> setNext(newNode);
                lastcurrentNode = headNode;
                currentNode = newNode;
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
                    this -> currentNode = this -> currentNode -> getNext();
                return this -> currentNode -> get();
            }
        }

        // display all items available in list
        void Display()
        {
            // we will use currentnode to iterate throw items
            // headNode is just a dummy node so we start from next of head
            this -> currentNode = this -> headNode -> getNext();
            while(this -> currentNode)
            {
                cout<<currentNode -> get()<<endl;
                this -> currentNode = this -> currentNode -> getNext();
            }
        }

        // remove an item from list ( will remove from end of list )
        void Remove()
        {
            // remove an item at the end of list
            // then reset the currentNode, lastcurrentNode according to current items in list
            currentNode = lastcurrentNode -> getNext(); // make sure the currenNode is last node
            delete currentNode; // delete current node
            currentNode = lastcurrentNode; // move 1 step back
            currentNode -> setNext(nullptr);
            // for lastcurrentNode 
            Node* pre = new Node();
            pre = headNode;
            while(pre)
            {
                if(currentNode == pre->getNext())
                    lastcurrentNode = pre;

                pre = pre->getNext();
            }
            size--;
            delete pre; // now delete this temp node 
        }

        // check length of list 
        int Length()
        {
            return this -> size;
        }

        // check list is empty of not
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