//RGB LED + 3 x 220 Ohm Resistors + HC SRO Ultrasonic Range finder
//Displays Red light for distances 12" and over
//Displays Green light for distances 3"-12"
//Displays Blue light for distances less than 3"


#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
float a;
int dly=25;

int B=8;
int G=9;
int R=10;

void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(B, OUTPUT);
   pinMode(G, OUTPUT);
   pinMode(R, OUTPUT);

}

void loop() {
   
   a=sr04.Distance()/2.54;
   

while (a<=3) {
   
   a=sr04.Distance()/2.54;
   
   Serial.print(a);
   Serial.println(" inches a<3");
   delay(dly);

  digitalWrite (B, HIGH);
  digitalWrite (G, LOW);
  digitalWrite (R, LOW);
} //ends "if"

while (a>3 && a<=12) {
   
   a=sr04.Distance()/2.54;
   
   Serial.print(a);
   Serial.println(" inches 3<a<12");
   delay(dly);
  
  digitalWrite (B, LOW);
  digitalWrite (G, HIGH);
  digitalWrite (R, LOW);
}//ends "if"

while (a>12) {

   a=sr04.Distance()/2.54;
   
   Serial.print(a);
   Serial.println(" inches a>12");
   delay(dly);

  digitalWrite (B, LOW);
  digitalWrite (G, LOW);
  digitalWrite (R, HIGH);
}//ends "if"

}
