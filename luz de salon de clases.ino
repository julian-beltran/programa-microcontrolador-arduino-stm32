
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PA2, OUTPUT); 
  pinMode(PA1, INPUT);  
  pinMode(PA4, OUTPUT);
  digitalWrite(PA2, LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  long t; 
  long d; 
  
  digitalWrite(PA2, HIGH);
  delayMicroseconds(10);       
  digitalWrite(PA2, LOW);  
   
  t = pulseIn(PA1, HIGH); 
  d = t/59; 
  if(d>0 && d<20){
                    
                    digitalWrite(PA4, LOW);
                    delay(30000);
  }else
  digitalWrite(PA4, HIGH);

}
