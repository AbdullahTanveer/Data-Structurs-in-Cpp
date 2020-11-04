// Data Structures - Generic Singly Linked List Implementation in C++
// its a generic linked list. So you can define datatype that you want to store in list
#include <iostream>

using namespace std;

// template type to make list generic
template<class T>
// List Class
class List
{
    private:
        // Node Class
        class Node
        {
            public:
                T object;
                Node *next;
        };
        int size; // for length of the list
        Node *headNode, *lastcurrentNode, *currentNode;
    public:
        // constructor
        List()
        {
            size = 0;
            headNode = new Node();
            headNode -> next = nullptr;
            currentNode = nullptr;
            lastcurrentNode = nullptr;
        }
        // destructor
        ~List(){ }

        // add items in list
        void Add(T obj)
        {
            // create a temp node
            Node *newNode = new Node();
            // set object 
            newNode -> object = obj;
            // check if list is empty
            if(currentNode != nullptr)
            {
                // current is not null means list is not empty
                // so we add items from currentNode
                this -> currentNode = lastcurrentNode -> next; // make sure currentNode is last item of list
                newNode -> next = currentNode -> next;
                currentNode -> next = newNode;
                lastcurrentNode = currentNode;
                currentNode = newNode;
            }
            else
            {
                // current is null means list is empty
                // so we add item from headNode's next
                newNode -> next = nullptr;
                headNode -> next = newNode;
                lastcurrentNode = headNode;
                currentNode = newNode;
            }
            size++;
            
        }

        // access list item by index ( helps in accessing list items )
        T Index(int in)
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

        // remove an item from list ( will remove from end of list )
        void Remove()
        {
            // remove an item at the end of list
            // then reset the currentNode, lastcurrentNode according to current items in list
            currentNode = lastcurrentNode -> next; // make sure the currenNode is last node
            delete currentNode; // delete current node
            currentNode = lastcurrentNode; // move 1 step back
            currentNode -> next = nullptr;
            // for lastcurrentNode 
            Node* pre = new Node();
            pre = headNode;
            while(pre)
            {
                if(currentNode == pre -> next)
                    lastcurrentNode = pre;

                pre = pre -> next;
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

// demo generic linked list
void DemoILL()
{
    cout<<"\n=============== Integer Type Singly Linked List ==============="<<endl;
    List<int> l;
    // adding some items
    for(int i = 0; i <= 10; i++)
        l.Add(i);

    // displaying all items from list using display function
    cout<<"\n-- Items added in List --"<<endl;
    l.Display();

    // length of list
    cout<<"\nLength of list : "<<l.Length()<<endl;

    // removing some items from list
    l.Remove();
    l.Remove();

    // removed two items from list, now let's see how many items left in list
    cout<<"\n-- After Removing some items -- "<<endl;
    l.Display();

    // length of list
    cout<<"\nLength of list : "<<l.Length()<<endl;

    // access list item by index
    cout<<"\n-- Access List item by index -- "<<endl;
    cout<<"Item on Index(3) : "<<l.Index(3)<<endl;
}

void DemoCLL()
{
    cout<<"\n=============== Char Type Singly Linked List ==============="<<endl;
    List<char> l;
    // adding some items
    char ch = 'a';
    for( ; ch <= 122; ch++)
        l.Add(ch);

    // displaying all items from list using display function
    cout<<"\n-- Items added in List --"<<endl;
    l.Display();

    // length of list
    cout<<"\nLength of list : "<<l.Length()<<endl;

    // removing some items from list
    l.Remove();
    l.Remove();
    l.Remove();
    l.Remove();

    // removed two items from list, now let's see how many items left in list
    cout<<"\n-- After Removing some items -- "<<endl;
    l.Display();

    // length of list
    cout<<"\nLength of list : "<<l.Length()<<endl;

    // access list item by index
    cout<<"\n-- Access List item by index -- "<<endl;
    cout<<"Item on Index(3) : "<<l.Index(3);
}
int main()
{
    // demo of integer type linked list
    DemoILL();

    // demo of char type linked list
    DemoCLL();

    return 0;
}