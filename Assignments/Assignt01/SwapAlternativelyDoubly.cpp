#include <iostream>
using namespace std ;

class Node 
{
    public: 
    int data ;
    Node * next ;
    Node *prev ;

    Node ( int value )
    {
        data = value ;
        next = NULL ;
        prev = NULL ;
    }

};

Node *insertAtEnd ( Node *head , int arr[] , int size )
{
    Node * tail = NULL ;
    for ( int i = 0 ; i < size ; i++ )
    {
         if ( head == NULL )
         {
             head = new Node ( arr[i] ) ; 
             tail = head ;
         }

         else 
         {
             tail->next = new Node (arr[i]);
             tail->next->prev = tail ;
             tail = tail->next;
         }
    }
            return head ;
}

Node * swapAlternate ( Node * head )
{
    if ( head == NULL )
    {
        cout << "List is Empty\n";
        return head ;
    }
    if ( head->next == NULL )
    {
        cout <<"List has one Node\n";
        return head ;
    }

    Node *front = head->next ;
    Node *back = head ;

    while ( back->next->next!=NULL )
    {
        back = back->next;
    }
    
    while ( front!= NULL && back!=NULL && back!=front &&  front->next )
    {
         Node *temp1 = back->next;
         Node *temp2 = back->prev ;
         Node *temp3 = NULL ;
         back->next = front->next ;
         back->prev = front->prev ;
         back->prev->next = back ;
         back->next->prev = back ;

         front->next = temp1 ;
         front->prev = temp2 ;

         front->prev->next = front ;
         front->next->prev = front ;
          
         temp3 = front ;
         front = back ; 
         back = temp3 ;
         front = front->next->next ;
         back = back->prev->prev;
    }

         return head ;
}

void printList ( Node * head )
{
   Node *q = head ;

   while ( q!=NULL )
   {
       cout << q->data << " ";
       q = q->next ;
   }
}

int main ( )
{
   Node *head = NULL ;
   int arr[9] = {1,2,3,4,5,6,7,8,9};
   head = insertAtEnd( head , arr , 9 );
   head = swapAlternate(head);
   printList(head);
   cout << endl;

}