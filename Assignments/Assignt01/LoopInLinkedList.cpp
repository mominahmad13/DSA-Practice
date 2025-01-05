#include <iostream>
using namespace std ;

class Node 
{
   public : 
   int data ;
   Node * next ;

   Node ( int value )
   {
      data = value ;
      next = NULL;
   }
};

// create linked list with loop 
Node *createLinkedList ( Node *head )
{
     head = new Node(1);
     Node *newNode = head ;
     for ( int i = 2 ; i <= 4 ; i++ )
     {
         newNode->next = new Node (i);
         newNode = newNode -> next ;
     }
     // Adding loop  
     Node *loopPoint = newNode ;  // pointer to Node 4
     for ( int i = 5 ; i <= 7 ; i++)
     {
         newNode->next = new Node(i);
         newNode = newNode -> next ;
     }
        newNode->next = loopPoint ;

        return head ;
}    

bool loopExists ( Node *head )
{
    Node * fast = head;
    Node * slow = head;

    while ( fast != NULL && fast-> next != NULL)
    {
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if ( slow == fast )
        {
            return true ;
        }

    }  
           return false ;
}

int main ( )
{
     Node *head = NULL;
     head = createLinkedList(head);
     if ( loopExists(head) )
     {
        cout << "Loop exist\n";
     }
     else
     {
         cout << "Loop not exists\n";
     }
}