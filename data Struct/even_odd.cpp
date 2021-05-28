#include <iostream>
#include<map>
#include<string>
#include<utility>

typedef  long long int iit ; 
using namespace std ; 
class guy{
    iit points ; 

};
//count 1 --->alice count2-->BOB
// Players take turns, Alice moves first.
// Each turn a player chooses any element and removes it from the array.
// If Alice chooses even value, then she adds it to her score. If the chosen value is odd, Alice's score does not change.
// Similarly, if Bob chooses odd value, then he adds it to his score. If the chosen value is even, then Bob's score does not change.
iit* mega(int*ptr, int elems ){
    static int count1=0, count2=0  ; 
        iit sum ;
        int *tmp =  ptr ;
    for(int i=0 ; i<elems; i++){
sum+=*ptr;
ptr++ ;
    }
    for(int i=0 ; i<elems; i++){
        if(i%2==0){
            if(*itr) 
            return mega(tmp,elems-1) ;
        }
        else{
            count 2
        }
    }
}
int main()

{

return 0;

}