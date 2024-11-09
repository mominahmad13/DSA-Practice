#include <iostream>
using namespace std;

class Node
{
   public :
   int data ;
   Node *next ;

   Node( int value )
   {
      data = value ;
      next = NULL;
   }
};

Node *insertAtEnd( Node *head , int arr [] , int size )
{
     Node * last =  NULL ;
     for ( int  i = 0 ; i < size ; i++ )
     {
        if ( head == NULL )
        {
            head = new Node (arr[i]);
            head->next = head ;
            last = head ;
        }
        else
        {
            Node * temp = new Node (arr[i]);
            last->next = temp ;
            last = last->next ;
            last->next = head ;            
        }
     }
           return head ;
}

Node *JosephusProblem ( Node *head  , int m )
{
   if ( head -> next = head )
   {
       return head ;
   }    

   Node *prev = head    ;

   for ( int i = 1 ; i < m-1 ; i ++ )
   { 
       prev = prev->next ;
   }
       Node *toDelete = prev->next ;
       prev->next = toDelete->next ;
       if (toDelete == head )
       {
          head = head->next ;  
       }
       delete toDelete ;
       return ( JosephusProblem(prev->next , m));
}

int main ( )
{
   int n , m ;
   cout << "Enter number of people: \n";
   cin >> n ;
   cout << "Enter position of person to killed: \n";
   cin >> m ;
   int arr [n] ;
   for ( int i = 0 ; i < n ; i++ )
   {
        arr[i] = i ;
   }
   Node *head = NULL ;
   head = insertAtEnd( head, arr , n ) ;
   head = JosephusProblem(head,m);
   cout << "Person Left: " << head->data  << endl ;
}