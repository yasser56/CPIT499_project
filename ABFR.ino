#include <Servo.h>
#include "car.h"
#include "ultrasonicSensor.h"
int sensorPin = A5;
long  disLeft, disCenter, disRight;
int Buz = A4;
Servo myservo;
car car1 (4, 5, 6, 7);
ultrasonicSensor  S_left(8);
ultrasonicSensor  S_center(2);
ultrasonicSensor  S_right(3);

  boolean fire = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //-----------------------------------------
  pinMode(car1.getR_IN4(), OUTPUT);
  pinMode(car1.getR_IN3(), OUTPUT);
  pinMode(car1.getL_IN2(), OUTPUT);
  pinMode(car1.getL_IN1(), OUTPUT);
  myservo.attach(9);      

  //-----------------------------------------


}

void loop() { // put your main code here, to run repeatedly:
  
  int R_IR_sensor = analogRead(A0);
  Serial.print(R_IR_sensor);
  Serial.print("  R_IR_sensor");
  Serial.println();



  int C_R_IR_sensor = analogRead(A1);
  Serial.print(C_R_IR_sensor);
  Serial.print("  C_R_IR_sensor");
  Serial.println();


  int C_L_IR_sensor = analogRead(A2);
  Serial.print(C_L_IR_sensor);
  Serial.print("   C_L_IR_sensor");
  Serial.println();


  int L_IR_sensor = analogRead(A3);
  Serial.print(L_IR_sensor);
  Serial.print("   L_IR_sensor");
  Serial.println();



  /*
    R_IR_sensor
    C_R_IR_sensor
    C_L_IR_sensor
    L_IR_sensor
  */

 //---------------------------------------------------------------------------------------------------------------------------------
  // left Ultrasonic Sensor
  disLeft =  S_left.getDistance();
// Centar Ultrasonic Sensor
  disCenter = S_center.getDistance();
//  righ Ultrasonic Sensor
  disRight = S_right.getDistance();
//----------------------------------------------------------------------------------------------------------------
  while (R_IR_sensor <= 800) {
   // fire = true;
     tone(A4, 6000);
   car1.rightMove();
    R_IR_sensor = analogRead(A0);
   
    if (R_IR_sensor > 500 ) {
    car1.StoptMove();
       noTone(A4);
      break;

    }
  }



  while (L_IR_sensor <= 800) {
  //  fire = true;
     tone(A4, 6000);
    car1.leftMove();
    L_IR_sensor = analogRead(A3);
    if (L_IR_sensor > 500 ) {
      car1.StoptMove();
       noTone(A4);
      break;
    }
  }



  while ( (C_R_IR_sensor <= 800) || (C_L_IR_sensor <= 800) ) {
    fire = true;
   tone(A4, 6000);
    car1.Move();
  
   

  }
 //=====================================================================

  // sense obstacals from Center UltrasonicSensor and_Avoid them
  while (disCenter < 15 ) {
          car1.BackMove();
          Serial.println("BackMoveBackMoveBackMoveBackMoveBackMoveBackMove");
          disCenter = S_center.getDistance();

    if (disCenter >= 15){
     car1.StopMove();
      break;
    }
        }
  //=====================================================================
  //  sense obstacals from Right UltrasonicSensor and_Avoid them
  while (disRight < 10 ) {
    car1.BackMove();
    car1.leftMove();  delay(570);
    car1.Move(); delay(300);

    while (R_IR_sensor <= 750) {
      tone(A4, 6000);
      car1.rightMove();
      R_IR_sensor = analogRead(A0);
      if (R_IR_sensor > 500  ) {
        car1.StoptMove();
        noTone(A4);
        break;
      }
    }
    Serial.println("BackMove");


    disRight = S_right.getDistance();
    if (disRight > 10 ) {
      car1.StoptMove();
      Serial.println("okBackMove");
      break;
    }
  }

  //=====================================================================

  // sense obstacals from Left UltrasonicSensor and_Avoid them
  while (disLeft < 10 ) {
    car1.BackMove();
    car1.rightMove();  delay(570);
    car1.Move(); delay(300);

    while (L_IR_sensor <= 750) {
      tone(A4, 6000);
      car1.leftMove();  delay(550);
      L_IR_sensor = analogRead(A3);

      if (L_IR_sensor > 500  ) {
        car1.StoptMove();
        noTone(A4);
        break;
      }
    }
    Serial.println("BackMove");

    disLeft = S_left.getDistance();
    if (disLeft > 10 ) {
      car1.StoptMove();
      Serial.println("okBackMove");
      break;
    }
  }
  
      while ( ( disCenter >=16 ) && ( disCenter < 20) ) {

        
         if ( ( disRight >= disLeft ) && ( R_IR_sensor <= 890)  )
         {
         car1.leftMove();
           delay(550);
          Serial.println("في شرط اليمين");
          car1.StopMove();
           break;

        }
        
        else if ( ( disRight < disLeft ) && ( L_IR_sensor <= 890) )
        {
          car1.rightMove();
          delay(550);
          Serial.println("في شرط اليسار");
          car1.StopMove();
          break;      
        }
        
       else
       {
        R_IR_sensor = analogRead(A0);
        L_IR_sensor = analogRead(A3);
      } 
    

   




   Serial.println();
 // delay(2000);
}
void put_out() {
 digitalWrite(A0, HIGH);
  for (int i = 0; i < 90; i += 1) // goes from 0 degrees to 90 degrees
  { // in steps of 1 degree
    myservo.write(i);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int i = 90; i >= 1; i -= 1) // goes from 90 degrees to 0 degrees
  {
    myservo.write(i);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo.write(0);
}



