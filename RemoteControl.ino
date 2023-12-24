

//https://arduinogetstarted.com/tutorials/arduino-switch arduino toggle switch

#include <ezButton.h> 
ezButton toggleSwitch(7);  // create ezButton object that attach to pin 7;


//RGB LED code https://arduinogetstarted.com/tutorials/arduino-rgb-led
const int PIN_RED   = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE  = 9;

//Arduino Button Code  https://roboticsbackend.com/arduino-push-button-tutorial/
#define BUTTON_PIN 4

void setup() {

Serial.begin(9600);
toggleSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds                  


// ------------------- https://linuxhint.com/use-analog-pin-as-digital/ -----
pinMode(A5, OUTPUT); //led poop
pinMode(A4, OUTPUT); //led pee
pinMode(A3, OUTPUT); //led power reset
pinMode(A2, OUTPUT); //led cancel 
pinMode(A1, OUTPUT); //led adult setting
pinMode(A0, OUTPUT); //led baby setting 



// --- RGB LED 
 pinMode(PIN_RED,   OUTPUT);
 pinMode(PIN_GREEN, OUTPUT);
 pinMode(PIN_BLUE,  OUTPUT);


// ----- Button 
  pinMode(BUTTON_PIN, INPUT_PULLUP);


}

void loop() {

//------------------------------ LED Generic -------------------------
digitalWrite(A5,HIGH);
delay(1000);
digitalWrite(A5,LOW);
delay(1000);



//------------------------------ Toggle Switch -------------------------

toggleSwitch.loop(); // MUST call the loop() function first

  if (toggleSwitch.isPressed())
    Serial.println("The switch: OFF -> ON");

  if (toggleSwitch.isReleased())
    Serial.println("The switch: ON -> OFF");

  int state = toggleSwitch.getState();
  if (state == HIGH)
    Serial.println("The switch: OFF");
  else
    Serial.println("The switch: ON");


//------------------- RGB LED Arduino 

 // color code #00C9CC (R = 0,   G = 201, B = 204)
  analogWrite(PIN_RED,   0);
  analogWrite(PIN_GREEN, 201);
  analogWrite(PIN_BLUE,  204);

  delay(1000); // keep the color 1 second

  // color code #F7788A (R = 247, G = 120, B = 138)
  analogWrite(PIN_RED,   247);
  analogWrite(PIN_GREEN, 120);
  analogWrite(PIN_BLUE,  138);

  delay(1000); // keep the color 1 second

  // color code #34A853 (R = 52,  G = 168, B = 83)
  analogWrite(PIN_RED,   52);
  analogWrite(PIN_GREEN, 168);
  analogWrite(PIN_BLUE,  83);

  delay(1000); // keep the color 1 second


// --------------Button Code 

 byte buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == LOW) {
      Serial.println("Button is pressed");
  }
  else {
      Serial.println("Button is not pressed");
  }
  delay(100);



}