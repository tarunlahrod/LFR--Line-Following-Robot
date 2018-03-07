  
 
//CODE FOR LFR WITH THREE IR SENSORS 


#define ln 8       // negative of left motor
#define lp 9       // positive of left motor
#define rp 6       // positive of right motor
#define rn 7       // negative of right motor



void setup() 
{
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT); 
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(3,INPUT);
 pinMode(4,INPUT);
 pinMode(5,INPUT);
}

void straight()
{
  analogWrite(lp,128);
  analogWrite(ln,128);
  analogWrite(rp,128);
  analogWrite(rn,128);
 digitalWrite(lp,HIGH);
 digitalWrite(rp,HIGH);
 digitalWrite(ln,LOW);
 digitalWrite(rn,LOW); 
}

void stp()
{
    analogWrite(lp,128);
  analogWrite(ln,128);
  analogWrite(rp,128);
  analogWrite(rn,128);
  digitalWrite(lp,LOW);
  digitalWrite(rp,LOW);
  digitalWrite(ln,LOW);
  digitalWrite(rn,LOW);
  
}

void slightLeft()
{
    analogWrite(lp,128);
  analogWrite(ln,128);
  analogWrite(rp,128);
  analogWrite(rn,128);
 digitalWrite(lp,LOW);
 digitalWrite(rp,HIGH);
 digitalWrite(ln,LOW);
 digitalWrite(rn,LOW); 
}

void slightRight()
{
    analogWrite(lp,128);
  analogWrite(ln,128);
  analogWrite(rp,128);
  analogWrite(rn,128);
 digitalWrite(lp,HIGH);
 digitalWrite(rp,LOW);
 digitalWrite(ln,LOW);
 digitalWrite(rn,LOW); 
}

void hardRight()
{
    analogWrite(lp,128);
  analogWrite(ln,128);
  analogWrite(rp,128);
  analogWrite(rn,128);
 digitalWrite(lp,HIGH);
 digitalWrite(rp,LOW);
 digitalWrite(ln,LOW);
 digitalWrite(rn,HIGH); 
  
}

void hardLeft()
{
    analogWrite(lp,128);
  analogWrite(ln,128);
  analogWrite(rp,128);
  analogWrite(rn,128);
 digitalWrite(lp,LOW);
 digitalWrite(rp,HIGH);
 digitalWrite(ln,HIGH);
 digitalWrite(rn,LOW);   
}

void lost()
{
    analogWrite(lp,128);
  analogWrite(ln,128);
  analogWrite(rp,128);
  analogWrite(rn,128);
 digitalWrite(lp,HIGH);
 digitalWrite(rp,HIGH);
 digitalWrite(ln,LOW);
 digitalWrite(rn,LOW);   
}




void loop() 
{

// taking input from the sensors

 int  left = digitalRead(3);  //LEFT SENSOR in the moving direction
 int  mid = digitalRead(4);   //MIDDLE SENSOR in the moving direction
 int  right = digitalRead(5); //RIGHT SENSOR in the moving direction
 

 int move = (left*4) + (mid*2) + (right) ;    //making a simple algo for differentiating each case and hence use switch case

// using switch case for better efficiency 

switch (move)        
{
  case 0: stp(); break;
  case 1: hardLeft(); break;
  case 2: straight(); break;   //this case '010' does not exist, still taking under consideration.
  case 3: slightLeft(); break;
  case 4: hardRight(); break;
  case 5: straight(); break;
  case 6: slightRight(); break;
  case 7: lost(); break;
}
              

} //end of loop()
