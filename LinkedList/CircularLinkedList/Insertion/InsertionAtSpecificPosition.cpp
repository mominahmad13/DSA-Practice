#include <iostream>
using namespace std ;

class Node
{
   public :
   int data ;
   Node * next ;
   
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

Node *InsertAtPos ( Node * head , int pos , int x  , int size )
{
    if ( head == NULL )
    {
        cout << "Node is Empty/n";
        return NULL ;
    }
    if ( pos < 1 )
    {
        cout << "Invalid Position/n";
        return head ;
    }
    if ( pos > size )
    {
        cout << "Position Out of Bound/n";
        return head ;
    }

    Node *last = head ;

    // first Node
    if ( pos == 1 )
    {
        while ( last -> next != head )
        {
           last = last -> next ;
        } 

        Node *temp = new Node(x);
        temp ->next = head ;
        last->next = temp ;
        head = temp ;
        return head  ;
    }
    else 
    {
       Node *temp = new Node (x) ;
       Node *curr = head ;
       Node *prev = NULL;
       pos = pos - 1  ;
       while (pos -- )
       {
           prev = curr ;
          curr = curr->next ;
       }
       temp->next = curr ;
       prev->next = temp ;
       return head ;

    }
}
int main ( )
{
    int arr[5] = {0,2,4,6,8};
    Node *head = NULL;
    head = insertAtEnd (head , arr , 5 );
    head = InsertAtPos(head , -1 , 3, 5 );

    Node *q = head ;

    while ( q->next != head )
    {
        cout << q->data << " ";
        q = q-> next ;
    }   
        cout << q->data ;
        cout << endl ;
} 