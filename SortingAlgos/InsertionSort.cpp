#include <iostream>
using namespace std;

void InsertionSort ( int arr[], int size ){

 for ( int i = 1 ; i < size ; i ++ ){
  
  for ( int j = i ; j > 0 ; j-- ){
     
     if ( arr[j] < arr[j-1] ){
        swap(arr[j], arr[j-1] );
     }
     else{
         break;
     }
  }
 } 

}

int main ( ) {
  
  int arr[10] = {1,8,3,9,4,0,7,6,2,5};

  InsertionSort(arr,10);
  cout << "Sorted Array: \n";

    for ( int i = 0 ; i <10 ; i++ ){
         
         cout << arr[i] << " " ;
    }

    cout << endl ;

  return 0 ;
}