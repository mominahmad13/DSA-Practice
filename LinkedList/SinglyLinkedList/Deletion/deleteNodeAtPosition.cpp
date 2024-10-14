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

Node *deleteNodeAtPosition ( Node *head , int x )
{
    if ( x== 1 )
    {
        Node * temp = head ;
        head = head->next ;
        delete temp ;
        return head ;  // starting point address
    }
    else
    {
       x-- ; // go to x-1 th position 
       Node *prev = NULL;
       Node *curr = head ;
       while ( x-- )
       {
          prev = curr ;
          curr= curr->next ;           
       }

       prev->next = curr->next;
       delete curr ;

       return head ;  
    }
}

int  main ( )
{
    Node *head = NULL;
     
    int arr [] = {2,4,6,1,7} ;
    head = createLinkedList(arr,0,5);
    // after deleting node 
    head = deleteNodeAtPosition(head , 3);
   
    
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