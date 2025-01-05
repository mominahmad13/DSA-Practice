#include <iostream>
using namespace std ;

class Node 
{
    public:
    int data ;
    Node * next ;

    Node ( int value )
    {
        data = value ;
        next = NULL ;
    }
}; 

Node  *insertAtEnd ( Node  * head  , int arr [ ] , int size )
{
    Node *tail = NULL;
    for ( int i  = 0 ; i < size ; i++ )
    {
      if ( head == NULL )
      {
         head = new Node (arr[i]);
         tail = head ;
      }
      else
      {
         tail->next = new Node(arr[i]);
         tail = tail->next ;
      }
  
    }

        return head ;
}

Node * swapNodes ( Node *head , int pos1 , int pos2 ,  int size )
{
    if ( pos1 == pos2 )
    {
        cout << "Swapping same Positions\n";
        return head ;
    }

    if ( pos1 > size )
    {
        cout <<pos1 << " is not a valid Position\n";
        return head ;
    }

    if ( pos2 > size )
    {
       cout <<pos2 << " is not a valid position\n";
       return head ;
    }

    Node *prev1 = NULL ;
    Node *prev2 = NULL;
    Node *Node1= head ;
    Node *Node2 = head ;
   
    int count  = 1 ;
   

   while ( pos1 > count && Node1 != NULL )
   {
       prev1 = Node1 ;
       Node1 = Node1->next ;
       count ++ ;
   }
       count = 1 ;

   while ( pos2 > count && Node2 != NULL )
   {
      prev2 = Node2 ;
      Node2 = Node2->next ;
      count ++ ;
   }
   
  
 
   // if  node 1 is not head 
   if ( prev1 != NULL )
   {
       prev1->next = Node2 ;
   }
   else // Node 1 is head 
   {
      head = Node2 ;
   }
   
   // if node2 is not head 
   if ( prev2 != NULL )
   {
       prev2->next = Node1 ;
   }
   else  // if node2 is head 
   {
      head = Node1 ;
   }

     Node *temp = Node1->next ;
     Node1->next = Node2->next ;
     Node2->next = temp ;

     return head ; 
}
void printList ( Node *head )
{
    Node * q = head ;

    while ( q!= NULL )
    {
        cout << q->data << " ";
        q = q->next ;
    }
}
int main ( )
{
   Node *head = NULL;
   int arr[8] = {1,2,3,4,5,6,7,8};
   head = insertAtEnd(head ,arr, 8);
   head = swapNodes( head , 3 , 9 , 8 );
   printList(head);
   cout << endl;
}