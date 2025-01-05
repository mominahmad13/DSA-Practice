#include <iostream>
#include <vector>
using namespace std ; 

void Merge ( int arr [] , int start , int mid , int end ){
   
   vector <int> temp(end-start+1) ;
    int left = start ;
    int right = mid+1;
    int index = 0 ;

   while ( left <= mid && right <= end ){
      
      if ( arr[left] <= arr[right]){
          temp[index] = arr[left];
          index ++;
          left++;
      }
      else{
         temp[index] = arr[right];
         index++;
         right++;
      }
   }

   // copy any element left in left array

   while ( left <=mid ){
      
      temp[index] = arr[left];
      left ++ ;
      index++ ;
   }

   // copy any element left in right array

   while ( right <= end ){

     temp[index] = arr[right];
     right ++ ;
     index ++ ;

   }
   index = 0 ;

   // copy sorted vector to original array

   while ( start <= end ){

      arr[start] = temp[index];
      start++ ;
      index++;
   }
}

void MergeSort ( int arr[] , int start , int end ){

  if ( start == end )
     return ;

  int mid = start + ( end - start) / 2 ;

  MergeSort ( arr , start , mid ) ;
  MergeSort ( arr , mid+1 , end );
  Merge ( arr , start , mid , end );
}



int main ( ){
    
    int arr[10] = {1,8,3,9,4,0,7,6,2,5};

    MergeSort(arr,0,9);
    
    cout << "Sorted Array: \n";

    for ( int i = 0 ; i <10 ; i++ ){
         
         cout << arr[i] << " " ;
    }

    cout << endl;

    return 0 ;
}