#include <Servo.h> 
Servo Myservo;
#define trigPin 9          
#define echoPin 8        
#define MLa 4            
#define MLb 5            
#define MRa 6            
#define MRb 7            
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(MLa, OUTPUT);   
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);E
  pinMode(trigPin, OUTPUT);    
  pinMode(echoPin, INPUT);      
  Myservo.attach(20);
}
void loop() 
{
  Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);    
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);       
  distance = duration / 58.2;               
  Serial.println(distance);
  delay(10);
  if (distance > 20)            
  {
    Myservo.write(90);
    digitalWrite(MRb, HIGH);    
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);                                                       
  }
  else if ((distance < 20)&&(distance > 0))     
  {
    digitalWrite(MRb, LOW);               
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);
    delay(100);
    
    Myservo.write(0);
    delay(500);
    Myservo.write(180);
    delay(500);
    Myservo.write(90);
    delay(500);
    
    digitalWrite(MRb, LOW);                
    digitalWrite(MRa, HIGH);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, HIGH);
    delay(500);
    digitalWrite(MRb, LOW);                      
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);  
    delay(100);  
    digitalWrite(MRb, HIGH);       
    digitalWrite(MRa, LOW);   
    digitalWrite(MLa, LOW);                                 
    digitalWrite(MLb, LOW);  
    delay(500);
  }

}
