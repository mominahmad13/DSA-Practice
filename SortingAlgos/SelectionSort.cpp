#include <iostream>
using namespace std;

void SelectionSort ( int arr[] , int size ) {
   
   int index;
   for ( int i = 0 ; i < size - 1 ; i++ ){
        index = i ;
     for ( int j = i + 1 ; j < size ; j++ ){
         
        if ( arr[j] < arr[index]) {
           
            index = j;
        }
     }
         swap ( arr[index] , arr[i]) ;
   }
}

int main (){

    int arr[10] = {1,8,3,9,4,0,7,6,2,5};

    SelectionSort(arr,10);
    cout << "Sorted Array: \n";

    for ( int i = 0 ; i <10 ; i++ ){
         
         cout << arr[i] << " " ;
    }

    cout << endl ;

   return 0 ;
}

