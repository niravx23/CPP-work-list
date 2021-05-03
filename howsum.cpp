//given a sum and a group of arrays determine whether the sum can  be
//generated using the given array . You can use the elements as many times
// you want  . Also 0 times is allowed. 
//at last print the possible array that can generate the given sum ;

#include<iostream>
#include<vector>
#include<map>
using namespace std ;


vector<int> howsum(long long int  sum  , vector<int> here){
    static map<long long int ,vector<int>> to_store;
    static vector<int> to_return  ; 
if(sum==0){
  to_return.push_back(0) ;
return to_return ;
}
if(sum<0){to_return.clear();
return to_return;}

if(to_store.count(sum)!=0){
auto itr  = to_store.find(sum) ;
return itr->second;
}
for(auto i :here){
    const long long int remainder =  sum-i ;  //         // sum =  7 and elements [2,3]
  vector<int> result =howsum(remainder,here);
    if(result.size()!=0){
        to_return.push_back(i) ;
        to_store.insert(pair<long long int ,vector<int>>(remainder,to_return)) ;
        return to_return ;
    }

}
to_return.clear();
        to_store.insert(pair<long long int ,vector<int>>(sum,to_return)) ;

return to_return;
}

int main(){ 
    vector<int> send ;
    long long int n ;             
    cin>>n;            
    int trial  ,numb  ;
    cin>>numb ; 
    for(int i= 0; i<numb; i++)             
   {
       cin>>trial ;
       send.push_back(trial);

   }

    send = howsum(n, send) ;
if(send.size()==0)cout<<"null"; 
else{
  
    for( auto i : send){
        if(i==0){}
        else
        cout<<i<<" ";
    }
}

    return  0 ;        
}