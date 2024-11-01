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
Node* removeDuplicate(Node* head) {
    Node *curr = head;
    
    while (curr != NULL && curr->next != NULL) {
        Node* temp = curr;
        
        while (temp->next != NULL) 
        {
            if (curr->data == temp->next->data) 
            {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
             else
            {
                temp = temp->next;
            }
        }
        
        curr = curr->next;
    }
    return head ;
}
int main ( )
{
    Node *head = NULL;
    int arr[10] = {1,3,2,3,5,5,4,6,7,6};
    head = insertNode ( head , arr ,10 );
    head = removeDuplicate(head);

    Node *q = head ;

    while ( q != NULL )
    {
        cout << q->data ;
        q = q->next ;
    }
        cout << endl ;
}