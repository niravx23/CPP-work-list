#include <fstream>
#include <iostream>
#include <string>

using namespace std; 

/*          ////////!\\\\\\\\\
 ----- > THIS PARSER ALLOWS YOU TO WRITE ALL TYPES OF SHADER IN SAME FILE .
 ----- > THIS CURRENTLY WORKS FOR VERTEX AND FRAGMENT SHADER . 
 ----- > IT CAN BE MODIFIED FOR ADDING OTHER SHADER TYPES [FOR THAT YOU NEED TO ALTER MODES, INCLUDE STRING OF ADDITIONAL SHADER AND CREATE A EXTRA METHOD TO RETURN THAT SHADER STRING]
 ----- > STEPS TO USE  :
       1) CREATE A CLASS OBJ AND PASS THE LOC/n OF THE SHADER FILE  . [EG :-  ShaderParser obj1("Shaders.glsl")] 
       2) CREATE STRINGS FOR DIFFERENT SHADERS .
       3) USE GET_SHADERNAME_SHADER() TO ASSING THE SHADERS ITS SOURCE .
*/
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
