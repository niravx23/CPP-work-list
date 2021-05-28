/*
this is array acting like a vector . You can access the array , read , add and modify . 
 * To include this in cpp file use ----> #include "data_abstraction_array.h" ; 
 1) To inititate the array --> creat_arr("name_array",total_size_assinged, actual_size_used) ;
  !-- > keep assinged size more than actual_size_used , to enter more data when needed in future;
 2) When using set_data :  
 for  n entitities enter  n data items of type T and
 3)get_data method prints the entire arr upto used_space .

(data_type)malloc(sizeof(data)) ; -- >dynamic memory allocation

//             IN PROGRESS WORK !!  !! !                    //
*/


// namespaces are ADT, linked_list, cir_linked_list ;
#include <iostream>

using namespace std;
namespace  ADT {

    
template<class T>
class creat_arr{ 

int used_size , size_allocated   ;
public : int *ptr ;

creat_arr(int a1, int a2 ):size_allocated(a1),used_size(a2) {
     
     ptr = new T[size_allocated] ;
}
~creat_arr(){

    
}

int* pointer(){
    return ptr ;
}
int size(){
    return used_size ;
}  


int alloc_size() { 
    return size_allocated ;
}

 void set_data(){
   
    
     T tmp ; 
 for(int i= 0; i<used_size ;i ++){
     cin>>tmp ;
     ptr[i] = tmp ; }
 
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

    


    
void BinarySearch(creat_arr<int> obj , int arr[]  ){ 
    int n; 

    std::cout<<"ENTER THE NUMBER TO FIND ? : ";
    std::cin>>n;
     obj.sort();
    int mid, low  =0  , high  = obj.size()-1;
     
      while(high>=low) {
          
      mid = (low+high)/2;
    if(n==arr[mid]){
        std::cout<<"The element "<< n <<" was found at index "<<mid<<std::endl ;
        break;
    }
    else if(n>arr[mid]){
        low  = mid+1 ;
         
    }
      else{
          high = mid -1;
      }
      
 
 }
       
 if(high<low){
     std::cout<<"ELEMENT NOT FOUND "<<std::endl;
 }
}


}

//--------------------------------------------------------------------------------------------------------\\

 namespace linked_list{
    static int count  =0  ;
   
struct ll {
    int data ;

    struct ll * ptr ;



};
void PrintLinkedList(struct ll*ptr1){

    while(ptr1!=NULL){
        cout<<ptr1->data<<" " ;
        ptr1 = ptr1->ptr ;
    }
    cout<<endl;
}

struct ll * insert_at_beginning(struct ll* head ,int dat1a){ 
    struct ll* here1 = new struct ll ;
    here1->data =  dat1a ;
    here1->ptr = head ;
 return here1 ;
}

struct ll* insert_at_end(struct ll* last, int data1){
    struct ll* to_send  = new struct  ll ;
    to_send -> data = data1 ;
    last->ptr = to_send ;
    to_send ->ptr = NULL;

    return to_send ;
}


struct ll* overwrite_at_index(struct ll* start ,int data1,int  index ){
    struct ll* sample1 = new struct ll ;
 sample1 = start ;
    struct ll* sample = new struct ll ;
    sample = start ;

    for(int i =0 ; i < index-1; i++){
       
        sample = sample->ptr ;
    } 
        sample->data = data1 ;
 
       return sample1;
}

struct ll* insert_after_node(struct ll* node, int data1, int post){


struct ll* sample  = new struct ll ;
struct ll* sample1 = new struct  ll ;
struct ll* main_node  = new struct ll ;

sample1 =  node   ;
sample = node;
for(int i = 0 ; i  <post-2 ; i ++)
{
sample = sample ->ptr ;

}
main_node->ptr =  sample->ptr ; 
main_node->data  = data1 ;

sample->ptr  = main_node ; 

return sample1 ;

}


void intro (){

    const char * dat =  "\t The following functions of Linked List are written under namespace linked_list\n"
    "\n\tThe data abstraction ADT namespace is another namespace in Data Abstraction Header File which doesn't posses any relation with this\n"
    "\tADT namespace  : ADT corresponds to array whilst the linked_list forms the basis for vectors and many STL containers ! \n"
    "\n\tTHE CONTAINED FUNCTIONS IN THIS NAMESPACE ARE \n\n"
    "void PrintLinkedList(struct ll*ptr1) \n\n"
    "struct ll * insert_at_beginning(struct ll* head ,int dat1a)\n\n"
    "struct ll* insert_at_end(struct ll* last, int data1)\n\n"
    "struct ll* overwrite_at_index(struct ll* start ,int data1,int  index )\n\n"
    "struct ll* insert_after_node(struct ll* node, int data1, int post)\n\n" ;
  
  cout<<dat;

}
 
void get_func_info(string here1 ){

    if(here1.find("beginning")!= string::npos){
        cout<<"\n struct ll * insert_at_beginning(struct ll* head ,int dat1a)\n ";
    }
    else
    cout<<"\nEnter Related  Function Name ! \n" ; 
}

struct ll* delete_node(struct ll* start , struct ll* del ){
struct ll* sample =  new struct  ll ;
struct ll* sample1 =  new struct  ll ;
struct ll* sample2 =  new struct  ll ;

if(start == del){
    sample = start->ptr ;
    return sample ;
}
sample = start ;
sample1 = start ;
while(sample!= del){
    if(sample->ptr ==del){
        sample2= sample; 
    }
sample = sample->ptr ;
}
sample = sample->ptr ;
sample2->ptr = sample ;
return sample1 ;
}

struct ll* delete_Key(struct ll* start ,int value ){
struct ll* sample =  new struct  ll ;
struct ll* sample1 =  new struct  ll ;
struct ll* sample2 =  new struct  ll ;

sample = start ;
sample1 = start ;
sample2 = start ;

int check =0 ;

while(sample->data!=value && sample->ptr!= NULL){
   if((sample->ptr)->data == value){
       sample1 ;
   }
   sample = sample->ptr ;
   check ++;
}
if(check == 0){
    sample2 = sample2->ptr ;

    return sample2 ;
}
else if(sample->data  == value){
    sample1->ptr =  sample->ptr ;
}



return sample2; 
}


 }
 
//--------------------------------------------------------------------------------------------------------\\

 
namespace cir_linked_list{

struct ll {
    int data ;

