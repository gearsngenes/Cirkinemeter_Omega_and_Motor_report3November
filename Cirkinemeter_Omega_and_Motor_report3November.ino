//---------OLED Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306();

//--------------Joystick Pins and Variables
int x=A0;  //X axis pin
int y=A1;  //Y axis pin
int xval=0;
int yval=0;
int speedval=0;

//--------------TB66 Pins; MOTOR CONTROL
int pwmB=5;  //RPM control

//BO pins control direction
int BO1=6;  //BIN1
int BO2=9;  //BIN2

//--------------Sensor Pins and Values
int sensor1=10;  //Pin of the IR RECEIVER
int sensState1 = 0;  //value of digital signal of sensor (0 or 1==> 0V or 3V)
int lastState1=0;    //The sensor's PREVIOUS digital signal, used to determine crossing
int LEDPIN=13;       //Used for visual display. If sensor detects IR, LED turns on

//Circular Kinematics Values
unsigned long startTime=0;    //Time at the start of the revolution
unsigned long endTime=0;      //Time at the end of the revolution
float theta=3.14159*2;        //Angle traveled between the two times (2 pi RADIANS)
float omega=0;                //Variable for Angular velocity


// --------------------------


//Void Setup performs code once, declares Inputs and Outputs
void setup() {
  //Joystick
  pinMode(x, INPUT);  //gets values from joystick
  pinMode(y, INPUT);  //gets values from joystick
  //TB66
  pinMode(BO1, OUTPUT);  //sends values to TB66
  pinMode(BO2, OUTPUT);  //sends values to TB66
  
  //IR receiver
  pinMode(sensor1, INPUT);  //Receives data from sensor     
  digitalWrite(sensor1, HIGH);  //This forces the sensor to activate for the first time, afterwards, only digital READS
  
  //OLED wing
  oledSetup(); //OLED display setup

}

//Void Loop repeats tasks indefinitely
void loop() {
  //Clears the OLED display each cycle instantly, commented out so the data stays until the new data comes
    //display.clearDisplay();
    //display.display();
  
  //Joystick to Motor Control
  xval=analogRead(x);
  yval=analogRead(y);
  collect();  //Print X Y values
  getSetSpeed();  //get PWMB value from Joystick and set it as the RPM for the Motor
  chooseDirection();  //Decide direction of Motor (clockwise vs counterclockwise)
  directiontest();  //print direction for debugging
  
  //IR receiver code
  sensState1 = digitalRead(sensor1);  //Get digital signal from IR receiver
  detectAndTime();  //Record times, calculate Omega, publish values to OLED
}
