 
//ultrasonic sensor pin define
const int trigpin1 = 2;
const int echopin1 = 3;

const int trigpin2 = 4;
const int echopin2 = 5;

const int trigpin3 = 6;
const int echopin3 = 7;


void setup() {

Serial.begin(9600);

pinMode(trigpin1,OUTPUT);
pinMode(echopin1,INPUT);

pinMode(trigpin2,OUTPUT);
pinMode(echopin2,INPUT);

pinMode(trigpin3,OUTPUT);
pinMode(echopin3,INPUT);


}
//funtion for read data and trig sensor 

float getdistance(int trigpin,int echopin){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  long duration = pulseIn(echopin,HIGH,30000);
  if(duration = 0){
    return -1;
  }
  return duration*0.0343/2.0;
}



void loop() {

float d1 = getdistance(trigpin1,echopin1);

Serial.print("distance1:");

if(d1<0){
  Serial.print("NO object");
}
else{
  Serial.print(d1);
}

float d2 = getdistance(trigpin2,echopin2);

Serial.print("distance2:");

if(d2<0){
  Serial.print("NO object");
}
else{
  Serial.print(d2);
}

float d3 = getdistance(trigpin3,echopin3);

Serial.print("distance3:");

if(d3<0){
  Serial.print("NO object");
}
else{
  Serial.print(d3);
}
delay(500);
}
