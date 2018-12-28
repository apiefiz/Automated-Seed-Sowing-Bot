#include <Servo.h>             //Servo library
char t; 
Servo servo_test1,servo_test2;        //initialize a servo object for the connected servo  

int angle=0;
// defines variables
long duration;
int distance;
const int trigPin = 2;
const int echoPin = 3;
const int in1 = 13;
const int in2 = 12;
const int in3 = 11;
const int in4 = 10;
int p=0;
void setup() 
{ 
  servo_test1.attach(9);   
  servo_test2.attach(8);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output 
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(in1,OUTPUT);   //left motors forward
  pinMode(in2,OUTPUT);   //left motors reverse
  pinMode(in3,OUTPUT);   //right motors forward
  pinMode(in4,OUTPUT);   //right motors reverse
} 

  
void loop() 
{ 
  for(angle = 180; angle > 0; angle -= 1) 
  {                                  
    servo_test1.write(angle);               
                          
  } 
 
  //delay(1000);
  
  for(angle =0; angle<180; angle+=1)  
  {                                
    servo_test1.write(angle);             
    //delay(5);                       
  } 
  
  for(angle = 60; angle > 0; angle -= 1) 
  {                                  
    servo_test2.write(angle);               
                          
  } 
 
  //delay(1000);
  
  for(angle =0; angle<60; angle+=1)  
  {                                
    servo_test2.write(angle);             
    //delay(5);                       
  } 
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
if(t == '1'){            //move forward(all motors rotate in forward direction)
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

else if(t == '2'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

else if(t == '3'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

else if(t == '4'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
 
else if(t == '5'){      //STOP (all motors stop)
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
delay(100);}
else
{
   duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance<30)
    { 
      p++;
      servo_test1.detach();
      if(p%2==0)
      {  
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH);
      }
      else
      {
      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW); 
      }
      delay(1200);
      servo_test1.attach(9);
    }
    
  else
    { servo_test2.detach(); 
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
      servo_test2.attach(8);
    }  
  delay(0);
}
}  //  delay(1000);

