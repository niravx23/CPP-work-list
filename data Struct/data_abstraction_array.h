/*
this is array acting like a vector . You can access the array , read , add and modify . 
 * To include this in cpp file use ----> #include "data_abstraction_array.h" ; 
 1) To inititate the array --> creat_arr("name_array",total_size_assinged, actual_size_used) ;
  !-- > keep assinged size more than actual_size_used , to enter more data when needed in future;
 2) When using set_data : 
 for int values enter :(for eg):- 1 2 3 4 ... n (n ==  used_size)
 3)get_data method prints the entire arr upto used_space .



//             IN PROGRESS WORK !!!!!                    //
*/
#ifndef data_abstraction_array                     
#define data_abstraction_array

#include <iostream>
#define check  1
using namespace std ; 

template<class T>
class creat_arr{ 

int used_size , size_allocated   ;
public : int *ptr ;

creat_arr(int a1, int a2 ):size_allocated(a1),used_size(a2) {
    if(a1<a2){ 
        
                 #ifdef check
                 check =  0  ;
                 #endif 
      
    }
    else  
     ptr = new T[size_allocated] ;
}
~creat_arr(){

cout<<"created entity deleted !" <<endl;
    
}

int* pointer(){
    return ptr ;
}
int usize(){
    return used_size ;
}  

int alloc_size() { 
    return size_allocated ;
}

 void set_data(){
     if(!check)
     {
         ~creat_arr();
     }
     else
   {  T tmp ; 
 for(int i= 0; i<used_size ;i ++){
     cin>>tmp ;
     ptr[i] = tmp ; }
 }
 }
void pb(T a){ 
    if(used_size==size_allocated)
    cout<<"ARRAY LIMIT REACHED !" ;
    else
{ ptr[used_size] = a;
 used_size++ ;}
}
void insert_and_sort(T a){
    pb(a) ;
    sort();
}
void delete_element_all_occurence(T a ){
 

    for(int i= used_size-1; i >=0 ;i --){
        if(ptr[i]== a){
                 
           for(int m = i;m< used_size ;m ++){
                           ptr[i] =ptr[i+1] ; 
                           

           }
           used_size-- ;
        }
    }
} 

void delete_element_single_occurence(T a) ; // deletes all the occurences "a" of datatype T irrespective of the index postions. 
 void sort(){
     for(int m= 0; m < used_size ;m ++){
         for(int i= 1; i < used_size ;i ++){
         T temp  ; 
         if(ptr[i-1]>ptr[i])
         {
            temp   =   ptr[i-1];
             ptr[i-1] =  ptr[i] ; 
             ptr [i] =  temp ;
         }
     }
     }
 }

 void at(int a){
     
     cout<<ptr[a-1]<<endl ; 
 }

 void insert(T a , int index); 
 void get_data() ;


} ;

   template<class T>
   void creat_arr<T> :: get_data(){
    
 for(int i= 0; i<used_size ;i ++){
    
    cout<<ptr[i]<<" " ;
 }
 cout<<endl ; 
 }
 

template <class T>
void  creat_arr<T> :: insert(T val, int ind){

    if(used_size==size_allocated)
    cout<<"ARRAY LIMIT REACHED !" ; 
    else
    {
 for(int i = used_size-1 ;i >= ind; i--){
    
    
   ptr[i+1]  = ptr[i] ;
   ptr[i] =ptr[i-1];
 }

 ptr[ind-1]  = val; 
 used_size++  ;
    }
} 

template<class T>
void  creat_arr<T> :: delete_element_single_occurence(T a){ // deletes single and the very first occurence of a  . 

    for(int i=0 ; i<used_size;  i++){

        if(ptr[i]==a){
        
                for(int m = i ; m<used_size ;m++){

                    ptr[m] = ptr[m+1] ;
                }
               used_size -- ;
               break; 
        }
    }
}
#endif  // data_abstraction_array 
