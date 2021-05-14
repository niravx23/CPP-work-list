#include <fstream>
#include <iostream>
#include <string>

using namespace std; 


class ShaderParser{
  private :   ifstream parse  ;
       enum modes {
         Vertex , Fragment , none 
       };

       string Filename , VertexShaderSource  , FragmentShaderSource ;
      public  :
   modes type  = modes::none ;

      ShaderParser(string sample) :Filename (sample){
         
            parse.open(Filename);
            string ne;
            while(getline(parse, ne)){
                if(ne.find("shader vertex") != string::npos){ 
                  type = modes ::Vertex;
                }
                else if (ne.find("shader fragment")!=string ::npos)
                type = modes::Fragment ;
                else 
                 {
                   if((int)type==0 ){
                     VertexShaderSource += ne  + '\n' ;
                   }
                   else
                   FragmentShaderSource +=ne + '\n';
                 }
       }
      }
    

   string GET_VERTEX_SHADER();
   string GET_FRAGMENT_SHADER();
   
   };

   string ShaderParser :: GET_VERTEX_SHADER(){

     return VertexShaderSource ;
   }

   
   string ShaderParser :: GET_FRAGMENT_SHADER(){

     return FragmentShaderSource ;
   }