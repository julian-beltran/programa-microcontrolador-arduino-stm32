//#define ECHO =(PA1);
//#define TRIGGER =(PA2);

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
          Serial.print("pare");
          Serial.println();
          delay(1000);
          
          digitalWrite(PA4, LOW);
          delay(1000);
          
          
          } else   if(d>20 && d<40){
                    Serial.print("advertencia");
                    Serial.println();
                    delay(1000);
          
                    digitalWrite(PA4, HIGH);
                    delay(100);
                    digitalWrite(PA4, LOW);
                    delay(100);  
                    }else
                         digitalWrite(PA4, HIGH);
       
}


//Serial.print("Distancia: ");
  //Serial.print(d);      
  //Serial.print("cm");
  //Serial.println();
  //delay(100);
