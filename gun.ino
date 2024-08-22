/* Code to view on the Serial Monitor the values of the Gyroscope
 * and the output for the mouse. This is equal to the standard code
 * but with instructions to check the values on the Serial monitor.
 * Change the delay to read the values at reduced speed.
 * 
 * Gabry295
 */

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>
#include "Keyboard.h"

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int dps_x = 1;
int dps_y = 1;
int dps_mode = 2;

const int mode_1 = 1000;
const int mode_2 = 400; //with VALORANT sens 0.67
//dps mode 1 = mouse, 2 = playing, 3 = disable

// int devide(int varible){
//   return varible / 1000;
// }

// int dps_switch(int mode){
//   if (mode == 3)
//   {
//     mode = 1;
//   }
//   else 
//   {
//     mode = mode + 1;
//   }
//   return mode;
// }

int dps_set_x(int x, int mode)
{
  if (mode == 1)
  {
    x = x / mode_1;
  }
  else if (mode == 2)
  {
    x = x / mode_2;
  }
  // else if (mode == 3)
  // {
  //   x = 0;
  // }
  return x;
}
int dps_set_y(int y, int mode)
{
  if (mode == 1)
  {
    y = y / mode_1;
  }
  else if (mode == 2)
  {
    y = y / mode_2;
  }
  // else if (mode == 3)
  // {
  //   y = 0;
  // }
  return y;
}

void setup() {
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  // Serial.begin(9600);
  //Serial.print("Serial Begin");
  Wire.begin();
  //Serial.write("Wire begin");
  mpu.initialize();
  //Serial.write("MPU");
  Mouse.begin();
  //Serial.write("Start");
  Keyboard.begin();
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  /*
  Serial.print("a/g:\t");
  Serial.print(devide(ax)); Serial.print("\n");
  Serial.print(devide(ay)); Serial.print("\t");
  Serial.print(devide(az)); Serial.print("\t");
  Serial.print(devide(gx)); Serial.print("\t");
  Serial.print(devide(ay)); Serial.print("\t");
  Serial.println(devide(gz)); */
  
  int bt6_Right = digitalRead(6); //Right click
  int bt7_Left = digitalRead(7); //Left click
  int bt8_Gun = digitalRead(8); //Gun mode
  int bt4_Reload = digitalRead(4); //Reload
  int bt5_Mouse = digitalRead(5); //Mouse mode
  //Left click
  if (bt7_Left == LOW)
  {
    Mouse.press(MOUSE_LEFT);
  }
  else
  {
    Mouse.release(MOUSE_LEFT);
  }
  //Right Click
  if (bt6_Right == LOW)
  {
    Mouse.press(MOUSE_RIGHT);
  }
  else
  {
    Mouse.release(MOUSE_RIGHT);
  }
  // dps
  if (bt8_Gun == LOW)
  {
    if (dps_mode == 1)
    {
      dps_mode = 2;
    }
    Keyboard.press('1');
    Keyboard.release('1');
  }
  if (bt5_Mouse == LOW)
  {
    dps_mode = 1;
  }
  //Reload
  if (bt4_Reload == LOW)
  {
    Keyboard.press('r');
    Keyboard.release('r');
  }
  // Serial.print(gz); Serial.print("\t");
  // Serial.println(gy);
  dps_x = -(dps_set_x(gz, dps_mode));
  dps_y = dps_set_y(gy, dps_mode);
  Mouse.move(dps_x, dps_y);
  // Mouse.move(-gz/1000, gy/1000);
  // Serial.print("bt6_Right: ");
  // Serial.println(bt6_Right);
  // Serial.print("bt7_Left: ");
  // Serial.println(bt7_Left);
  // Serial.print("bt8_Gun: ");
  // Serial.println(bt8_Gun);
  // Serial.print("bt4_Reload: ");
  // Serial.println(bt4_Reload);
  // Serial.print("bt5_Mouse: ");
  // Serial.println(bt5_Mouse);
}
