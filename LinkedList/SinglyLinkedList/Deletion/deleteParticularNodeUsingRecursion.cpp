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

Node *deleteNodeAtPositionRecursion ( Node *curr , int x )
{
    if ( x == 1 )
    {
        Node * temp = curr->next ; 
        delete curr ;
        return temp; ;  
    }
    
    curr-> next = deleteNodeAtPositionRecursion(curr->next ,x-1 );
    return curr ;
}

int  main ( )
{
    Node *head = NULL;
     
    int arr [] = {2,4,6,1,7} ;
    head = createLinkedList(arr,0,5);
    // after deleting node 
    head = deleteNodeAtPositionRecursion(head , 3);
   
    
    // print values
    
    Node *p = head;
    while( p != NULL)
    {
       cout << p->data <<" " ;
       p = p->next ;
    }
       cout << endl;

    return 0 ;


}