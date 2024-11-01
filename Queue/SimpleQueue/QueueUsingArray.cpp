#include <iostream>
using namespace std ;

class Queue 
{
   public :
   int *arr ;
   int front ;
   int rear ;
   int size ;

   public :
   Queue ( int n )
   {
     arr = new int[n];
     front  = -1 ;
     rear = -1 ;
     size = n ; 
   }
   
   bool isEmpty ( )
   {
     return front == -1 ;
   }

   bool isFull ( )
   {
      return  (rear+1)%size == front ;
   }

   void push (int x)
   {
      
       if( isEmpty() )
       {
          cout<<"Pushed "<<x<<" into Queue\n";
          front = rear  = 0 ;
          arr[0]= x ;
       }

       else if ( isFull ( ) )
       {
          cout << "Queue is overflow\n";
          return ;
       }

       else
       {
          rear = rear + 1 ;
          arr[rear] = x ;
          cout<<"Pushed "<<x<<" into Queue\n";
       }
   }

   void pop ( )
   {
      if ( isEmpty() )
      {
         cout << "Queue is underflow\n";
         return ;
      }

      else 
      {
          if ( front == rear )
          {
              front = rear = -1 ;
              cout<<"Popped "<<arr[front]<<" from Queue\n";
          }

          else
          {
            cout<<"Popped "<<arr[front]<<" from Queue\n";
            front = front + 1 ; 
          }
         
      }
   }

   int start( )
   {
      if(isEmpty() )
      {
          return -1 ;
      }
      else
      {
         return arr[front];
      }
   }
};

int main( )
{

   Queue q(5);
   q.push(5);
   q.push(10);
   q.push(15);
   q.pop();
   q.pop();
   int y = q.start();
   if (!q.isEmpty())
   {
       cout << y <<endl;
   }

  

}

