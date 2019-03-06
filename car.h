class car {


  private:
    int R_IN4 ;
    int R_IN3 ;
    int L_IN2 ;
    int L_IN1 ;

    public:   car(int x , int y , int z , int w  ) {
      R_IN4 = x;
      R_IN3 = y;
      L_IN2 = z;
      L_IN1 = w;
    }


    //=============================================================================================
  public: 
  
  int getR_IN4(){
    return  R_IN4;
  }

   int getR_IN3(){
    return   R_IN3;
  }

   int getL_IN2(){
    return  L_IN2;
  }

   int getL_IN1(){
    return  L_IN1;
  }
  
  
 public: void leftMove() {
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
      digitalWrite(L_IN1, 1); //عكس عقارب الساعة
      digitalWrite(L_IN2, 0);

      digitalWrite(R_IN3, 0);
      digitalWrite(R_IN4, 1);
    }


    void BackMove() {
      digitalWrite(L_IN1, 0); // مع عقارب الساعة
      digitalWrite(L_IN2, 1);

      digitalWrite(R_IN3, 1);
      digitalWrite(R_IN4, 0);
    }
};
