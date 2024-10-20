#include <iostream>
using namespace std;

class Node 
{
    public:
    int data ;
    Node *prev ;
    Node *next ;

    Node ( int value )
    {
       data = value ;
       next = prev = NULL;
    }

};

int main ( )
{
    Node *head = NULL;

    int arr [ ] = {2,4,6,8};

    for  ( int i = 0 ; i < 4 ; i++)
    {
     if ( head == NULL )
     {
        head = new Node (arr[i]);
     }
     else
     {
       Node *temp = new Node (arr[i]);
       temp->next = head ;
       head->prev = temp;
       head = temp ;

     }
    }
    
    Node *p = head ;
    while ( p != NULL )
    {
        cout << p->data << " " ;
        p = p->next ;
    }
        cout << endl ;
    return 0 ;
}
