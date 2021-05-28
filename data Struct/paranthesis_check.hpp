#include <iostream>
#include <string>
#include "vector.hpp"
namespace paran_check 
{


bool check_paran(std::string sample){
    vector<char> paran ;
for(int i =0 ;i<sample.size() ; i ++ ){
std::cout<<sample[i] ;
if(sample[i]=='(' || sample[i] =='[' || sample[i]=='{')paran.push_back(sample[i]);
else if (sample[i]==')' || sample[i] ==']' || sample[i]=='}'){
if(paran.peek_last()=='(' && sample[i] ==')' ||paran.peek_last()=='{' && sample[i] =='}'||paran.peek_last()=='[' && sample[i] ==']')

     paran.pop_back();

}
}



if(paran.size()==0)return true ;
else return false ;



}