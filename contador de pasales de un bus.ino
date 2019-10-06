const int Trigger = PA2;   //Pin digital PA6 para el Trigger del sensor
const int Echo = PA1;   //Pin digital PA% para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros
const int zum=PA3; //Zumbador
const int Led = PA4; //Led pc13
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

  

    int valor= cont*3000;
    Serial.print("Personas: ");
    Serial.print(cont);
    Serial.print("  pasaje: ");
    Serial.print(valor);
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
