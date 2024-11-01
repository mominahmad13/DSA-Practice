#include <iostream>
using namespace std;

class CircularQueue 
{
   public:
   int *arr;
   int front;
   int rear ;
   int size;

   public:
   CircularQueue ( int n )
   {
      arr = new int [n];
      front = -1 ;
      rear = -1 ;
      size = n ;
   }

   bool isEmpty ( )
   {
      return front == -1 ;
   }

   bool isFull ( )
   {
      return front == (rear+1) % size ;
   }

   void push ( int x )
   {
      if ( isEmpty( ) ) 
      {
         front = rear = 0 ;
         arr[front] = x ;
         cout << x << "Pushed into Queue\n";
      }

      else if ( isFull( ) )
      {
         cout << "Queue is OverFlow\n";
         return ;
      }
      else
      {
         rear = ( rear + 1 ) % size ;
         arr[rear] = x ;
         cout << x << "Pushed into Queue\n";
      }
   }

   void pop ( )
   {
      if ( isEmpty( ) )
      {
         cout << "Queue is Empty\n";
         return ;
      }
      else 
      {
         if ( front == rear )
         {
             cout << "Popped" << arr[front] << " from Queue\n";
             front = rear = -1 ;
             
         }
         else
         {
             cout << "Popped" << arr[front] << "from Queue\n";
            front =  ( front + 1 ) % size ;
            
         }
      }
   }

   int start ( )
   {
      if ( isEmpty( ) )
      {
         cout << "Queue is Empty";
      }
      else
      {
         return arr[front] ;
      }
   }
};

int main ( )
{
   CircularQueue cq(5);
   cq.push(5);
   cq.push(10);
   cq.push(15);
   cq.pop();
   cq.pop();
   int y = cq.start();
   if (!cq.isEmpty())
   {
       cout << y <<endl;
   }

}