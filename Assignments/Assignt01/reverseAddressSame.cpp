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
         tail->link= new Node(arr[i]);
         tail = tail->link;

       }
    }
         return head ;
}

Node * reverseList ( Node *head )
{
    if ( head == NULL )
    {
        cout << "list is empty ";
        return 0 ;
    }
    else if ( head->link == NULL )
    {
        cout << " Only one Node Present ";
        return 0 ;
    }
    else
    {
      Node *curr = head ;
      Node * prev = NULL ;
      Node *next = NULL ;
      
     while ( curr != NULL )
       {
          next = curr->link ;
          curr->link = prev ;
          prev = curr ;
          curr = next ;
       } 
          head = prev ;
         
    }
         return head ;
}

   

int main ( )
{
    int arr[5] = {1,3,5,7,9};
    Node *head = NULL; 
    head = insertNode(head , arr , 5 ) ;
    head = reverseList(head);
    Node *q  = head ;
    while ( q  != NULL )
    {
       cout << q->data << " " ;
       q = q->link ;
    }
         cout << endl ;
}
