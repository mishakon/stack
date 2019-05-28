#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
    {
        int x;
        Node *Next;

    }*pNode;

class List
{

    Node *Head, *Tail;
public:
    List():Head(NULL),Tail(NULL){};
    ~List();
    void Add(int x);
    void Show();
    void del();
};


List::~List()
{
    Node *temp = Head;
    while (temp != NULL)
    {
        temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void List::Add(int x)
{
    Node *temp = new Node;
    temp->x = x;
    temp->Next = NULL;

    if (Head != NULL)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}

void List::Show()
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->x << " ";
        temp = temp->Next;
    }
    cout << endl;
}




void List::del()
{
    if (Head != NULL)
    {
        Node *temp = Head;
        Head = Head->Next;
        delete temp;
    }
    else
        cout << "the queue is empty" << endl;
}



int main()
{
    List lst;
    while(true)
    {
        cout << "add - adding to the queue" << endl;
        cout << "show - queue display" << endl;
        cout << "del - remove item from queue" << endl;
        cout << "exit - exit from the program" << endl;
        string command;
        cin >> command;
        if(command == "add")
            {
                int numeral;
                cout << "insert the number: ";
                cin >> numeral;
                lst.Add(numeral);
            }
        else if(command == "del")
        {
            lst.del();
        }
        else if(command == "show")
            {
                lst.Show();
            }
        else if(command == "exit")
        {
            break;
        }
        else
            cout << "error"  << endl;
    }
    return 0;
}
