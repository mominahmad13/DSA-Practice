#include <iostream>
using namespace std ;

int Partition ( int arr[] , int start , int end ){

  int pos = start ;

  for ( int i = start ; i <= end ; i++ ){

    if ( arr[i] <= arr[end]){
        swap( arr[i] , arr[pos]);
        pos++;
    }
  }
       return pos-1;
}

void QuickSort ( int arr[] , int start , int end ) {

   if ( start >= end )
     return ;

   int pivot = Partition ( arr, start , end );  
   QuickSort ( arr, start , pivot-1 );
   QuickSort( arr , pivot+1 , end ) ;
}

int main () {

    int arr[] = {10,3,4,1,5,6,3,2,11,9};

    QuickSort( arr, 0 , 9);
    cout << "Sorted Array: \n";

    for ( int i = 0 ; i < 10 ; i++ ){
         
         cout << arr[i] << " " ;
    }

    cout << endl ;

    return 0 ;
}