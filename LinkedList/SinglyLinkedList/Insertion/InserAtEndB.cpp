#include <iostream>
using namespace std;

class Node
{
   public:
   int data ;
   Node *next ;

   Node ( int value )
   {
       data = value ;
       next = NULL;  
   }

};
int main ( )
{
     Node *head = NULL;

     int arr[ ] ={2,4,6,8,10};

     for ( int i = 0 ; i < 5 ; i++ )
     {
         if ( head == NULL )
         {
            head = new Node ( arr[i] );
         }
         else
         {
            Node *tail = head;
            while ( tail->next != NULL)
            {
                tail = tail->next;
            }
            Node *temp = new Node (arr[i]);
            tail->next = temp ;
         }
     }
      Node *p = head;
      while ( p != NULL )
      {
          cout << p->data << " ";
          p = p->next;
      }
          cout << endl;


    return 0;
}