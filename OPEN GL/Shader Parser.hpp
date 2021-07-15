/**/

#include <fstream>
#include <iostream>
#include <string>

using namespace std; 
//----------------------------------UPDATE-------------------------------------------\\
/*
UNDER NAMESPACE program 
new function added to make a program providing only one glsl file location having all shaders in it . The example of which can be found on any glsl file on the rep .

eg :-
[in main func]

unsigned int prg  =  program::make_program("location of your glsl file");

*/


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

namespace program{
unsigned int make_program(string main1)
{
ShaderParser in1(main1); 

string a  =in1.GET_VERTEX_SHADER();
string b  =  in1.GET_FRAGMENT_SHADER();

const char* VertexShaderSource = a.c_str();
const char* FragmentShaderSource =  b.c_str();
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &VertexShaderSource, NULL);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &FragmentShaderSource, NULL);
    glCompileShader(fragment);

    unsigned int prg = glCreateProgram();
    glAttachShader(prg, vertex);
    glAttachShader(prg, fragment);
    glLinkProgram(prg);
    return prg;
}
}
