#define ctl 3
#define in1 12 //7
#define in2 11 //6

#define ctr 5
#define in3 10 //5
#define in4 9 //4

#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0

char t;
 
void setup() {
  pinMode(ctl,OUTPUT);
  pinMode(in1,OUTPUT);   //left motors forward 13 7
  pinMode(in2,OUTPUT);   //left motors reverse 12 6

  pinMode(ctr,OUTPUT);
  pinMode(in3,OUTPUT);   //right motors forward 11 5
  pinMode(in4,OUTPUT);   //right motors reverse 10 4
  
  Serial.begin(9600);
 
}
 
void loop() {
  if(Serial.available()){
    t = Serial.read();
    Serial.println(t);
  }
    //FLM(225);
    //FRM(255);
   
  if(t == 'F'){            //move forward
    FLM(255);
    FRM(255);
  }
   
  else if(t == 'B'){      //move reverse
    BLM(130);
    BRM(130);
  }
   
  else if(t == 'R'){      //turn left 
    BLM(120);
    FRM(120);
  }

  else if(t== 'I'){
    FLM(45);
    FRM(255);
  }

  else if(t== 'J'){
    BLM(45);
    BRM(255);
  }
   
  else if(t == 'L'){      //turn right
    FLM(120);
    BRM(120);
  }

  else if(t== 'G'){
    FLM(255);
    FRM(60);
  }

  else if(t== 'H'){
    BLM(255);
    BRM(60);
  }
   
  else if(t == 'S'){      //STOP (all motors stop)
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }
  delay(10);

//  analogWrite(ctl,255);
//  digitalWrite(in1,HIGH);
//  digitalWrite(in4,HIGH);
//  delay(100);
}

void FLM(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(ctl,speed);
  digitalWrite(in1,HIGH);
}
void FRM(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(ctr,speed);
  digitalWrite(in3,HIGH);
}

void BLM(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(ctl,speed);
  digitalWrite(in2,HIGH);
}
void BRM(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(ctr,speed);
  digitalWrite(in4,HIGH);
}
