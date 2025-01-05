#include <iostream>
using namespace std ;

bool BinarySearch ( int arr[] , int start , int end , int x ){

    if ( end >= start ){

        int mid = start + (end-start)/2;

        if ( arr[mid] == x ){
            return true ;
        }
       
       if ( arr[mid] > x ){
          return BinarySearch( arr ,start , end-1 , x);
       }
       
       if (arr[mid] < x ){
         return BinarySearch ( arr,mid+1,end ,x);
       }          
         
    }
        return false ;
        
}
      

int main ( ) {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    if ( BinarySearch(arr,0,9,7) ){
        cout <<"Element found\n";
    }
    else{
        cout<<"Not Found\n";
    }
    return 0 ;
}