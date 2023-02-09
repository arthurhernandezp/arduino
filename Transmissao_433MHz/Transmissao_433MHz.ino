#include <VirtualWire.h>

String mensagem;


void setup(){
  Serial.begin(115200);  
  vw_set_tx_pin(8);
  vw_setup(2000);   // Bits per sec
  
}
 
void loop(){
  String dado="L";
  char data[2];    
    
    dado.toCharArray(data,2);  
    
    Serial.print("Enviado : ");    
    Serial.println(data);    
    send(data);
    delay(30000);
  
} 
 
void send (char *message){
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Aguarda o envio de dados
}
