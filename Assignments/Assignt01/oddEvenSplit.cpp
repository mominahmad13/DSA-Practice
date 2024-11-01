#include <iostream>
using namespace std ;

class Node
{
   public :
   int data ;
   Node * next ;

   public :
   Node (int d)
   {
      data = d ;
      next = NULL;
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
         tail->next= new Node(arr[i]);
         tail = tail->next;

       }
    }
         return head ;
}

void splitList (Node* head , Node* &evenHead ,Node * &oddHead )
{
    Node *temp = head ;
    Node *evenTail = NULL;
    Node *oddTail =NULL;
    while ( temp != NULL )
    {
        if ( temp->data % 2 == 0  )
        {   
            if ( evenHead == NULL )
            {
                evenHead = temp ;
                evenTail = evenHead ;
            }
            else 
            {
                evenTail->next = temp ;
                evenTail = evenTail->next;
            }
        }
        if ( temp->data % 2 != 0  )
        {   
            if ( oddHead == NULL )
            {
                oddHead = temp ;
                oddTail = oddHead ;
            }
            else 
            {
                oddTail->next = temp ;
                oddTail = oddTail->next;
            }
        }
         temp = temp->next ;
    }

    if (evenTail != NULL) {
        evenTail->next = NULL;
    }
    if (oddTail != NULL) {
        oddTail->next = NULL;
    }
}

void printList(Node *head )
{
    Node *q = head ;

    while ( q != NULL )
    {
        cout << q->data << " ";
        q = q->next ;
    }
         cout << endl ;
}    

int main ( )
{
    Node *head = NULL;
    int arr[8] = {1,2,4,6,3,5,7,9};
    head = insertNode(head ,arr,8);
    Node *evenHead = NULL; 
    Node *oddHead = NULL;
    splitList(head , evenHead , oddHead );
    printList(evenHead);
    printList(oddHead);

}