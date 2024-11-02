#include <iostream>
using namespace std ;

 // no need of front
class PriorityQueue 
{
    public : 
    int *arr ;
    int *priority; 
    int front ;
    int rear ;
    int size ;
    
    PriorityQueue ( int n )
    {
       front = -1 ;
       rear = -1 ;
       arr = new int [n];
       priority = new int[n];
       size = n ;  
    }
    
    bool isEmpty ()
    {
        return front == -1 ;
    }
    bool isFull ( )
    {
       return (front == 0 && rear == size - 1 ) ;
    }
    void enqueue ( int x  , int p )
    {
        if ( isEmpty( ) )
        {
           front = rear  = 0;
           arr[0] = x ;
           priority[0]=p;
           cout <<"Pushed "<<x<<" in Queue\n";
        }
        else if ( isFull() )
        {
            cout << "Priority Queue is OverFlow\n";
            return ;
        }
        // insertion after deletion
        else if ( front > 0 && rear == size - 1 )
        {
            int i ;
            for ( i = front ; i<=rear ; i++ )
            {
                arr[i-front] = arr[i]; 
                priority[i-front] = priority[i] ;
                // purpose of the loop is to shift elements upward in array
            }
             rear = rear - front ;
             front  = 0;
             // same loop is used
            for (  i = rear ; i>=front ; i-- )
            {
               if ( p > priority [i] )
               {
                  arr[i+1] = arr[i];
                  priority[i+1] = priority[i];
               }
               else
               {
                  break ;
               }
            }
               arr[i+1] = x ;
               priority[i+1] = p ;
               rear++ ;
               cout << "Pushed "<<x <<" in Queue\n";
        }
        else
        {
            int i ;
            for (  i = rear ; i>=front ; i-- )
            {
               if ( p > priority [i] )
               {
                  arr[i+1] = arr[i];
                  priority[i+1] = priority[i];
               }
               else
               {
                  break ;
               }
            }
                arr[i+1] = x ;
                priority[i+1] = p ;
                rear++ ;
                cout << "Pushed "<<x<<" in Queue\n";

        }
    }

    void dequeue ( )
    {
        if (isEmpty() )
        {
           cout << "Priority Queue is Empty\n";
           return ;
        }
        else
        {
            cout << "Popped "<<arr[front]<<" from Queue\n";
            if ( front == rear )
            {
                front = rear = -1 ;
            }
            else
            {
                front++ ;
            }
        }
    }

    int start ( )
    {
        if ( isEmpty( ) )
        {
            cout << "Queue is Empty\n";
            return -1 ;
        }
        else
        {
            return arr[front];
        }
    }
};

int main ( )
{
   PriorityQueue p (5);
   p.enqueue(12 ,2);
   p.enqueue(14,1);
   p.enqueue(13,5);
   p.enqueue(19,7);
   p.enqueue(17,9);
 
   p.enqueue(13,2);
   cout << p.start() << endl ;


}