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
    int x = 3 ;
    int value = 30 ;
    Node *temp = head;
    x--;
    while(x--)
    {
        temp = temp->next;
    }
     Node * temp2 = new Node(value);
     temp2->next = temp->next;
     temp->next = temp2;

    
    //Print values
    Node  *p = head;
    while( p != NULL)
    {
       cout << p -> data <<" " ;
       p = p -> next ;
    }
       cout << endl;

    return 0 ;


}