int analogPin = A0;     // analog pin A3
int pinLED =5;
                          
int val = 0;              // variÃ¡vel para armazenar o valor lido

void setup(){
  Serial.begin(115200); // Inicia a saÃ­da serial com 115200bpi
  pinMode(pinLED, OUTPUT); 
}

void loop(){
  val = analogRead(analogPin);     // lÃª o valor analÃ³gico
  Serial.println(val);                       // apresenta o valor na saÃ­da serial
  
  //val = map (val,0,1023,0,255);
  analogWrite(pinLED,map (val,0,1023,0,255));
  delay(500);
}
