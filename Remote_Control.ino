#include <Keypad.h>
void task(unsigned char p);
int green = 2;
int red = 13;
int yellow = 12;

const byte ROWS = 4; //rows and columns for keypad
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; //{A0, A1, A2, A3};

byte colPins[COLS] = {7, 6, 5, 4};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//------------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}
//-----------------------------------------------------------------------------------------------------
void loop() {
  
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
    
  char customKey = myKeypad.getKey(); //defining the key that was pressed
  //delay(50);
  //char nextKey = myKeypad.getKey();  this might be needed to work with toggle
  
  //Serial.println("1st key = " + customKey);
  //Serial.println("2nd key = " + nextKey);
  
  
  if(customKey == '1') {  // (command 1, address 0)
    task(1); //s1
    task(1); //s2
    task(1); //toggle
    task(0); //address 1
    task(0); //address 2
    task(0); //address 3
    task(0); //address 4
    task(0); //address 5
    task(0); //command 1
    task(0); //command 2
    task(0); //command 3
    task(0); //command 4
    task(0); //command 5
    task(1); //command 6
  }

  if(customKey == '2') {   //command 2, address 20
    task(1); //s1
    task(1); //s2
    task(1); //toggle
    task(1); //address 1
    task(0); //address 2
    task(1); //address 3
    task(0); //address 4
    task(0); //address 5
    task(0); //command 1
    task(0); //command 2
    task(0); //command 3
    task(0); //command 4
    task(1); //command 5
    task(0); //command 6
  }

  if(customKey == '*') {    //mute 2nd tv (command 12, address 1)
    task(1); //s1
    task(1); //s2
    task(1); //toggle
    task(0); //address 1
    task(0); //address 2
    task(0); //address 3
    task(0); //address 4
    task(1); //address 5
    task(0); //command 1
    task(0); //command 2
    task(1); //command 3
    task(1); //command 4
    task(0); //command 5
    task(0); //command 6
  }

  if(customKey == '#') {   //command 9, address 5
    task(1); //s1
    task(1); //s2
    task(1); //toggle
    task(0); //address 1
    task(0); //address 2
    task(1); //address 3
    task(1); //address 4
    task(1); //address 5
    task(0); //command 1
    task(0); //command 2
    task(1); //command 3
    task(0); //command 4
    task(0); //command 5
    task(1); //command 6
  }
  
}

void task(int command){
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    delay(200);
    digitalWrite(yellow, LOW);
    if(command == 1){
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      delay(500);
    }
    else{
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      delay(500);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      delay(500);
    }
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
}
