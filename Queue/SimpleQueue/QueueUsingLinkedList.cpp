#include <iostream>
using namespace std ;

class Node
{
    public :
    int data ;
    Node * next ;

    public: 
    Node( int value )
    {
       data = value ;
       next = NULL;

    }

};

class Queue 
{
    public :
    Node *front ;
    Node * rear ;

    Queue ( )
    {
        front = rear = NULL ;
    }
    
    bool isEmpty( )
    {
        return front == NULL;
    }

    void push ( int x )
    {
        if ( isEmpty () ) 
        {
            cout << "Pushed" << x << " into the Queue\n";
            front = new Node (x);
            rear = front ;
            return ;
        }

        else
        {
            rear->next = new Node (x);
            rear = rear->next;
            cout << "Pushed"<< x << " into Queue\n";
        }
    }

    void pop ( )
    {
        if ( isEmpty( ) )
        {
            cout << "Queue is Underflow";
            return ;
        }
        Node * temp = front ;
        front = front->next;
        cout << "Popped"<< temp->data << " from Queue\n";
        delete temp ;
    }

    int start ( )
    {
        if ( isEmpty ( ))
        {
            cout << "Queue is Empty";
            return -1  ;
        }
        else
        {
            return (front->data);
        }
    }
};


int main ( )
{
    Queue q ;
    q.push(5);
    q.push(51);
    q.push(115);
    q.push(58);
    q.pop();
    cout << q.start() << endl ;
    return 0 ;
}


