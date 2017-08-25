#include <SimpleTimer.h>
#include <Servo.h> 
#include <stdlib.h>
#include <stdio.h>
int servoXPin = 8;
int servoYPin = 9;
int angleX = 80;
int angleY = 100;
SimpleTimer timer1,timer2,timer3;
Servo servoX,servoY; 

 void front(){
   while(!(angleX==80 && angleY==100))
       {
       if(angleX>80)angleX--;
       if(angleX<80)angleX++;
       if(angleY>100)angleY--;
       if(angleY<100)angleY++;  
       delay(100);       
      servoX.write(angleX);
      servoY.write(angleY);

       }
 }
 void right(){
        while(!(angleX==80   && angleY==20))
       {
       if(angleX>80)angleX--;
       if(angleX<80)angleX++;
       if(angleY>20)angleY--;
       if(angleY<20)angleY++;  
       delay(100);       
      servoX.write(angleX);
      servoY.write(angleY);

      }
      }
      void down(){
        while(!(angleX==50   && angleY==20))
       {
       if(angleX>80)angleX--;
       if(angleX<80)angleX++;
       if(angleY>20)angleY--;
       if(angleY<20)angleY++;  
       delay(100);       
      servoX.write(angleX);
      servoY.write(angleY);

      }
      }
 
      void left(){
        while(!(angleX==80 && angleY==189))
       {
       if(angleX>80)angleX--;
       if(angleX<80)angleX++;
       if(angleY>165)angleY--;
       if(angleY<165)angleY++;  
       delay(250);       
      servoX.write(angleX);
      servoY.write(angleY);

      }
       }

void setup() {
  
   Serial.begin(9600);
    servoX.attach(servoXPin); 
    servoY.attach(servoYPin);
}

 

void loop(){
      servoX.write(angleX);
      servoY.write(angleY);
      timer1.run();
      timer2.run();
      timer3.run();
   if(Serial.available()){
     int b= Serial.read();
    
      if(b=='s')
      {
     timer1.setTimeout(17000,right);
     timer2.setTimeout(22000,front);
     timer3.setTimeout(74000,left);
     
     
        }
       if(b == '2') angleX++;
       if(b == '8') angleX--;
       if(b == '6') angleY--;
       if(b == '4') angleY++;
       if(b == '9'){ angleX++; angleY++;}
       if(b == '7'){ angleX++; angleY--;}
       if(b == '1'){ angleX--; angleY--;}
       if(b == '3'){ angleX--; angleY++;}
       if(b == '5'){
        while(!(angleX==80 && angleY==100))
       {
       if(angleX>80)angleX--;
       if(angleX<80)angleX++;
       if(angleY>100)angleY--;
       if(angleY<100)angleY++;  
       delay(20);       
      servoX.write(angleX);
      servoY.write(angleY);

      }}
     
        
       if(angleX > 190) angleX = 190;
       if(angleY > 190) angleY = 190;
       if(angleX < 0) angleX = 0;
       if(angleY < 0) angleY = 0;
      Serial.print(angleX);
      
      Serial.print("  ");
      Serial.println(angleY);
    
    }
}
