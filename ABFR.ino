#include <Servo.h>
Servo myservo;
const int pingPin_left = 8;
const int pingPin_centar = 2;
const int pingPin_righ = 3;
int R_IN4 = 4;
int R_IN3 = 5;
int L_IN2 = 6;
int L_IN1 = 7;
long left, centar, righ, Time0 , Time1, Time2, cm1, cm2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //-----------------------------------------
  pinMode(R_IN4, OUTPUT);
  pinMode(R_IN3, OUTPUT);
  pinMode(L_IN2, OUTPUT);
  pinMode(L_IN1, OUTPUT);
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



  




    if (centar < 30 ) {

    if (centar == 15 ) {

      BackMove();
      Serial.println("BackMoveBackMoveBackMoveBackMoveBackMoveBackMove");
    }
    else if (righ > 40 ) {
      rightMove();
      rightMove();
      
      centar == 29;



    }
    else
    {
      leftMove();
      leftMove();
     

      centar == 29;

    }
    }

    else
    {

    if(R_IR_sensor <=500){
    rightMove();
     Move();
    }
    else if(L_IR_sensor <= 500){
    leftMove();
     Move();
    }

    else if( C_R_IR_sensor <= 500 || C_L_IR_sensor <= 500){
     Move();
    }

    }

   Serial.println();
  delay(2000);
}



