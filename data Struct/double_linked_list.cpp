/*

 
FIRST NODE PREVIOUS = NULL ;
LAST NODE NEXT   = NULL ;
STRUCT DOUBLE LL  
INT STORE     ;
DOUBLE* PTR1  ; 
DOUBLE * PTR2 ;
METHODS :-

Add a node at the front // DATA EXIST_F_NODE //0
Add a node after a given node. // DATA NODE  // 0
Add a node at the end          //DATA EXIST_F_NODE //0
Add a node before a given node // DATA NODE  //0
 */
#include<iostream>
#include<stdlib.h>
struct dd_list{
    int data ;
    struct dd_list * previous ;
    struct dd_list * next ;

};

struct dd_list* add_node_at_beginning(struct dd_list*ptr ,int data1){
    struct dd_list* here1  = new struct dd_list ;
    here1->data =  data1 ;
    here1->next =  ptr ;
    here1->previous = NULL ;
ptr->previous = here1 ;

 return here1 ;
}
void Show_list(struct dd_list * ptr , int mode ){
  
 if(mode == 1){                   // forward order
    while(ptr!=NULL){
        std::cout<<ptr->data<<" " ;
        ptr = ptr->next ;
    }
 }

 else {
     while(ptr!=NULL){
         std::cout<<ptr->data<<" " ;
         ptr = ptr->previous ;
 }
 }


}

struct dd_list* add_node_at_rear(struct dd_list*ptr ,int data1){
    while(ptr->next !=  NULL){
        ptr = ptr->next ;
    }
    struct dd_list* here1  = new struct dd_list ;
    here1->data =  data1 ;
    here1->next = NULL ;
    here1->previous = ptr;
ptr->next = here1 ;

 return here1 ;
}

struct dd_list* insert(struct dd_list*ptr ,int data1 , int mode ){
 struct dd_list* here1 = new struct dd_list; 
 struct dd_list* here2= new struct dd_list; 
 here1->data  = data1 ;

here2 = ptr; 

if(mode==1){ 
    if(ptr->next == NULL){
        return  add_node_at_rear(ptr , data1);
    }
    
    here1->previous =  ptr;
    here1->next     = (ptr->next) ;
    (ptr->next)->previous =  here1 ;
    ptr->next = here1 ;
}
else if(mode == -1){
if(ptr->previous == NULL)
    {
         return add_node_at_beginning(ptr, data1);
    }
  here1->previous =  ptr->previous ;
  here1->next = ptr ;
  (ptr->previous)->next = here1 ;
  ptr->previous = here1 ;
}
 
 
 return here1 ;
}


int main(){


struct dd_list * ptr1 = new struct dd_list; 
struct dd_list * ptr2 = new struct dd_list; 
struct dd_list * ptr3 = new struct dd_list; 
struct dd_list * ptr4 = new struct dd_list; 

ptr1->data = 3 ;
ptr1->previous = NULL;
ptr1->next = ptr2 ;

ptr2->data = 4;
ptr2->previous  = ptr1;
ptr2->next = ptr3 ;

ptr3->data = 8 ;
ptr3->previous  = ptr2;
ptr3->next = ptr4;

ptr4->data        = 31 ;
ptr4->previous        = ptr3;
ptr4->next        = NULL;


auto  head   =   add_node_at_beginning(ptr1 , 22);
auto  tail   =   add_node_at_rear(head , 45);
auto inter   =   insert(tail,3434 ,-1);
Show_list(head, 1);

}
