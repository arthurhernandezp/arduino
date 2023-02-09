const int ledPin = 13; 
int dado; //variÃ¡vel que receberÃ¡ os dados da porta serial

void setup(){
  Serial.begin(115200);//frequÃªncia da porta serial
  pinMode(ledPin,OUTPUT); //define o pino o ledPin como saÃ­da
}

void loop(){
  if(Serial.available() > 0){ //verifica se existe comunicaÃ§Ã£o com a porta serial
    
      dado = Serial.parseInt();//lÃª os dados da porta serial
      Serial.println(dado);
      switch(dado){
        case 1:
           digitalWrite(ledPin,HIGH); //liga o pino ledPin           
        break;
        case 2:
           digitalWrite(ledPin,LOW); //desliga o pino ledPin          
         break;
    }
  }
}
