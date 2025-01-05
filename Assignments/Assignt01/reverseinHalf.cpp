#include <iostream>
using namespace std ;

class Node
{
   public:
   int data ;
   Node * link ;

   Node ( int value )
   {
      data = value ;
      link = NULL ;
   }   
     
};

Node *insertAtEnd ( Node *head , int arr [] , int size )
{
    Node *tail = NULL;
    for ( int i = 0 ; i < size ; i ++ )
    {
      if ( head == NULL )
      {
         head = new Node(arr[i]);
         tail = head ;
      }
      else 
      {
         tail->link = new Node(arr[i]);
         tail = tail->link ;
      }
       
    } 
        return head ;

}
int length ( Node *head )
{
    int count = 0  ;

    Node *q = head ;

    while ( q!= NULL )
    {
        count = count + 1 ; 
        q = q->link ;
    }
        return count ;
}

Node *reverseList ( Node * head )
{
    Node *curr = head ;
    Node *next = NULL ;
    Node *prev = NULL ;

    while ( curr != NULL )
    {
        next = curr->link ;
        curr->link = prev ;
        prev = curr ;
        curr = next ;
    }
       head = prev ;
       return head ;
}

Node * swapHalf ( Node *head   )
{
   if ( head == NULL )
   {
     cout << "List is Empty\n";
     return head ;
   }

   int half = ( length(head) ) / 2 ;

   Node *firstHead  = head ;
   Node *secondHead = head ;
   Node *firstTail = NULL  ;
    
   while ( half -- )
   {
       firstTail = secondHead ;
       secondHead = secondHead->link ;
   }
      
      firstTail->link = NULL;
      firstHead = reverseList(firstHead);
      secondHead = reverseList(secondHead);

      Node *temp = firstHead ;
      while ( temp->link != NULL )
      {
          temp = temp->link ;
      }
      temp->link = secondHead ;
      return firstHead ;
       
}

void printList( Node *head )
{
    Node*q = head ;

    while ( q != NULL )
    {
        cout << q->data <<" ";
        q = q->link ;
    }
}
int main ( )
{
    Node *head = NULL; 
    int arr[8] = {1,2,3,4,5,6,7,8};
    head = insertAtEnd(head,arr,8);
    head = swapHalf(head);
    printList(head);
    cout << endl;
}