#include <iostream>

 using namespace std ;
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
