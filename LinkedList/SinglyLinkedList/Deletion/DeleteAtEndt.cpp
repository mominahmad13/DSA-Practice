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
     
    int arr [] = {2,4,6,1,7} ;
    head = createLinkedList(arr,0,5);
    
    // delete a node
    if ( head == NULL )
    {
        cout << "List is not present";
    }
    if ( head != NULL )
    {  
        // one node is present 
         if ( head->next == NULL)
         {
             Node *temp = head ;
             head = NULL;
             delete temp ;
        }
        // More than one Node Present
        else
        {
            Node * curr = head ;
            Node *prev = NULL ;

            while ( curr->next != NULL)
            {
                prev = curr ;
                curr = curr->next;
            }
                delete curr ;
                prev->next =NULL;
        }
    }

    
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