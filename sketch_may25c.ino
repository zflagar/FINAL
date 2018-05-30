#define IRSensor1 7
#define IRSensor2 8
#define IRSensor3 9
#define IRSensor4 10
#define IRSensor5 11
#define IRSensor6 12
#define IRLed1 1
#define IRLed2 2
#define IRLed3 3
#define IRLed4 4
#define IRLed5 5
#define IRLed6 6
#define LedFrekvence 1000
#define printFrekvence 500
#define PAUSE 10

int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond

bool IR1,IR2,IR3,IR4,IR5,IR6;
bool ch1=true,ch2=true,ch3=true,ch4=true,ch5=true,ch6=true; //change

String debug;
void Debug();
int irRead(int readPin, int triggerPin);

void setup()
{
  for(int i=1;i<=6;i++){
    pinMode(i, OUTPUT);
  }
  for(int i=7;i<=12;i++){
    pinMode(i, INPUT);
  }
  Serial.begin(9600);  
  Serial.println("Program Starting"); 
  delay(1000); 
}

void loop()
{ 
  delay(10);
  IR1=irRead(IRSensor1, IRLed1);
  IR2=irRead(IRSensor2, IRLed2);
  IR3=irRead(IRSensor3, IRLed3);
  IR4=irRead(IRSensor4, IRLed4);
  IR5=irRead(IRSensor5, IRLed5);
  IR6=irRead(IRSensor6, IRLed6);
  Debug();
  if(IR1==0 and ch1==true){
    ch1=!ch1;
    Serial.println("1.sensor");
  }
  else if (IR1==1 and ch1==false){
    ch1=!ch1;
  }
  else if(IR2==0 and ch2==true){
    ch2=!ch2;
    Serial.println("2.sensor");
  }
  else if (IR2==1 and ch2==false){
    ch2=!ch2;
  }
  else if(IR3==0 and ch3==true){
    ch3=!ch3;
    Serial.println("3.sensor");
  }
  else if (IR3==1 and ch3==false){
    ch3=!ch3;
  }
  else if(IR4==0 and ch4==true){
    ch4=!ch4;
    Serial.println("4.sensor");
  }
  else if (IR4==1 and ch4==false){
    ch4=!ch4;
  }
  else if(IR5==0 and ch5==true){
    ch5=!ch5;
    Serial.println("5.sensor");
  }
  else if (IR5==1 and ch5==false){
    ch5=!ch5;
  }
  else if(IR6==0 and ch6==true){
    ch6=!ch6;
    Serial.println("6.sensor");
  }
  else if (IR6==1 and ch6==false){
    ch6=!ch6;
  }
}

int irRead(int readPin, int triggerPin)
{
  for (int i=0; i <=cycles; i++)
  {
    digitalWrite(triggerPin, HIGH); 
    delayMicroseconds(halfPeriod);
    digitalWrite(triggerPin, LOW); 
    delayMicroseconds(halfPeriod - 1);     // - 1 to make up for digitaWrite overhead    
  }
  return digitalRead(readPin);
}
void Debug(){
  if(Serial.available() > 0){
    debug = Serial.readString();
    if (debug=="debug"){
      for(int i=1;i<=10;i++){
        Serial.print(irRead(IRSensor1, IRLed1));
        Serial.print(irRead(IRSensor2, IRLed2));
        Serial.print(irRead(IRSensor3, IRLed3));
        Serial.print(irRead(IRSensor4, IRLed4));
        Serial.print(irRead(IRSensor5, IRLed5));
        Serial.println(irRead(IRSensor6, IRLed6));
        
      }
    }
  }
}

