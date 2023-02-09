void setup(void){
  Serial.begin(115200);   //ATENÃ‡ÃƒO
  Serial.println("UERJ-FAPERJ - Exemplo print() println()");
}

void loop(void){

  Serial.println("Testando a saida serial!");
  Serial.println(1809);
  Serial.println(1809,DEC);
  Serial.println(1809,OCT);
  Serial.println(1809,HEX);
  Serial.println(1809,BIN);
  Serial.println(1.23456,2);
  Serial.println(1.23456,3);
  Serial.println(1.23456,4);

  delay(5000);
   
}
