#include <iostream> 
#include <map> 
using namespace std ;


 unsigned long long  fib(int n){

  static  map <int, unsigned long long > fibs ;
 
    
    if(n==1 ||n==2 || n==0) 
{     return  1;
 }

   else if(fibs.count(n))
 {
     auto it = fibs.find(n) ;
     return it->second;
 }
 
else{

fibs.insert(pair<int, unsigned long long >(n, fib(n-1)+fib(n-2))) ;
auto it = fibs.find(n) ;
return it->second ;

}

}

int main(){
    
int n;
cin>>n; 
cout<<fib(n);
return 0;
}

