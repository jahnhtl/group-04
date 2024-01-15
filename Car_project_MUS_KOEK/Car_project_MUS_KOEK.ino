int IN1 = 4;
int IN2 = 7;
int IN3 = 5;
int IN4 = 6; 
int StartButton = 8;
int StopButton = 9;
int LeftSensor = A0;  // Analog input pin for the left sensor
int RightSensor = A1; // Analog input pin for the right sensor
int StartButtonState;
int StopButtonState;
int leftDistanceThreshold = 30;  // Adjust this threshold based on your needs for the left sensor
int rightDistanceThreshold = 30; // Adjust this threshold based on your needs for the right sensor

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
  StartButtonState = digitalRead(StartButton);
  StopButtonState = digitalRead(StopButton);
  
  int leftDistance = analogRead(LeftSensor);
  int rightDistance = analogRead(RightSensor);

  if (StartButtonState == LOW && leftDistance > leftDistanceThreshold && rightDistance > rightDistanceThreshold) {
    // Start the motors
    analogWrite(IN1, 0);
    analogWrite(IN2, 255);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
  } else {
    // Stop the motors
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
  }

  if (StopButtonState == LOW) {
    // Stop the motors
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
  }

  // Print the distances for debugging
  Serial.print("Left Distance: ");
  Serial.print(leftDistance);
  Serial.print(" | Right Distance: ");
  Serial.println(rightDistance);
  
  delay(100);  // Adjust delay as needed
}
 



































/*int IN1 = 4;
int IN2 = 7;
int IN3 = 5;
int IN4 = 6; 
int StartButton = 8;
int StopButton = 9;
int StartButtonState;
int StopButtonState;

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
  StartButtonState = digitalRead(StartButton);
  StopButtonState = digitalRead(StopButton);

  if (StartButtonState == LOW) {
    // Starte die Motoren
    analogWrite(IN1, 0);
    analogWrite(IN2, 255);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
    //delay(5000);
  }

  if (StopButtonState == LOW) {
    // Stoppe die Motoren
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
    //delay(500);
  }  
}
*/
