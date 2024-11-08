#include <iostream>
using namespace std ;

int JosephusProblem ( int n , int k)
{
    if ( n == 1 )
    {
       return 0 ;
    }
    return ( JosephusProblem(n-1,k)+k ) % n ;
}
int main ( )
{
   int n , k ;
   cout << "Enter n: ";
   cin >> n ;
   cout << "Enter k : ";
   cin >> k ;
   int win = JosephusProblem(n,k);
   cout << "Person Left: " << win + 1  << endl ;

}