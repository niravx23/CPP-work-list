#include "vector.hpp"
#include <string>







using namespace  std; 


int main(){

    string n ;
    getline(std::cin, n);
  vector <char> sample;



    for(int i =0 ; i < n.size() ;  i++){
   if(n[i]=='('){
 sample.push_back('(');
   }
   else if(n[i]==')'){
       sample.pop_back();
   }

    }
 if(sample.size()== 0){
     cout<<"balanced"; 

 }
 else
  cout<<"unbalanced!" ;
    return  0;
}