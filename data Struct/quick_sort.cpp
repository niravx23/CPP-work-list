#include <iostream>
using namespace std ; 
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



 void  QuickSort(int arr[], int low , int high ){
 
   int part =   partition(arr , low , high );
   
   if(low<high){
       
        QuickSort(arr, low, part-1);
        QuickSort(arr, part+1, high);

   }
 
  
 }



int main()

{
    int n ; 

cin>>n;
int arr[n] ; 

for(int i= 0 ;  i < n ; i++){
    cin>>arr[i]; 
}

QuickSort(arr, 0 , n-1);


for(int i= 0 ;  i < n ; i++){
    cout<<arr[i]<<" " ;
}
return 0;

}
