#include <iostream>
using namespace std;

void BubbleSort ( int arr[] , int size ){

    for ( int i = size-2  ; i >= 0 ; i--) {
         
         bool swapped = false ;
        for ( int j = 0 ; j <= i ; j++){
          
           

           if ( arr[j] > arr[j+1] ){

               swap( arr[j], arr[j+1]);
               swapped = true ;
           } 
        }

        if ( !swapped ) // if no swap occur in any iteration means array is sorted
           break;
       
    }
}

int main (){

    int arr[10] = {1,8,3,9,4,0,7,6,2,5};

    BubbleSort(arr,10);
    cout << "Sorted Array: \n";

    for ( int i = 0 ; i <10 ; i++ ){
         
         cout << arr[i] << " " ;
    }

    cout << endl ;

   return 0 ;
}