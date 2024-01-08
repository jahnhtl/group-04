
int IN1 = 4;
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
    analogWrite(IN1, 255);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 255);
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
