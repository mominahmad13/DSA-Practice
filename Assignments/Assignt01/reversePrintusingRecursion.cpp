#include <iostream>
using namespace std ;

class Node
{
    public :
    int data ;
    Node * next ;
    
    public: 
    Node( int d )
    {
       data = d; 
       next = NULL ; 
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
         tail->next  = new Node(arr[i]);
         tail = tail->next;

       }
    }
         return head ;
}

void reversePrintRecursion( Node *curr )
{
    if ( curr == NULL )
       return ;

    reversePrintRecursion(curr->next);
    cout << curr->data << " ";

   
}

   

int main ( )
{
    int arr[5] = {1,3,5,7,9};
    Node *head = NULL; 
    head  = insertNode(head , arr , 5 ) ;
    reversePrintRecursion(head);
    cout << endl ;
}