    struct ll * ptr ;

};

void PrintLinkedList(struct ll* ptr1){
struct ll * sample = ptr1 ;
  do{
     cout<<ptr1->data<<" " ;
     ptr1 = ptr1->ptr ;
  }while(ptr1!=sample);

cout<<endl;

}

struct ll * insert_at_beginning(struct ll* head ,int dat1a){ // 
    struct ll* here1 = new struct ll ;
    struct ll* here2 = new struct ll ;

    here1->data =  dat1a ;
    here1->ptr = head ;
    here2 = here1 ;
    do{
        here1 = here1->ptr ;
    }while(here1->ptr!=head);
 here1->ptr = here2 ;
 return here2;
}
struct ll* insert_at_index(struct ll* start ,int data1,int  index ){ // here index are positions for index 0 position 1
 
    struct ll* to_return = new struct ll ;
 
  auto  traverse = start ;

  try{
if(index<=0){
    
    throw 101 ;
}
  }catch(int a){
    cout<<"PLEASE ENTER A NATURAL NUMBER WIHTIN RANGE"<<endl;
    cout<<"since data params were invalid The data was entered at position 1"<<endl;
     return insert_at_beginning(start,data1);
}



if(index==1){

    return insert_at_beginning(start,data1);
}
  for(int i =1 ; i<index-1  ; i++){
      traverse = traverse->ptr ;
  }
  auto sample = traverse ;
  sample = sample->ptr ; 
  traverse->ptr = to_return ; 


  to_return->ptr = sample ;
to_return ->data  = data1 ;
  return start ;
}

struct ll* delete_Key(struct ll* start ,int value ){
struct ll* sample =  new struct  ll ;
struct ll* sample1 =  new struct  ll ;
struct ll* sample2 =  new struct  ll ;

sample = start ;
sample1 = start ;
int check  = 0 ; 
do{
    check  ++ ;
 sample = sample->ptr ;
}while(sample->ptr->data!= value && sample->ptr!=start) ;

if(check==1){

 start = sample1->ptr ;
 return start ;
}
else if(sample->ptr->data == value){
sample2 =  sample ;

sample = sample->ptr ;
sample2->ptr = sample->ptr;
}
return start ;
}

void intro (){

    const char * dat = "\nWhen adding data be sure to point the pointer of last node to the first\n" " The following functions of Circular Linked List are written under namespace cir_linked_list\n"
    "\nThe data abstraction ADT namespace is another namespace in Data Abstraction Header File which doesn't posses any relation with \n"
    "ADT namespace  : ADT corresponds to array whilst the linked_list forms the basis for vectors and many STL containers and ciruclar linked list is type of link. list! \n"
    "\nTHE CONTAINED FUNCTIONS IN THIS NAMESPACE ARE \n\n"
    "\tvoid PrintLinkedList(struct ll*ptr1) \n\n"
    "\tstruct ll* insert_at_index(struct ll* start ,int data1,int  index )\n" 
    "\tstruct ll* delete_Key(struct ll* start ,int value )\n" ;
  
  cout<<dat;

}
}


//-------------@params-------------------------------------------------------------------------------------------\\



/*

while(sample->data!=value && sample!=start){
   if((sample->ptr)->data == value){
       sample1 ;
   }
   sample = sample->ptr ;
   check ++;
}
if(check == 0){
    sample2 = sample2->ptr ;

    return sample2 ;
}
else if(sample->data  == value){
    sample1->ptr =  sample->ptr ;
}
return start;*/