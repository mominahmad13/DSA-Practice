#include <iostream>
using namespace std;


class SinglyLinkedList 
{
    struct Node 
   {
     int data ;
     Node *next ; 

     Node ( int value )
      {
        data = value ;
        next = NULL;
      }
  }*head;
  
  public :
  SinglyLinkedList( )
  {  
     head = NULL;
  }
  

  public:
  void insertAtBegin();
  void insertAtEnd();
  void insertAtPos( int , int  );
  void deleteAtBegin();
  void deleteAtEnd();
  void deleteAtPos(int);
  void deleteFromValue (int);
  void search (int);
  void length();
  void Max();
  void Min();
  void display ( );
};


void SinglyLinkedList :: insertAtBegin ( )
{
    int num ;
    cout <<"Enter value to be inserted in start \n";
    cin >> num ;
    Node *newNode = new Node(num);

    if ( head == NULL )
    {
        head = newNode;
    }
    else
    {
       newNode->next = head ;
       head = newNode;
    }
}

void SinglyLinkedList :: insertAtEnd ( )
{
    int num ; 
    cout << "Enter value to be inserted in end \n";
    cin >> num ;
    Node *newNode = new Node (num);

    if ( head == NULL)
    {
        head = newNode ;
    }
    else
    {
        Node *tail= head;

        while ( tail->next != NULL)
        {
             tail = tail->next;
        }
        
         tail->next = newNode;
         
    }
}

void SinglyLinkedList :: insertAtPos ( int pos , int num )
{   
    if ( head == NULL )
    {
        cout << "List not exist\n";
        return ;
    }
    if ( pos < 1 )
    {
        cout <<" Invalid Position\n";
        return ;
    }
    else if ( pos == 1 )
    {
         Node *newNode = new Node (num);
         newNode->next =  head ;
         head = newNode;
         return ;
    }
    
    Node *temp = head ;
    int count = 1 ; 

     //  check that position given  should not exceed the length of list
     // Also  pos where node is inserted is pos - 1    
    while ( count < pos - 1 && temp!=NULL ) 
    {
        temp = temp->next;
        count++;
    }
    if ( temp == NULL )
    {
        cout << "Position is out of bound\n"; 
        cout << endl;
        return ;
    }

    Node *newNode = new Node(num);    
    newNode->next = temp->next;
    temp->next = newNode;
}


void SinglyLinkedList :: deleteAtBegin ( )
{
    if ( head == NULL )
    {
        cout << "list not exist\n";
        return ;
    }

    else{
       Node *temp = head ;
       head = head->next ;
       delete temp ; 
    }
}

void SinglyLinkedList :: deleteAtEnd ( )
{
    if ( head == NULL )
    {
        cout<< "list not exist\n" ;
        return ;
    }

    if ( head ->next == NULL) // Only one node exist
    {
       Node *temp = head ;
       head = NULL;
       delete temp ;
       return ;
    }
        Node *curr = head ;
        Node *prev = NULL;
        while ( curr-> next != NULL)
        {
             prev = curr ;
             curr = curr->next ;            
        }
             delete curr;
             prev->next = NULL;            
    

}

void SinglyLinkedList:: deleteAtPos ( int pos )
{
    if ( head == NULL )
    {
        cout << " list not exist \n";
        return ;
    }
    if ( pos < 1  )
    {
        cout << "Invalid position \n";
        return ;
    }

    else if ( pos == 1 ) 
    {
        Node * temp = head ;
        head = head->next ;
        delete temp ;
        return ;
    }
    
    Node *prev = NULL ;
    Node *curr = head ;
    
    int count = 1 ;

    while ( count < pos  &&  curr != NULL ) // delete at that exactly position
    {   
         prev = curr ;
         curr = curr-> next ; 
         count++; 
    }

    if ( curr == NULL )
    {
        cout << "Position out of bound \n ";
        return ;
    }

    prev->next = curr->next ;
    delete curr ;
} 

void SinglyLinkedList :: deleteFromValue ( int val )
{
    if ( head == NULL)
    {
        cout << "list not exist\n";
        return ;
    }
     
    if ( head->data == val )
     {
         deleteAtBegin();
         return ;
     }

        Node *curr = head;
        Node *prev = NULL;

        while ( curr != NULL )
        {
          if ( curr->data == val )
          {
             prev->next = curr->next;
             delete curr ;
             return ;
          }
            prev = curr ;
            curr = curr->next ;
        } 
           cout <<"Number not in list\n";

}
    

