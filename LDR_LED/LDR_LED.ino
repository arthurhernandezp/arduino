
const byte sensor = A2;      //Pino analÃ³gico em que o sensor estÃ¡ conectado.
const byte ledVermelho = 4;
int valorSensor = 0; //Usada para ler o valor do sensor em tempo real.


void setup () {
  Serial.begin(115200);
  pinMode(ledVermelho,OUTPUT);  
  digitalWrite(ledVermelho, LOW);  
}

void loop () { 
    valorSensor = analogRead(sensor);
    Serial.println(valorSensor);          

     if (valorSensor>850){              
      digitalWrite(ledVermelho, HIGH); 

     }
     else{
      digitalWrite(ledVermelho, LOW);
     }

    delay(1000);
}
      
