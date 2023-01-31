#include <TM1637Display.h>
int pinLed = 6;
const int CLK = 3;
const int DIO = 2;
TM1637Display display(CLK, DIO);
const byte sensor = A2;      //Pino analÃ³gico em que o sensor estÃ¡ conectado.
int valorSensor = 0; //Usada para ler o valor do sensor em tempo real.
int tempoDepois = 0;
void setup() {
  pinMode(pinLed,OUTPUT);
  analogWrite(pinLed,0);
  display.setBrightness(5);
  display.showNumberDec(0, false, 4, 4);
}

void loop() {
    valorSensor = analogRead(sensor);
    display.showNumberDec(tempoDepois, false, 4, 4);
    int tempoAntes = millis();
     if (valorSensor>850){              
      analogWrite(pinLed,HIGH);
     }
     int tempoDepois = millis() - tempoAntes;
     if(tempoDepois >= 2000){
      digitalWrite(pinLed, LOW);
      tempoDepois = 0;
     }    
    delay(5000);
}
