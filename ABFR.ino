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



  

    // left Ultrasonic Sensor

    pinMode(pingPin_left, OUTPUT);
    digitalWrite(pingPin_left, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin_left, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin_left, LOW);
    pinMode(pingPin_left, INPUT);
    Time0 = pulseIn(pingPin_left, HIGH);
    left = microsecondsToCentimeters(Time0);


    //------------------------------------------
    // Centar Ultrasonic Sensor
    pinMode(pingPin_centar, OUTPUT);
    digitalWrite(pingPin_centar, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin_centar, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin_centar, LOW);
    pinMode(pingPin_centar, INPUT);
    Time1 = pulseIn(pingPin_centar, HIGH);
    centar = microsecondsToCentimeters(Time1);

    //-------------------------------------------
    // righ Ultrasonic Sensor
    pinMode(pingPin_righ, OUTPUT);
    digitalWrite(pingPin_righ, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin_righ, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin_righ, LOW);
    pinMode(pingPin_righ, INPUT);
    Time2 = pulseIn(pingPin_righ, HIGH);
    righ = microsecondsToCentimeters(Time2);


    //-------------------------------------------------------------------------

/*
    Serial.print(left);
    Serial.print("cm left");
    Serial.println();

    Serial.print(centar);
    Serial.print("cm centar");
    Serial.println();

    Serial.print(righ);
    Serial.print("cm righ");
    Serial.println();

*/

    //-----------------------------------------------------------------------------




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

/*
    digitalWrite(L_IN1, 1); 
    digitalWrite(L_IN2, 0);
    digitalWrite(R_IN3, 0);
    digitalWrite(R_IN4, 1);

*/
    }

   Serial.println();
  delay(2000);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}


void leftMove() {
  digitalWrite(L_IN1, 1);
  digitalWrite(L_IN2, 0);
  Serial.println("leftMoveleftMoveleftMoveleftMoveleftMoveleftMoveleftMoveleftMoveleftMove");
  digitalWrite(R_IN3, 0);
  digitalWrite(R_IN4, 0);

  delay(550);
}

void rightMove() {

  digitalWrite(L_IN1, 0);
  digitalWrite(L_IN2, 0);
  Serial.println("rightMoverightMoverightMoverightMoverightMoverightMoverightMoverightMove");
  digitalWrite(R_IN3, 0);
  digitalWrite(R_IN4, 1);
  delay(550);

}

void StoptMove() {
  digitalWrite(L_IN1, 1);
  digitalWrite(L_IN2, 1);

  digitalWrite(R_IN3, 1);
  digitalWrite(R_IN4, 1);

}


void Move() {
  digitalWrite(L_IN1, 1); // 
  digitalWrite(L_IN2, 0);

  digitalWrite(R_IN3, 0);
  digitalWrite(R_IN4, 1);
}


void BackMove() {
  digitalWrite(L_IN1, 0); //
  digitalWrite(L_IN2, 1);

  digitalWrite(R_IN3, 1);
  digitalWrite(R_IN4, 0);
}