
//ArduinoBluetoothWithSmirfLED3Servos 

#include <SoftwareSerial.h> 
#include <Servo.h> 

SoftwareSerial BT(10, 11);        //TX, RX respectively

//Variable holds info from Bluetooth 
String state;      
//set your servo name and pin # here:       
Servo servoName;
int const servoPin=4;
void setup() {
 
 BT.begin(115200);
 Serial.begin(9600);              // serial communication to check the data on serial monitor
servoFunctionSet (servoPin,servoName);
 
}

//-----------------------------------------------------------------------//  
void loop() {
  
  while (BT.available()){          //Check if there is an available byte to read
  
    delay(10);                      //Delay added to make reads stable (a little like a spam block)
    char c = BT.read();             //Created a variable called 'c'                                 
    state += c;                     //Whenever 'c' is referenced it's the equivalent writing "BT.read()" #lazy
                       
                                  
  } 
  if (state.length() > 0) {                                         
    Serial.println(state);          //Servo Functions     
 
   if(state == "S1"){       
     servoFunction(servoName); 
     Serial.println ("S1");  
   }
  }
}

void servoFunctionSet (int servoPin, Servo servoName){
servoName.attach(servoPin); 
       servoName.write(90);      
}
void servoFunction (Servo servoName){ 
  servoName.write(120);
    delay(2000);
    servoName.write(50);
    delay(1000);
    servoName.write(90); 
    Serial.println ("servoFunction"); 
}


