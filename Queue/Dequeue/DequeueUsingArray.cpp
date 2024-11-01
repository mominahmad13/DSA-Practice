#include <iostream>
using namespace std ;


class Dequeue 
{
   public :
   int * arr ;
   int front ; 
   int rear ;
   int size ;

   Dequeue ( int n )
   {
      front = rear = -1 ;
      arr = new int [n];
      size = n ;
   }  

   bool isEmpty( )
   {
     return ( front  == - 1 ) ;
   }

   bool isFull ( )
   {
     return ( (rear+1) % size == front ) ;
   }
   
   void pushFront ( int x )
   {
       if ( isEmpty() )
       {
          front  = rear = 0 ;
          arr[0] = x ;
          cout << "Pushed "<<x <<" in front\n";
          return;
       }

       else if ( isFull( ) )
       {
          cout << "Dequeue is overflow\n";
          return ;
       }
       else
       {
             front =  (front-1+size) % size ;
             arr[front] = x ;
             cout << "Pushed "<< x << " in front\n";

       }
   } 

   void pushBack ( int x )
   {
      if ( isEmpty() )
       {
         front = rear = 0 ;
         arr[0] = x ;
         cout << "Pushed "<< x << " in Back\n";
         return ;
       }
      else if ( isFull() )
      {
          cout << "Dequeue is overflow\n";
          return ;
      }
      else 
       {
          rear = (rear+1) %size;
           arr[rear]=x;
           cout << "Pushed "<<x<<" in Back\n";
           return ;
       }
   }

   void popFront ( )
   {
      if ( isEmpty( ) )
      {
          cout << "Dequeue is empty\n";
          return ;
      }
      else
      {
         if ( front == rear) // single element
         {
            cout << "Popped "<<arr[front] <<" from front\n";
            front = rear = -1;   
         }
         else
         {
           cout << "Popped "<<arr[front] <<" from front\n";
           front = (front+1)%size ;
         }
      }

   }

   void popBack ( )
   {
       if (isEmpty( ) )
       {
         cout << "Dequeue is empty\n";
         return ; 
       }
       else
       {
          if ( front == rear )
          {
             cout << "Popped "<<arr[rear] <<" from back\n";
             front = rear = -1 ;
          }
          else
          {
              cout << "Popped "<<arr[rear] <<" from back\n";
              rear = (rear-1+size)%size ;
          }
       }
   }

   int start ( )
   {
       if ( isEmpty ( ) )
       {
           cout <<  "Dequeue is Empty\n";
           return -1 ;
       }
       else
       {
          return arr[front];   
       }
   }

   int end ( )
   {
       if ( isEmpty( ) )
       {
          cout << "Dequeue is Empty\n";
          return -1 ;
       }
       else
       {
          return arr[rear] ;
       }
   }
   

};

int main ( )
{      

    Dequeue q(5);
    q.pushBack(10);
    q.pushFront(9);
    q.pushBack(10);
    q.pushFront(9);
    q.pushBack(10);
    q.pushFront(9);
    q.popBack();
    q.popFront();
    cout << q.start()<<endl ;
    cout << q.end() << endl ;

    return 0 ;
   
}