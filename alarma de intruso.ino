
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PA2, OUTPUT);//echo 
  pinMode(PA1, INPUT); //trigger 
  pinMode(PA3, OUTPUT);//pin del zumbador
  pinMode(PA4,OUTPUT);//pin del led
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
                    
                    Serial.print("advertencia");
                    Serial.println();
                    delay(1000);
          
                    digitalWrite(PA4, HIGH);
                    delay(100);
                    digitalWrite(PA4, LOW);
                    delay(100);  
                    digitalWrite(PA3, LOW);
  }else
  digitalWrite(PA3, HIGH);
  digitalWrite(PA4, HIGH);

}
