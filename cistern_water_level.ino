/* cistern water level gauge using a ultrasonic sensor for distance and displaying on a grove led
bar, cistern empty displays just the red led on the grove bar more than 45" to the water, cistern full displays all ten leds lit, 
at 5" to the water, less than 2" to the water is danger of overflowing all leds will blink ON/OFF 
Connect +5v and GND normally and trigger pin to 12 & echo pin to 13. 
*/

#include <Grove_LED_Bar.h>
Grove_LED_Bar bar(6, 7, 0); 
#define trigPin 12
#define echoPin 13

float speedofsound = .0135039; //inches per usec
int distance, duration, x; //in inches

void setup() {
        Serial.begin (9600); 
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
         bar.begin();
}

void loop() {
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) * speedofsound;
   Serial.print(distance);
   Serial.println("inches \n");
   
    delay(100);

if (distance <= 4 ) {
  
   x=0;
   while (x < 10){
    x++;
      bar.setBits(0x3FF); // led 1,2,3,4,5,6,7,8,9,10
     delay(100);
      bar.setBits(0x0); // all off
      delay(100);
       }
   }
   else if (distance <= 6)
   {
    bar.setBits(0x3FF);   
   }
  else if (distance <= 11)
  {
       bar.setBits(0x1FF); //led 1,2,3,4,5,6,7,8,9
    delay(100);
 }
 else if (distance <= 16)
 {
    bar.setBits(0xFF); //led 1,2,3,4,5,6,7,8
     delay(100);
 }
 else if (distance <=21)
 {
  bar.setBits(0x7F); //led 1,2,3,4,5,6,7
   delay(100);
 }
else if (distance <= 26)
{
  bar.setBits(0x3F); //led 1,2,3,4,5,6
   delay(100);
}
else if (distance <= 31)
{
  bar.setBits(0x1F); //led 1,2,3,4,5
   delay(100);
}
else if (distance <= 36)
{
  bar.setBits(0x0F); //led 1,2,3,4
   delay(100);
}
else if (distance <= 41)
{
  bar.setBits(0x07); //led 1,2,3
   delay(100);
}
else if (distance <= 45)
{
  bar.setBits(0x03); //led 1,2
   delay(100);
}
else if (distance > 45)
{
  bar.setBits(0x01); // led 1
   delay(100);
}


}
 
