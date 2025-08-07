#include <Servo.h>
Servo servo ;
int eastLDR = 0;
int westLDR = 1;
int east = 0;
int west = 0;
int error = 0;
int calibration = 600;
int servoposition = 90;
void setup()
{
  servo.attach(9);
}
void loop()
{
  east = calibration + analogRead(eastLDR);
  west = analogRead(westLDR);
  if (east < 350 && west < 350)
  {
    while (servoposition <= 150)
    {
      servoposition++;
      servo.write(servoposition);
      delay(100);
    }
  }
  error = east - west;
  if (error > 15)
  {
    if (servoposition <= 150)
    {
      servoposition++;
      servo.write(servoposition);
    }
  }
  else if (error < -15)
  {
    if (servoposition > 20)
    {
      servoposition--;
      servo.write(servoposition);
    }
  }
  delay(100);
}
