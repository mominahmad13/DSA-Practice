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

Node * createLinkedList ( int arr [ ] , int index , int size )
{
    // Base case
    if ( index == size )
    {
        return NULL;
    }

    
    Node*temp = new Node(arr[index]);
    temp->next = createLinkedList( arr , index+1 , size );
    return temp;
        

}

int  main ( )
{
    Node *head = NULL;
     
    int arr [] = {2,4,6,8,10};
    head = createLinkedList(arr,0,5);
    
    Node *temp = head;
    while( temp != NULL)
    {
       cout << temp->data <<" " ;
       temp = temp->next ;
    }
       cout << endl;

    return 0 ;


}