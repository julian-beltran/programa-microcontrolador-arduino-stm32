const int Trigger = PA2;   
const int Echo = PA1;   
long t; 
long d; 
const int zum=PA3; 
const int Led = PA4; 
int cont=0;


//Contador personas CC

void setup() {

  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(zum, OUTPUT);
  pinMode (Led, OUTPUT);

  
  

}

void loop() {
  // put your main code here, to run repeatedly:

  distancia();
  
char leer = Serial.read();

  

  
    Serial.print("Personas: ");
    Serial.print(cont);
    Serial.println();
  
  
  if(d<8){
   

      cont++;
      encenderLed();
      sonar();
      delay(1000);
      
     
    
  }else
  digitalWrite(zum, HIGH);
  delay(100);
  digitalWrite(Led,HIGH);
  delay(100);
  


}

void distancia(){

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  

}

void sonar()
{
  
  digitalWrite(zum, HIGH);
  delay(100);
  digitalWrite(zum, LOW);
  delay(100);
  
}

void encenderLed()
{

  digitalWrite(Led,HIGH);
  delay(100);
  digitalWrite(Led,LOW);
  delay(100);
  
  
}
