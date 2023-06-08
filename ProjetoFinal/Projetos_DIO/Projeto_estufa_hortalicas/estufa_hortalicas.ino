int tmp = 0;
int motor = 7;
int led = 4;
int valorTMP = 0;
void setup()
{
  pinMode(motor, OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  valorTMP= analogRead(tmp);
  Serial.print("valorTMP: ");
  Serial.println(valorTMP);
  if(valorTMP >= 164){
  	digitalWrite(motor,HIGH); 
  }else{
   	digitalWrite(motor,LOW);
  }
  if(valorTMP >=207){
    	digitalWrite(led,HIGH); 
  }else{
    	digitalWrite(led,LOW);
  }
}
