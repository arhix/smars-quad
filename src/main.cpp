#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

int pulseWidth(int angle);

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t ServoCount = 0;

void setup()
{
  Serial.begin(9800);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  yield();
  delay(1000);

  // init position
  pwm.setPWM(0, 0, pulseWidth(50)); //knee f left
  pwm.setPWM(1, 0, pulseWidth(130));
  pwm.setPWM(2, 0, pulseWidth(120)); //knee f right
  pwm.setPWM(3, 0, pulseWidth(130));
  pwm.setPWM(4, 0, pulseWidth(120)); //knee b left
  pwm.setPWM(5, 0, pulseWidth(130));
  pwm.setPWM(6, 0, pulseWidth(50)); //knee b right
  pwm.setPWM(7, 0, pulseWidth(130));
  Serial.println("servoDefault status: executed");
}

void loop()
{
  delay(1000);
  pwm.setPWM(0, 0, pulseWidth(0)); //knee f left
  pwm.setPWM(2, 0, pulseWidth(180)); //knee f right
  pwm.setPWM(4, 0, pulseWidth(180)); //knee b left
  pwm.setPWM(6, 0, pulseWidth(0)); //knee b right
}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}