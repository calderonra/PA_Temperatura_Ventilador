#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
int frecuencia = 220;      // frecuencia correspondiente a la nota La
float tempe=0;
int motor=9;

int sonido=13; 

int led1=12;
int led2=11;
void setup(){
   pinMode(motor,OUTPUT);
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  
 digitalWrite(motor,LOW);
 digitalWrite(led1,LOW);
 digitalWrite(led2,LOW);
}//end "setup()"
 
void loop(){
  //Start of Program 
    DHT.read11(dht_apin);
        tempe=DHT.temperature;

    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

    if(tempe>=26){
       digitalWrite(motor,1);
       tone(sonido,frecuencia);    // inicia el zumbido
       digitalWrite(led2,1);
       digitalWrite(led1,0);
    }
    else if(tempe<=25){
       digitalWrite(motor,0);
       noTone(sonido);               // lo detiene a los dos segundo
       digitalWrite(led2,0);
       digitalWrite(led1,1);
       
    }
   
    delay(2000);                    
    
    //delay(1000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 
