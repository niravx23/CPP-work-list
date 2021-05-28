#include <iostream>
#include <string>
#include <map>
#include "vector.hpp"
 std::map<char, int> precedence ;
  

namespace prefix {

std::string reverse(std::string a) ;
void add_precedence(){
precedence.insert( std::pair<char, int>('*', 2));
precedence.insert( std::pair<char, int>('/', 2));
precedence.insert( std::pair<char, int>('+', 1));
precedence.insert( std::pair<char, int>('-', 1));
}

bool isOperator(char a){
    if(a== '*'||a=='/'||a=='+'||a=='-'){
        return true;

    }
    else{ 
    return false ;
    }
}
  std::string to_prefix(std::string sample){
        vector <char> ops ;
       add_precedence();
       std::string out_stream ;
       
       for(int i = sample.size()-1 ; i >= 0 ; i--){
           if(sample[i]=='(' ||sample[i] ==')'){
               continue ;
           }
           if(isOperator((char)sample[i])){
               if(ops.size()==0){
                   ops.push_back(sample[i]);
                   continue;
               }      
                         auto  itr = precedence.find(ops.peek_last());
                         auto itr_here = precedence.find(sample[i]);
                         if(itr->second>=itr_here->second){
                            
                             out_stream+= ops.peek_last() ;
                            ops.pop_back();
                              auto it  = precedence.find(ops.peek_last());
                             if(it->second<itr_here->second){
                                    ops.push_back(sample[i]);
                             }
                             else {
                              out_stream += sample[i];
                             }
                         }
                         else{
                             ops.push_back(sample[i]);
                         }

           }
           else{
               out_stream+= sample[i];
           }
       }


       if(ops.size()>0){
 auto itr  = ops.itr_first();
 int  t  =  ops.size();
      for(int i = 0 ;i <t;i++){
       
       out_stream += ops.peek_last() ;
       
               ops.pop_back();
      }
       }
       
       return reverse(out_stream);
        } 
std::string reverse(std::string a) {
 
 std::string sample   ;
 for(int i  = a.size()-1  ;  i>= 0 ; i --){
     sample += a[i];
 }


return sample;
}
} 



namespace postfix{

    std::string  to_postfix(std::string sample){
              
              std::string outln; 
        prefix::add_precedence();

        vector<char> post ;

        for(int i =0  ;i  < sample.size() ;  i++){

        if(sample[i] == '('|| sample[i]==')'){
            continue ;
      
        }
        if(prefix::isOperator(sample[i])){

            if(post.size()==0){
                post.push_back(sample[i]);
                continue ;
            }
            auto itr  = precedence.find(post.peek_last());
            auto here1 = precedence.find(sample[i]);

            if(itr->second<here1->second){
                post.push_back(sample[i]);
                continue ;
            }
            else{ 
                
                outln+= post.peek_last();
                post.pop_back();
                auto it  = precedence.find(post.peek_last());
                if(here1->second<=it->second){
                   outln +=sample[i];
                }
                 else
                
                post.push_back(sample[i]);
            }
            
        }
        else{
            outln += sample[i];
        }
          

        }
 
        
     
       if(post.size()>0){
               auto t = post.size();
            for(int  i =0  ; i  <t ; i++){

                outln+=  post.peek_last();
                post.pop_back();
            }
        }

        return outln;
    }





}