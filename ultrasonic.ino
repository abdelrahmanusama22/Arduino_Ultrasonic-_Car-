#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define trig 8
#define echo 9
long duration,distance;
void setup() 
{
 for(int i=4;i<=8;i++)
  {
    pinMode(i,OUTPUT);
  }  
  pinMode(echo,INPUT);

}
void ultrasonic()
{
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
duration= pulseIn(echo,HIGH);
distance=(duration/2)*0.0343;
}
void forword()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}
void backword()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);  
}
void left()
{
  digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}
void right()
{
  digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}
void stopp()
{
  digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}

void loop() 
{
 ultrasonic();
 if(distance<20)
 {
  stopp();
  delay(250);
  left();
  delay(400);
 }
 else
 {
  forword();
 }
}
