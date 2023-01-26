#include <Servo.h>
enum state{esquerda = 0,direita};

Servo servo01;
int state = direita;
int pos = 0;
const int botao=2;
boolean estadoCorrente = LOW;
boolean estadoAnterior=LOW;
int var = 1;
void setup() {
  Serial.begin(115200);
  pinMode(2,INPUT_PULLUP);
  Serial.println("B4H - Servicos em Computacao - Servo-Motor");  
  servo01.attach(5);       // Controle no pino D5   
}
void loop() {
  Serial.println(pos);         
  estadoCorrente = debounce(estadoAnterior);
  if (estadoAnterior==LOW && estadoCorrente==HIGH){
    if(state == direita) state = esquerda;
    else if(state == esquerda) state = direita;
  }
  estadoAnterior = estadoCorrente;
  if(pos < 170 && state == direita){
    pos++;
    servo01.write(pos);     
    Serial.println(pos);  
    delay(30);   
  }
  else{
    state == esquerda;
  }
  if(pos > 10 && state == esquerda){
    pos--;
    servo01.write(pos);     
    Serial.println(pos);  
    delay(30); 
  }else{
    state == direita;
  }
}

boolean debounce(boolean estadoAnterior){ // Função debounce
  boolean corrente = digitalRead(botao);
  if( estadoAnterior!= corrente){
  delay(5);
  corrente = digitalRead(botao);
  }
  return corrente;
}
