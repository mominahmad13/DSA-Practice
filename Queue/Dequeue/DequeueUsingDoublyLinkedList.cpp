#include<iostream>
using namespace std ;

class Node 
{
    public :
    int data ;
    Node * next ;
    Node * prev ;

    Node ( int value )
    {
        data = value ;
        next = NULL;
        prev= NULL;
    }

};

class Dequeue
{
   Node* front ;
   Node* rear ;
   
   public: 
   Dequeue ( )
   {
     front = NULL;
     rear = NULL;
   }

   void pushFront ( int x )
   {
      if ( front == NULL )
      {
         front = new Node (x);
         rear = front ;      
         cout << "Pushed " << x << " in front of Deque\n";
      }
      else
      {
         Node *temp = new Node (x);
         temp->next = front ;
         front->prev = temp ;
         front = temp ;
         cout <<"Pushed "<<x<<" in front of Dequeue\n";
      }
   }

   void pushBack ( int x )
   {
      if ( front == NULL )
      {
         front = new Node (x);
         rear = front ;      
         cout << "Pushed " << x << " in back of Deque\n";
      }
      else
      {
         Node *temp = new Node (x);
         rear->next = temp ;  
         temp->prev = rear  ;
         rear = temp ;
         cout <<"Pushed "<<x<<" in back of Dequeue\n";
      }
   }

   void popFront ( )
   {
      if ( front == NULL) 
      {
         cout << "Dequeue is Empty\n";
         return ;
      }

      else
      {
        Node *temp = front ;
        front = front->next;
        cout << temp->data << " popped from front\n";
        delete temp ;
        // if one node
        if ( front )
        {
            front->prev =NULL;
        }
        else
        {
            rear = NULL;
        }
    
      }
   }

   void popBack ( )
   {
      if ( front == NULL) 
      {
         cout << "Dequeue is Empty\n";
         return ;
      }

      else
      {
        Node *temp = rear ;
        rear = rear->prev;
        cout << temp->data << " popped from back\n";
        delete temp ;
        // if one node
        if ( rear )
        {
            rear->next = NULL;
        }
        else
        {
            front = NULL;
        }
          
      }
   }

   int start ( )
   {
      if ( front == NULL)
      {
         cout << "Dequeue is Empty\n";
         return -1 ;
      }
      else
      {
         return front->data ;
      }
   }

   int end ( )
   {
      if ( front = NULL )
      {
         cout << "Dequeue is Empty\n";
         return - 1 ;
      }
      else
      {
         return rear->data ;
      }
   }
};
int main ( )
{
    Dequeue dq ;
    dq.pushFront(5);
    dq.pushBack(13);
    dq.pushFront(8);
    dq.popBack();
    cout << dq.start ( ) << endl ;;
    cout << dq.end() << endl ;
    return 0 ;
}

