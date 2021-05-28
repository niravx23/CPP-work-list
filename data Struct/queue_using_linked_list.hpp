#include <iostream>

struct node {
 int  data;
  struct node * ptr; 

} ;

template<class T> class linked_list_queue {

  /*pbl*/ 
  struct node* rear  =NULL;
  struct node* front  =NULL;
  int size  =  0  ;

  public :

linked_list_queue(){

}
  void enqueue(T data1){
   if(rear == NULL && front == NULL){
 
       struct node*  sample  = new struct node ;
       rear  = sample ;
       front = sample ;
       sample->data  = data1 ;
       sample->ptr  =  NULL;
   }
   else{

      struct node * sample = new struct node  ;


      rear->ptr = sample ;
      sample->data = data1 ;
      sample->ptr = NULL;

   }
          size++;
  }

void show(){
  if(size<1){goto point1 ;}
 struct node * sample  = new struct node ;
 sample = front;
  while(sample->ptr!=NULL){
    std::cout<<sample->data<<" ";
    sample = sample->ptr ;
  }

  std::cout<<std::endl;
point1 :{

}
}
};
 