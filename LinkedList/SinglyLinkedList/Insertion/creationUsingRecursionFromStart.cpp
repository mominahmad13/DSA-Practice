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

Node * createLinkedList ( int arr [ ] , int index , int size , Node *prev )
{
    // Base case
    if ( index == size )
    {
        return prev ; 
    }

    Node *temp = new Node ( arr[index] );
    temp->next = prev ;
    return createLinkedList( arr , index+1 , size , temp );

}

int  main ( )
{
    Node *head = NULL; 

    int arr [] = {2,4,6,8,10};


    head = createLinkedList(arr,0,5,NULL);
    
    //print the value
    Node *temp = head;

    while( temp != NULL)
    {
       cout << temp->data <<" " ;
       temp = temp->next ;
    }
       cout << endl;

    return 0 ;


}