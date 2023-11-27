int IN1 = 4;
int IN2 = 7;
int IN3 = 5;
int IN4 = 6;
int Button =8;
int ButtonState;

void setup()
{
  // Set the output pins
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(Button, INPUT);

 
}

void loop()
{
 
 // if(digitalRead(Button) == LOW){

   
 
    analogWrite(IN1, 255);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 255);
    delay(5000);
   
    //analogWrite(IN1, 0);
    //analogWrite(IN2, 0);
    //analogWrite(IN3, 0);
    //analogWrite(IN4, 0);
    //delay(2000);
  }
