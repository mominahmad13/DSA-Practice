#include <iostream>
#include <cstring>
using namespace std ;

int josephusProblem ( int arr [] , int n , int index , int k , int personLeft )
{
   if ( personLeft == 1 )
   {
      for ( int i = 0 ; i < n ; i ++ )
      {
         if ( arr[i] == 0 )
         {
             return i ;
         }
      }
   }  

   int kill = (k-1) % personLeft;
     
   while ( kill -- )
   {
        index = (index + 1 ) % n ;
        while ( arr[index] == 1 )
        {
            index = ( index + 1 ) % n ;
        }
   }
        arr[index] = 1 ; // person killed
    
        
        while ( arr[index] == 1 )
        {
            index = ( index + 1 ) % n ;
        }

        return josephusProblem(arr,n ,index , k , personLeft - 1 );
}  


 
int main ()
{
    int size , k , personLeft ;
    cout << "Enter size : ";
    cin >> size ;
    int * arr = new int [size] ;
    memset(arr,0,sizeof(arr));
    personLeft = size ;
    cout << "Enter position to be killed: ";
    cin >> k ;
    int killed = josephusProblem(arr,size,0,k,personLeft);
    cout << "Winner: "<< killed << endl ;
}

