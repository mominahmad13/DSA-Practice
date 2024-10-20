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

    head = new Node (4);

    cout << head->data << endl ;

    return 0 ;
}
