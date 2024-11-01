#include<iostream>
using namespace std ;

class Node
{
   public:
   int data ;
   Node *next ;

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

Node * swapPairwise ( Node *head )
{
    int swap = 0 ;
    Node * curr  = head ;
    Node * prev = NULL;
    while ( curr !=  NULL && curr->next !=NULL )
    {
        prev = curr ;
        curr = curr-> next ;
        swap = curr->data ;
        curr->data = prev->data ;
        prev->data = swap ; 
        curr = curr->next;
    }
        return head ;

}

int main ( )
{
    Node * head = NULL;
    int arr [5] = {1,2,3,4,5};
    head = insertNode(head,arr,5);
    head = swapPairwise(head);

    Node *q = head ;

    while ( q != NULL)
    {
        cout << q->data << " " ;
        q = q->next ;
    }
        cout << endl;
}    