void SinglyLinkedList :: search( int x )
{
  
    int pos = 0;
    Node *temp = head ;
    if ( head == NULL)
    {
        cout << "list not exist\n";
        return ;
    }

    while ( temp !=NULL )
    {
        if ( temp->data == x )
        {
            cout << "Number found at position\n"<< pos+1;
            return ;
        }
        else
        {
            temp = temp->next;
            pos++;
        }
       
    } 
       cout << "Number not found\n ";
            
} 

void SinglyLinkedList :: length ()
{
    int length = 0 ;
    if ( head == NULL )
    {
        cout << " list not exist \n";
        return ;
    }
    Node *temp = head ;
    while ( temp!=NULL )
    {   
        length ++;
        temp = temp->next;
    }
    cout <<"total nodes are: "<<length; 


}

void SinglyLinkedList :: Max ()
{  
   int max = head->data ;
   if ( head == NULL )
   {
     cout << "list not exist";
     return ;
   }

   Node *temp = head ;

   while ( temp != NULL )
   {
      if ( temp->data > max )
      {
          max = temp->data;
      }
      temp = temp->next;
   }
     cout << "Max value in node is:" << max <<endl;
    
}

void SinglyLinkedList :: Min ()
{  
   int min = head->data ;
   if ( head == NULL )
   {
     cout << "list not exist";
     return ;
   }

   Node *temp = head ;

   while ( temp != NULL )
   {
      if ( temp->data < min )
      {
          min = temp->data;
      }
      temp = temp->next;
   }
    cout << "Min value in node is:" << min << endl;
    
}

void SinglyLinkedList :: display ( )
{
     Node *temp = head ;

     while ( temp!=NULL )
     {
         cout << temp->data << " " ;
         temp = temp->next ;
     }   
         cout << endl ;       
}



int main ( )
{   

    SinglyLinkedList s ;
    int choice ;

  do 
  {

    cout<< "Menu Program for Singly Linked List\n";
    cout << "-----------\n" <<endl;
    cout << "0: STOP/n" << endl;
    cout << "1: Insert Node at Beginning\n";
    cout << "2: Insert Node at End:\n";
    cout << "3: Insert Node At specific position:\n";
    cout << "4: Delete Node At Start:\n";
    cout << "5: Delete Node At End:\n";
    cout << "6: Delete Node At specific position:\n";
    cout << "7: Delete a value in a Node:\n";
    cout << "8: search element in Node:\n";
    cout << "9: Find length of Node:\n";
    cout << "10: Find Max number in whole Linked List:\n";
    cout << "11:Find Min number in whole Linked List:\n";
    cout << "12: Display list:\n";
    
    cout <<"Enter choice: ";

    cin >> choice ;
    
    
    switch ( choice )
    {
        case 0 :
                 cout << "Program stopped" << endl;
                 break ;
                 
        case 1 : 
                 s.insertAtBegin();
                 break ;
        case 2 : 
                 s.insertAtEnd();
                 break ;
        case 3 :
                 int posToInsert ;
                 int X;
                 cout <<"Enter number:\n";
                 cin >> X ;
                 cout << "Enter position:\n";
                 cin >> posToInsert ;
                 s.insertAtPos( posToInsert , X ); 
                 break ;
       case 4 :
                 s.deleteAtBegin();
                 break ;
       case 5 : 
                 s.deleteAtEnd();
                 break ;
       case 6 :
                 int posToDelete ;
                 cout << "Enter position:\n";
                 cin >> posToDelete ;
                 s.deleteAtPos(posToDelete);
                 break ;
       case 7 :
                 int value ;
                 cout << "Enter value";
                 cin >> value ;
                 s.deleteFromValue(value);
                 break ;  
       case 8 : 
                int x; 
                cout <<"Enter number:\n";
                cin >> x ;
                s.search(x);
                break ;
       case 9 :
                s.length();
                break ;
       case 10:
                s.Max();
                break ;
       case 11: 
                s.Min();
                break ;
       case 12:
                s.display( );                  
                break ;
       default:
                cout << "Invalid Choice\n";   
                break ;      
    }  
       cout << endl;
   }  while ( choice != 0) ;
    
    return 0 ;
}

