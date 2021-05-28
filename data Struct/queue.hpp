#include <iostream>

template<class T>
class queue{

private : 

 int size =0 ;
T* data = new T[size] ;
int front=-1 ;
int rear=-1;


public :

void details(){
std::cout<<"size : "<<size<<std::endl;
std::cout<<"front end : "<<front<<std::endl;
std::cout<<"rear end :"<<rear<<std::endl;



}
bool isEmpty(){
    if(front==rear){
        return true ;
    }
    else return false;
}
void enqueue(T sample){
if(isEmpty()){
    rear = 0 ; 

    data[rear] = sample ;
    size++;
}
else{
    rear++;
    data[rear] = sample ;
    size++;
}
    
}

void peek_front(){
std::cout<<data[front+1]<<std::endl;
}
void peek_rear(){
std::cout<<data[rear]<<std::endl;

}

T dequeue(){
    if(!isEmpty()){
       
        front++ ;
        size-- ;

        return data[front-1];
    }
    else{
        return -1 ;
    }
}

void show(){
    
      auto x = front+1 ;

   while(x<=rear){

       std::cout<<data[x]<<" " ;
       x++;
   }
    std::cout<<std::endl;
}
};

