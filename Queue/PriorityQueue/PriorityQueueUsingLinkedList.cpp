#include <iostream>
using namespace std ;

class Node
{
    public:
    int data ;
    int prior ;
    Node *next ;

    Node(int value ,int p )
    {
       data = value ;
       prior = p ;
       next = NULL;
    }
};

class PriorityQueue
{
    public:
    Node *front ;
    Node *rear ;


    PriorityQueue()
    {
       front = NULL;
       rear = NULL; 
    }

    bool isEmpty()
    {
       return (front == NULL);
    }

    void enqueue(int x , int p)
    {
       if (isEmpty())
       {
          front = new Node(x,p);
          rear = front ;
          cout << "Pushed "<<x<<" into Queue\n";
          return ;
       }

       if ( p > front->prior )
       {
          Node * newNode = new Node(x,p);
          newNode->next = front ;
          front = newNode;
          cout << "Pushed "<<x<<" into Queue\n";
          return ; 
       }

       Node *temp = front ;
       while( temp->next !=NULL && temp->next->prior >= p )
       {
          temp = temp->next;
       }
           Node *newNode = new Node(x,p);
           newNode->next = temp->next ;
           temp->next = newNode;

        // Update rear if inserted at end
        if (newNode->next == NULL)
        {
            rear = newNode ;
        }
        cout << "Pushed "<<x<<" into Queue\n";

    }

    void dequeue ( )
    {
        if ( isEmpty() )
        {
            cout << "Queue is Empty/n";
            return ;
        }
        else
        {
            Node *temp = front ;
            cout << "Popped "<<front->data<<" into Queue\n";
            front = front->next ;
            delete temp ;
        }
    }

    int start ( )
    {
        if (isEmpty())
        {
            cout <<"Queue is Empty\n";
            return -1 ;
        }
        else
        {
            return front->data ;
        }
    }
};

int main ( )
{
    PriorityQueue p ;
    p.enqueue(1,7);
    p.enqueue(2,3);
    p.enqueue(5,8);
    p.enqueue(9,1);
    p.dequeue();
    cout << p.start() << endl ;

}