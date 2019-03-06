class ultrasonicSensor {

  private:
     int pingPin  ;
    long Time , dis;

 
  
  public: ultrasonicSensor(int a) {
      pingPin = a;

    }
    

    long getDistance() {
      pinMode(pingPin, OUTPUT);
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPin, LOW);
      pinMode(pingPin, INPUT);

      Time  = pulseIn(pingPin, HIGH);
      dis = microsecondsToCentimeters(Time);
      return dis;
    }


  private: long microsecondsToCentimeters(long microseconds) {
      // The speed of sound is 340 m/s or 29 microseconds per centimeter.
      // The ping travels out and back, so to find the distance of the object we
      // take half of the distance travelled.
      return microseconds / 29 / 2;
    }







};
