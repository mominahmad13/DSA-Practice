#include <iostream>
using namespace std ;

class Node
{
    public :
    int data ;
    Node * link ;
    
    public: 
    Node( int d )
    {
       data = d; 
       link = NULL ; 
    }
   
};

Node *insertNode ( Node *head , int arr []  , int size )
{   
    Node * tail ;
    for ( int i = 0 ; i < size ; i++)
    {
       if ( head == NULL)
       {
         head = new Node (arr[i]) ;
         tail = head ;
       }
       else
       {
         tail->link = new Node(arr[i]);
         tail = tail->link;

       }
    }
         return head ;
}

void reversePrint( Node *head )
{
     if ( head == NULL )
    {
        cout << "List is empty";
        
    }

     Node *curr = head ;
     Node *last = NULL ;

   while ( last != head )
   {
     while ( curr-> link != last )
     {
        curr = curr->link ;
     }
        last = curr ;
        cout << last->data << " ";
        curr = head ; 
   }
        cout << endl ;
}

   

int main ( )
{
    int arr[5] = {1,3,5,7,9};
    Node *head = NULL; 
    head = insertNode(head , arr , 5 ) ;
    reversePrint(head);
}
