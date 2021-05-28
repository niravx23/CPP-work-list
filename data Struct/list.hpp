#include <iostream>
// clone of list ----------->  STL 
template <class T>
class list {
   public :
   
 static int count   ;

 T *data  = new T[count] ;

// 0
T get_maxm(){

    if(count!=0 ){
    int max1 = data[0] ;
for(int i= 0; i < count; i ++){
if(data[i]>max1)max1 =data[i] ;
}

return max1 ;
    }

else {
    try {
        throw 202;
    }catch(int a ){
        std::cout<<"empty container !" <<std::endl ;
    }
}
    
}

T get_element(int i){

try {
if(i>count+1  || i<0){
    throw 101 ;
}
}catch(int a)
{
    std::cout<<"invalid position"<<std::endl;
    goto b1 ;
}

return data[i-1] ;



b1:{

}
}
//0
void push_back(T a) ;
//0
void show(){
    for(int i= 0; i<count ; i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl ;
}
//0
void pop_back(){
   count -- ;
}

//0
int size(){
return count  ;
}
//0
void clear(){
    count= 0 ;
    delete data ;

}
//0
int isEmpty(){
    if(count ==0) return  1 ;
    else return 0;
}
//0
int isFull(){

    return !isEmpty();
}
//-
~list(){
    clear();
}
//0
void peek(int a){
if(a<= count){

    std::cout<<data[a-1]<<std::endl ;
}
}
//0
void sort(); 
//0
void overwrite(T data1, int post){
   
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
//0
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
//0
void set_data_upto( int index) ;
} ;


template<class T>
 int  list<T>::count  = 0 ;


template<class T>
void  list<T>::sort(){
  T temp  ; 
 
     for(int m= 0; m < count ;m ++){
         for(int i= 1; i < count ;i ++){
       
         if(data[i-1]>data[i])
         {
            temp   =   data[i-1];
             data[i-1] =  data[i] ; 
             data [i] =  temp ;
         }
     }
     }
}

template <class t>
void list<t> ::push_back(t sample){

   if(!isPresent(sample)){   ///isPresent returns 1 if present true case .

       count++ ;
       data[count-1] = sample ;
   }             
}


template <class T>
void list <T>::set_data_upto(int index) { // from current count to count + index-1 
   

T sample ;
for(int i =0   ; i  < index ; i ++){
   std::cin>>sample ;
  push_back(sample);
  
}
}

