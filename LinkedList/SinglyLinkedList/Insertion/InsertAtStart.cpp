#include <iostream>
using namespace std ;

class Node
{
    public:
    int data;
    Node *next;
    Node *head;
    
    Node ( int value )
    {
        data = value;
        next = NULL;
    }
};

int main ( )
{
    
    Node *head;
    head = NULL;
    //cout << head->data << endl;
   // cout << head->next << endl;

    int arr [] = {2,4,6,8,10};

    for ( int i = 0 ; i<5 ; i++)
    {

      if ( head == NULL )
       {
         head = new Node(arr[i]);
       }
      else
       {
        Node *temp;
        temp = new Node (arr[i]);
        temp->next = head;
        head = temp;
       }

    }

    // print the values

    Node * p = head;
    while ( p != NULL ) // Or simple (p)
    { 
       cout << p->data << " " ;
       p = p->next; 
    }
       cout<<endl;

}