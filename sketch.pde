import processing.serial.*;
import java.util.*;
Serial p;                                                      



void setup(){

   println(Serial.list());                                  

   textSize(64);

   p = new Serial(this, Serial.list()[0], 9600);    
   
}                                                                 

 
void draw(){ }                                                 

 

void keyPressed(){
   p.write(key);                                               

   background(0);

   text(key, 20, 80);

}