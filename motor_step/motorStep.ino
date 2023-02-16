#include <Stepper.h> //INCLUSÃO DE BIBLIOTECA
const int botao=3;
const int ledVermelho = 6; 
const int ledVerde = 5; 
const int ledAzul = 4; 

const int stepsPerRevolution = 64; //NÚMERO DE PASSOS POR VOLTA
 
Stepper myStepper(stepsPerRevolution, 8,10,9,11); //INICIALIZA O MOTOR UTILIZANDO OS PINOS DIGITAIS 8, 9, 10, 11

boolean estadoCorrente = LOW;
boolean estadoAnterior=LOW;
boolean ledOn = false;
int var = 1;
int aux = 0;
void setup(){
  myStepper.setSpeed(300); //VELOCIDADE DO MOTOR
  Serial.begin(115200);
  pinMode(ledVermelho,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAzul,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
}
void loop(){
  /*//LAÇO "for" QUE LIMITA O TEMPO EM QUE O MOTOR GIRA NO SENTIDO ANTI-HORÁRIO      
  for(int i = 0; i < 50; i+=2){ //PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE 50 INCREMENTA "i"
          myStepper.step(stepsPerRevolution); //GIRA O MOTOR NO SENTIDO ANTI-HORÁRIO
  }
   //LAÇO "for" QUE LIMITA O TEMPO EM QUE O MOTOR GIRA NO SENTIDO HORÁRIO            
  for(int i = 0; i < 50; i+=2){//PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE 50 INCREMENTA "i"
          myStepper.step(-stepsPerRevolution); //GIRA O MOTOR NO SENTIDO HORÁRIO
  }*/
  
  if(var > 0) myStepper.step(stepsPerRevolution);
  else if (var < 0) myStepper.step(-stepsPerRevolution);

  estadoCorrente = debounce(estadoAnterior);
  if (estadoAnterior==LOW && estadoCorrente==HIGH){ 
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledVermelho,LOW);
    digitalWrite(ledAzul,LOW);
    var *= -1;
    delay(500);
  }
  
  estadoAnterior = estadoCorrente;
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,HIGH);
  digitalWrite(ledAzul,HIGH);

  aux++;
}
boolean debounce(boolean estadoAnterior){ // Função debounce
  boolean corrente = digitalRead(botao);
  if( estadoAnterior!= corrente){
  delay(5);
  corrente = digitalRead(botao);
  }
  return corrente;
}
