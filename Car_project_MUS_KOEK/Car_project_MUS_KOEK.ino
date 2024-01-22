#include <SharpIR.h>

int IN1 = 4;
int IN2 = 7;
int IN3 = 5;
int IN4 = 6; 
int StartButton = 8;
int StopButton = 9;
int LeftSensor = A1;
int RightSensor = A0;
int StartButtonState;
int StopButtonState;

SharpIR LeftDD(SharpIR::GP2Y0A21YK0F, A1);
SharpIR RightDD(SharpIR::GP2Y0A21YK0F, A0);

void setup()
{
  // Set the output pins
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(StartButton, INPUT_PULLUP);
  pinMode(StopButton, INPUT_PULLUP);
}

void loop()
{
  static int fahren = 0;
  StartButtonState = digitalRead(StartButton);
  StopButtonState = digitalRead(StopButton);

  //int leftDistance = analogRead(LeftSensor);
  //int rightDistance = analogRead(RightSensor);

  int leftDistance = LeftDD.getDistance();
  int rightDistance = RightDD.getDistance();

  if (StartButtonState == LOW) {
    fahren = 1;
  }
  if (StopButtonState == LOW) {
    fahren = 0;
  }

  if(fahren == 1)
  {
    // Starte die Motoren
    analogWrite(IN1, 0);
    analogWrite(IN2, 255);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
    //delay(5000);  
  if ( LeftSensor > RightSensor ) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 50);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
  }  if ( LeftSensor < RightSensor ) {
    analogWrite(IN1, 0);
    analogWrite(IN2, 50);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
  }

  }
  else
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
  }



  Serial.print("Left Distance: ");
  Serial.print(leftDistance);
  Serial.print(" | Right Distance: ");
  Serial.println(rightDistance);
  
  delay(100);  // Adjust delay as needed
}  
