const int lf=9;///rfontleft
const int lb=8;///backleft
const int rb=7;///backright
const int rf=6;//rfont right
int trigPin = 2;      
int echoPin = 3;
int duration;
int distance;

void setup() {
  delay(random(500,2000));
  pinMode(lf,OUTPUT);
  pinMode(rf,OUTPUT);
  pinMode(lb,OUTPUT);
  pinMode(rb,OUTPUT);  
  Serial.begin(9600);

  
}


void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);   
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;  
  delay(10);
   Serial.println(distance);
  if (distance > 19)            
  {
    digitalWrite(rf, HIGH);                    // move forward
    digitalWrite(rb, LOW);
    digitalWrite(lf, HIGH);                                
    digitalWrite(lb, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(rf, LOW);  //Stop                
    digitalWrite(rb, LOW);
    digitalWrite(lf, LOW);                                
    digitalWrite(lb, LOW);
    delay(500);
    digitalWrite(rf, LOW);      //movebackword         
    digitalWrite(rb, HIGH);
    digitalWrite(lf, LOW);                                
    digitalWrite(lb, HIGH);
    delay(500);
    digitalWrite(rf, LOW);  //Stop                
    digitalWrite(rb, LOW);
    digitalWrite(lf, LOW);                                
    digitalWrite(lb, LOW);  
    delay(100);  
    digitalWrite(rf, HIGH);       
    digitalWrite(rb, LOW);   
    digitalWrite(lb, LOW);                                 
    digitalWrite(lf, LOW);  
    delay(500);
  }

}
