#include <iostream>

using namespace std ; 


int *SelectionSort(int* ptr , int n){
    int *arr = new int[n] ;
for(int i =0  ; i <n; i++){
    arr[i] =*ptr ;
    ptr++;

}
    int min  , tmp ;
int x =0 , y =0;
for(int  i  =0 ; i  < n-1  ; i ++) {
min  = arr[y];
x= y; 
    for(int  j =i ; j <n  ; j ++){
        
        if(arr[j]<min){
            x= j;
            min = arr[j];
        }
   
    } 

 tmp =  arr[y] ;
 arr[y] = min  ;
 y++ ;
 arr[x] = tmp ;
}
 return arr;
}


int main()

{
 int n ;
    cin>>n;
    int* arr = new int[n] ; // ignomre the error 

for(int i = 0; i<n ; i++){
    cin>>arr[i];
}

arr = SelectionSort(arr, n) ;

   

for(int i = 0; i<n ; i++){
   cout<<arr[i]<<" " ;
}


return 0;

}