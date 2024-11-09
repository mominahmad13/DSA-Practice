#include <iostream>
using namespace std ;

class Node 
{
   public :
   int data ;
   Node *next ;

   Node(int value)
   {
      data = value ;
      next = NULL ;
   }
};

int main ( )
{
   Node *head = NULL ;
   head = new Node (4);
   head->next = head ;
   
}