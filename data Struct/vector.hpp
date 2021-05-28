#include <iostream>
template <class T>
class vector {
   public :
int count =0   ;

 T *data  = new T[count] ;




friend class list  ;

void push_back(T a)
{
   
    count++ ;
    data[count-1] = a ;
}

void show(){
    for(int i= 0; i<count ; i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl ;
}
void pop_back(){
  if(count!=0) count -- ;
}

int size(){
return  count  ;
}

void clear(){
    count= 0 ;
    delete data ;

}

int isEmpty(){
    if(count ==0) return  1 ;
    else return 0;
}

int isFull(){

    return !isEmpty();
}
~vector(){
    clear();
}

T peek_last(){

    return data[count-1] ;
}

T* itr_first(){

    return &data[0];
}
void insert(T data1, int post){
   
   try {
       if(post<1){
           throw 202  ;
       }
       else if (post>count+1){
           throw 203; 
       }
   }catch(int a){
       if(a==200){
       std::cout<<"\nTHE ENTERED INDEX WAS NOT VALID , ELEMENT ADDED TO INDEX 0  !"<<std::endl ;
       goto now ;
   }
   else if(a==203)
   {
       
       std::cout<<"OUT OF LIMIT !" <<std::endl ;
       goto now;
   }
   }
    for(int i = post ;i<=count ; i++){
  
        data[i] = data[i-1] ;

    }
    count++ ;
    data[post-1] = data1 ;
    now :{

    }
}

int isPresent(T a)
{
    for(int i  = 0; i < count ; i ++){
        if(data[i]==a){
            return 1 ;
            break ;
        }
    }

    return  0 ; 
}


} ;


// template<class T>
//  int  vector<T>::count  = 0 ;


