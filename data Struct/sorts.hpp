#include <iostream>


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

namespace Qsort{
void  QuickSort(int arr[], int low , int high ){
 
   int part =   partition(arr , low , high );
   
   if(low<high){
       
        QuickSort(arr, low, part-1);
        QuickSort(arr, part+1, high);

   }
 
  
 }
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;           //2 5 6
    int j = high;
    int temp;

    
    while(i<=j){

        while(pivot >= arr[i] && i <=high){
            i++ ;
        }
         while(pivot < arr[j] && j>=low){
            j-- ;
        }
        if(j>i && i<= high  && j >=low){
            temp = arr[i] ;
            arr[i]=  arr[j] ;
            arr[j] = temp ;
        }
    }

        if(j>= low)
         { temp  = arr[j]  ;
           arr[j] = arr[low]  ;
           arr[low] =  temp ;
         }
        return  j ;
}

}