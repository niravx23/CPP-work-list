#include <iostream>

using namespace std ; 

void  merge(int arr[ ] , int low  , int mid , int high ){
  
    int part1  =  mid ;
     
    int x= low , temp;
    int y = mid+1;
      
    while(x<=high && y<=high){
        if(arr[x]>arr[y] ){
           temp =  arr[x] ;
           arr[x] = arr[y] ;
           arr[y] = temp;
           x++;
        }
        else{
            y++;
        }
        }


}
void mergeSort(int arr[ ] ,int low , int high ){

    if(low<high){
        int mid  = (low+high)/2 ;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1,high);
        merge(arr, low , mid, high );

    }
}

int main()

{

   int n ;
    cin>>n;
    int* arr = new int[n] ; // ignomre the error 

for(int i = 0; i<n ; i++){
    cin>>arr[i];
}


mergeSort(arr, 0 , n-1) ;


for(int i = 0; i<n ; i++){
   cout<<arr[i];
}

return 0;

}