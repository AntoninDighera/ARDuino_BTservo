#include <Adafruit_NeoPixel.h>

//ArduinoBluetoothWithSmirfLED3Servos 

#include <SoftwareSerial.h> 
#include <Servo.h> 

SoftwareSerial BT(10, 11);        //TX, RX respectively

//Introducing Light stuff here

#define PIXEL_PIN 6
#define PIXEL_COUNT 16

//Introducing Servos

Servo servo1;                     //Team 1/4 Servo Name
Servo servo2;                     //Team 1/4 Servo Name
Servo servo3;                     //Team 2/5 Servo Name
Servo servo4;                     //Team 2/5 Servo Name
Servo servo5;                     //Team 3/6 Servo Name
Servo servo6;                     //Team 3/6 Servo Name

//Respective Servo Pins
const int servo1Pin = 0;          //Team 1/4 
const int servo2Pin = 0;          //Team 1/4 
const int servo3Pin = 0;          //Team 2/5 
const int servo4Pin = 0;          //Team 2/5 
const int servo5Pin = 0;          //Team 3/6 
const int servo6Pin = 0;          //Team 3/6 

//Variable holds info from Bluetooth 
String state;                

void setup() {
 
 BT.begin(115200);
 Serial.begin(9600);              // serial communication to check the data on serial monitor

//Led Light Strip Set Up 

strip.begin(); 
strip.show()    //initialize all pixels to off 


//Servo Setup 
//this can be turned into a function too

 servo1.attach(servo1Pin);    
 servo2.attach(servo2Pin);    
 servo3.attach(servo3Pin);    
 servo4.attach(servo4Pin);     
 servo5.attach(servo5Pin);    
 servo6.attach(servo6Pin);    

 servo1.write(90);     
 servo2.write(90);
 servo3.write(90);     
 servo4.write(90);
 servo5.write(90);     
 servo6.write(90);
}


//-----------------------------------------------------------------------//  
void loop() {
  
  while (BT.available()){         //Check if there is an available byte to read
  
    delay(10);                      //Delay added to make reads stable (a little like a spam block)
    char c = BT.read();             //Created a variable called 'c'                                 //Whenever 'c' is referenced it's the equivalent writing "BT.read()" #lazy
    state += c;                   
                                  
  }

  
  if (state.length() > 0) {       
                                  
    Serial.println(state);       
//Light Functions 

  if(state == "On")               {
    lightOn(); 
    Serial.println("On");   
      } 
  
  if(state == "Off"){   
    lightOff(); 
    Serial.println("Off"); 
     }  

//Servo Functions     
//Name of Servo Action 
 
 if(state == "S1"){       
    servo1Function(); 
    Serial.println ("S1");  
  }
  
//Name of Servo Action 

  if(state == "S2"){         
    servo2Function();  
    Serial.println ("S2"); 
  }

//Name of Servo Action 
  
  if(state == "S3"){         
    servo3Function(); 
    Serial.println ("S3");  
 
  }

//Name of Servo Action 

  if(state == "S4"){         
    servo4Function();
    Serial.println ("S4");  
  
  }

//Name of Servo Action

 if(state == "S5"){ 
  servo5Function();
  Serial.println ("S5");  
 
 }

//Name of Servo Action 
 
 if(state == "S6"){ 
  servo6Function(); 
  Serial.println ("S6"); 
 }
  
//Light Buttons 

if (state == "L1") {

 //run function for lights
 Serial.println = "L1";  
}

if (state == "L2") {
//run function for lights
 Serial.println = "L2";  

}

if (state == "L3") { 

//run function for lights 
 Serial.println = "L3";  

} 



}
  
  
state ="";                      //after loop finished change the value of the 'state' variable to blank and LOOP

}

} //Reset the variable

void lightOn(){
  //digitalWrite(13,HIGH); 
 
}

void lightOff(){
  //digitalWrite(13,LOW); 
  
}

void servo1Function (){ 
/*
  servo3.write(120);
    delay(2000);
    servo3.write(50);
    delay(1000);
    servo3.write(90); 
    Serial.println ("servo1Function"); 
*/
}

void servo2Function(){
  //content
   Serial.println ("servo2Function");
}

void servo3Function(){
  //content
   Serial.println ("servo3Function");
}

void servo4Function(){
  //content
   Serial.println ("servo4Function");
}

void servo5Function(){
  //content
   Serial.println ("servo5Function");
}

void servo6Function(){
  //content
   Serial.println ("servo6Function");
}

//LIGHT FUNCTIONS





void startShow(int i) {
  switch(i){
    case 0: colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
            break;
    case 1: colorWipe(strip.Color(255, 0, 0), 50);  // Red
            break;
    case 2: colorWipe(strip.Color(0, 255, 0), 50);  // Green
            break;
    case 3: colorWipe(strip.Color(0, 0, 255), 50);  // Blue
            break;
   case 4: colorWipe(strip.Color(150,150,150),50); // White
            break;
//    case 5: theaterChase(strip.Color(127,   0,   0), 50); // Red
//            break;
//    case 6: theaterChase(strip.Color(  0,   0, 127), 50); // Blue
//            break;
    case 7: rainbow(20);
            break;
    case 8: rainbowCycle(20);
            break;
    case 9: theaterChaseRainbow(50);
            break;
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint32_t Wheel(byte WheelPos);
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel{
      if(digitalRead(BUTTON_PIN1) == 1 || digitalRead(BUTTON_PIN3) == 1){
        break;
      }
      for(i=0; i< strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        if(digitalRead(BUTTON_PIN1) == 1 || digitalRead(BUTTON_PIN3) == 1){
          break;
        }
      }
    strip.show();
    delay(wait);
   }
}

//Theatre-style crawling lights.
//void theaterChase(uint32_t c, uint8_t wait) {
//  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
//    for (int q=0; q < 3; q++) {
//      for (int i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, c);    //turn every third pixel on
//      }
//      strip.show();
//
//      delay(wait);
//
//      for (int i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, 0);        //turn every third pixel off
//      }
//    }
//  }
//}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  delay(1000);
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    
    if(digitalRead(BUTTON_PIN1) == 1 || digitalRead(BUTTON_PIN3) == 1 || digitalRead(BUTTON_PIN2) == 1){
        break;
    }
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}




