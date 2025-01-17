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

Node *createDLL( int arr[ ] , int size , int index , Node *back )
{
    
    if ( index == size )
      return NULL;
    
    Node *temp = new Node(arr[index]);
    temp->prev = back ;
    temp->next = createDLL(arr,size,index+1,temp);
    return temp ;

}

int main ( )
{
    Node *head = NULL;
    
    int arr [ ] = {1,2,3,4,5};
    head = createDLL(arr,5,0,NULL);
    Node *p = head ;
    while ( p != NULL )
    {
        cout << p->data << " " ;
        p = p->next ;
    }
        cout << endl ;

    return 0 ;
}
