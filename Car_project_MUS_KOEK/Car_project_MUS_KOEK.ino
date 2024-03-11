#include <SharpIR.h>
#define IR_SENSOR_FRONT  A2
#define IR_SENSOR_RIGHT  A1
#define IR_SENSOR_LEFT  A0

int IN1 = 4;
int IN2 = 7;
int IN3 = 5;
int IN4 = 6;
int StartButton = 8;
int StopButton = 9;
//int RightSensor = A1;
//int LeftSensor = A0;
int StartButtonState;
int StopButtonState;

SharpIR LeftSensor(SharpIR::GP2Y0A21YK0F, A0);
SharpIR RightSensor(SharpIR::GP2Y0A21YK0F, A1);

uint16_t ir_sensor_front_raw, ir_sensor_right_raw, ir_sensor_left_raw;
uint16_t ir_sensor_front_new, ir_sensor_right_new, ir_sensor_left_new;

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

  int leftDistance = LeftSensor.getDistance();
  int rightDistance = RightSensor.getDistance();

  ir_sensor_front_raw = analogRead(IR_SENSOR_FRONT);
ir_sensor_front_new = (uint16_t) (16256 / (ir_sensor_front_raw + 22.8)) -8;

if(ir_sensor_front_new > 150)
  ir_sensor_front_new = 151;
else if(ir_sensor_front_new < 20)
  ir_sensor_front_new = 19;

ir_sensor_right_raw = analogRead(IR_SENSOR_RIGHT);
ir_sensor_right_new = (uint16_t) (6000 / (ir_sensor_right_raw - 6.89)) -4;

if(ir_sensor_right_new > 80)
  ir_sensor_right_new = 81;
else if(ir_sensor_right_new < 10)
  ir_sensor_right_new = 9;

ir_sensor_left_raw = analogRead(IR_SENSOR_LEFT);
ir_sensor_left_new = (uint16_t) (6000 / (ir_sensor_left_raw - 6.89)) -4;

if(ir_sensor_left_new > 80)
  ir_sensor_left_new = 81;
else if(ir_sensor_left_new < 10)
  ir_sensor_left_new = 9;

  if (StartButtonState == LOW) {
    fahren = 1;
  }
  if (StopButtonState == LOW) {
    fahren = 0;
  }

  if (fahren == 1)
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, 255);
    analogWrite(IN3, 255);
    analogWrite(IN4, 0);
    //delay(5000);
    if ( leftDistance < 30 )
    {
      analogWrite(IN1, 0);
      analogWrite(IN2, 100);
      analogWrite(IN3, 255);
      analogWrite(IN4, 0);
    }
    else if ( rightDistance < 30)
    {
      analogWrite(IN1, 0);
      analogWrite(IN2, 255);
      analogWrite(IN3, 100);
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
