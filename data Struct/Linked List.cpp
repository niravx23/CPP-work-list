#include <iostream>

using namespace std ;
  

//---------------------------------------------------------------------------------------------------------\\

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
