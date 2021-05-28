#include <iostream>

using namespace std;


int* InsertionSort(int* ptr , int n){
int tmp /*, x =0*/;

int *arr = new int[n] ;
for(int i =0  ; i <n; i++){
    arr[i] =*ptr ;
    ptr++;

}
for(int i= 1; i<n ; i++){        // for 4 3 times

   if(arr[i-1]<arr[i]){
   continue ;

   }
   else{  // arr[i] > arr[i+1]

       for(int j = i ; j >0 ;j--){
           if(arr[j-1]<arr[j]){
               continue;
           }
              tmp  = arr[j-1] ;
              arr[j-1] = arr[j] ;
              arr[j] = tmp;
       }
   }
    

}

return arr;
}

int main(){
    int n ;
    cin>>n;
    int* arr = new int[n] ; // ignomre the error 

for(int i = 0; i<n ; i++){
    cin>>arr[i];
}
// sort[0]=  arr[0];

arr = InsertionSort(arr, n);

for(int  j =0 ; j < n ; j ++){
    cout<<arr[j] <<" ";
}
return 0;
}
