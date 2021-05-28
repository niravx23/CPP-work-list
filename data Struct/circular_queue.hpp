#include <iostream>

/*
  ||||||||| |||||||||   |||||||||   |||||||||||
  ||           ||       ||          ||*      ||     
  ||||||       ||       ||||||      || *     ||
  ||           ||       ||          ||  *    ||          
  ||           ||       ||          ||   *   ||  
  ||        |||||||||   ||          |||||||||||


 */
template<class T>class circular_queue {
 int size =0;
 int stock ;
 T *data =  new T[stock];
 int front =-1 ;
 int rear =-1 ;

 public :


circular_queue(int n):stock(n){}

int used_size(){
    return size;

}
bool isFull(){
  if(size==stock) return true; //size assingned already from user.
  else return  false;
}

bool isEmpty(){
    if(size ==0)return true ;
    else return false;
}
void enqueue(T a){
    if(isEmpty()){
        size++;
        rear++;
        data[rear] = a ;
        front++;
    }
    else{
        if(isFull()){
            std::cout<<"can't insert out of space !"<<std::endl;
        }
        else{
               rear = (rear+1)%stock;
        size++;
               data[rear] = a ;
        }
    }



}

void dequeue(){

    if(isEmpty()){
        std::cout<<"no items to remove !" <<std::endl;
    }
    else{
        size-- ;
        front =( front +1 )%stock ;
    }
}


void show(){
 int t = front;
    for(int i = 0;i<size; i++){

        std::cout<<data[t]<<" " ;
        t= (t+1)%stock;
    }
    std::cout<<std::endl;
}

T front_peek(){

    return data[front];
}

T end_peek(){

    return data[rear];
}
};
