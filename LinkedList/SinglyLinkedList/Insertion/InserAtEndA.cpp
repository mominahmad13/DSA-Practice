#include <iostream>
using namespace std;

class Node
{
    public:
    int data ;
    Node *next;
    
    Node ( int value )
    {
        data = value ;
        next = NULL;
    }
    
};

int main ( )
{
    Node *head = NULL;
    Node *tail = NULL;

    int arr [] = {2,4,6,8,10};
    for( int i = 0 ; i <5 ; i++)
    {

      if ( head == NULL )
      {
         head = new Node(arr[i]) ;
         tail = head;
      }
      else
      {
         tail->next = new Node (arr[i]);
         tail = tail->next;
      }

    }

    Node *temp = head;
    while( temp != NULL)
    {
       cout << temp->data <<" " ;
       temp = temp->next ;
    }
       cout << endl;

    return 0 ;


}