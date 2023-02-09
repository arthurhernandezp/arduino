#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 3
#define DIO 2
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

TM1637Display tm(CLK, DIO);
//Array que desenha o simbolo de grau
const uint8_t graus[] { SEG_A | SEG_B | SEG_F | SEG_G , SEG_A | SEG_D | SEG_E | SEG_F };

double temp_amb;
double temp_obj;
int led = 10;
const int botao=7;
boolean estadoCorrente = LOW;
boolean estadoAnterior=LOW;
void setup()
{
  Serial.begin(115200);
  Serial.println("Sensor de temperatura MLX90614");
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
  //Inicializa o MLX90614
  mlx.begin();
  tm.setBrightness(3);
  tm.clear(); 
  
}

void loop()
{
  estadoCorrente = debounce(estadoAnterior);
  if (estadoAnterior==LOW && estadoCorrente==HIGH){
    //Leitura da temperatura ambiente e do objeto
    temp_amb = mlx.readAmbientTempC();
    temp_obj = mlx.readObjectTempC();
    int whole = (int)temp_obj;
    int decimal = (temp_obj - whole) * 10;

    digitalWrite(led,LOW);
    
    //Mostra as informacoes no display
    tm.showNumberDecEx(whole*10+decimal,0b11100000, true, 3, 0);
    tm.setSegments(graus, 1, 3);
    delay(10000);
  }
  tm.clear(); 

  estadoAnterior = estadoCorrente;
  digitalWrite(led,HIGH);
}

boolean debounce(boolean estadoAnterior){ // Função debounce
  boolean corrente = digitalRead(botao);
  if( estadoAnterior!= corrente){
  delay(5);
  corrente = digitalRead(botao);
  }
  return corrente;
}
