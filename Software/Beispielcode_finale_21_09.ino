/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN_Daumen  102 // This is the 'minimum' pulse length count (out of 4096) --- Min Daumen 100 (102)
#define SERVOMAX_Dauemn  415 // This is the 'maximum' pulse length count (out of 4096) --Max Dauemn 415
#define SERVOMIN 70 // This is the 'minimum' pulse length count (out of 4096) --- continiuse servo minimum to move: 70  -- move right between 70 and 285
#define SERVOMAX  280 // This is the 'maximum' pulse length count (out of 4096) --continiuse servo stops moving: 285 -- move left between 285 and 500 
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servonum = 14;


void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  // Drive each servo one at a time using setPWM()
  Serial.println(servonum);
  Serial.println("in loop");
  //set evry servo to zero
  pwm.setPWM(0, 0, 0);
  pwm.setPWM(1, 0, 0);
  pwm.setPWM(3, 0, 0);
  pwm.setPWM(4, 0, 0);
  pwm.setPWM(5, 0, 0);
  pwm.setPWM(6, 0, 0);
  pwm.setPWM(7, 0, 0);
  pwm.setPWM(8, 0, 0);
  pwm.setPWM(9, 0, 0);
  pwm.setPWM(10, 0, 0);
  pwm.setPWM(11, 0, 0);
  pwm.setPWM(12, 0, 0);
  pwm.setPWM(13, 0, 0);
  pwm.setPWM(14, 0, 0);
  pwm.setPWM(15, 0, 0);

  //move the servo for A few econds in each direction
  pwm.setPWM(servonum, 0, 100);
  pwm.setPWM(1, 0, 100);
  delay(300);
  pwm.setPWM(servonum, 0, 285);
  pwm.setPWM(1, 0, 285);
  delay(2000);
  pwm.setPWM(servonum, 0, 400);
  pwm.setPWM(1, 0, 400);
  delay(300);
  pwm.setPWM(servonum, 0, 285);
  pwm.setPWM(1, 0, 285);
  delay(2000);

/* to count the pwm up or down
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen = pulselen+10) {
    pwm.setPWM(servonum, 0, pulselen);
    delay(1000);
    Serial.println(pulselen);
  }
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; (pulselen= pulselen-1)) {
    pwm.setPWM(servonum, 0, pulselen);
    delay(1000);
    Serial.println(pulselen);
  }*/

}
