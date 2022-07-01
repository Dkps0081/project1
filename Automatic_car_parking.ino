#include<LiquidCrystal.h>
#include<Servo.h>
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo servo;
int sensor1 = 6;
int sensor2 = 7;
int x = 4;
int rs = 12 , rw = 11 , enable = 10 , d4 = 5 , d5 = 4 , d6 = 3 , d7 = 2 ;
LiquidCrystal lcd(rs , rw , enable , d4 , d5 , d6 , d7);
void setup() {
  // put your setup code here, to run once:
   pinMode( sensor1 , INPUT) ;
   pinMode( sensor2 , INPUT) ;
   servo.attach(9);
   lcd.begin( 16 , 4);
   lcd.print("Total slots : 4 " );
   lcd.setCursor(0,1);
   lcd.print("Vacant slots : " ); 
   lcd.setCursor(15 ,1 );
   lcd.print(x) ;
   servo.write(0);
   Serial.begin(9600);   // Initiate a serial communication
   SPI.begin();      // Initiate  SPI bus
   mfrc522.PCD_Init();   // Initiate MFRC522
   Serial.println("Approximate your card to the reader...");
   Serial.println();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sensor1) == LOW && x == 0){
    lcd.clear();
    lcd.print("No slots left");
  }
  if(digitalRead(sensor1) == LOW && servo.read() == 0 && x > 0){
   // unsigned long StartTime = millis();
//      while(digitalRead(sensor2) == LOW) {
//      delay(50);
//      
//    }
    x = x - 1;
    delay(500);
    servo.write(90);
    lcd.begin( 16 , 2);
    lcd.print("Total slots : 4 " );
    lcd.setCursor(0,1);
    lcd.print("Vacant slots : " ); 
    lcd.setCursor(15 ,1 );
    lcd.print(x) ;
  }
  else if(digitalRead(sensor1) == LOW && servo.read() == 90){
   // unsigned long CurrentTime = millis();
//    while(digitalRead(sensor1) == LOW) {
//      delay(50);
//    }
    delay(500);
     servo.write(0);
  }
  delay(500);
  
  if(digitalRead(sensor2) == LOW && servo.read() == 90){
   // unsigned long CurrentTime = millis();
//    while(digitalRead(sensor2) == LOW) {
//      delay(50);
//      
//    }
    delay(500);
     servo.write(0);
  }
  
 // if(abs(CurrentTime - StartTime) < 10000 )
    else if(digitalRead(sensor2) == LOW && servo.read() == 0  ){
   // unsigned long StartTime = millis();
    if (x < 4){
//        while(digitalRead(sensor2) == LOW) {
//           delay(50);
//      
//    }
    x = x + 1;
    delay(500);
    servo.write(90);
    lcd.begin( 16 , 2);
    lcd.print("Total slots : 4 " );
    lcd.setCursor(0,1);
    lcd.print("Vacant slots : " ); 
    lcd.setCursor(15 ,1 );
    lcd.print(x) ;
    }
  }
  delay(1000);
  
  
  
  
}