#include <Servo.h>

Servo my_servo;

uint32_t next;

void setup()
{
  // 1000 & 2000 set min/max pulse width in microseconds 

  my_servo.attach(9, 1000, 2000);

  next = millis() + 500;
}

void loop()
{
  static bool rising = true;

  if(millis() > next)
  {
    if(rising)
    {
      my_servo.write(180);
      rising = false;
    }
    else
    {
      my_servo.write(0);
      rising = true;
    }

    // repeat again in 3 seconds.
    next += 3000;
  }

}

