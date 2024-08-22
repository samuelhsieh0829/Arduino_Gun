# Arduino Gun
A Gun which can play shooting game on PC

## Material requirement
* Arduino Pro Micro (or something that support HID feature like Arudino Leonardo)
* MPU6050 sensor
* Buttons (like blue switch)
* Wires
* Cardboard or something that can make a gun-like model
* Soldering iron and some solder

## Wiring (Arduino Pro Micro)
* MPU6050 SDA connect to 2, SCL connect to 3 (2 and 3 is I2C port on Arduino Pro micro btw)
* Right click button connect to 6
* Left click button connect to 7
* Reload button connect to 4
* (Optional)
* Gun mode button connect to 8
* Mouse mode button connect to 5
* (These two buttons is for switching mouse dpi, Gun mode dpi is higher) <br>
**Important** Install buttons into the model before soldering them on Arduino

## Example
![image](https://github.com/samuelhsieh0829/Arduino_Gun/blob/80bbd91a63e4892f1d3e34b0ef7e20ad3c877a9f/IMG_2358.jpg)
![image](https://github.com/samuelhsieh0829/Arduino_Gun/blob/80bbd91a63e4892f1d3e34b0ef7e20ad3c877a9f/IMG_2359.jpg)
![image](https://github.com/samuelhsieh0829/Arduino_Gun/blob/80bbd91a63e4892f1d3e34b0ef7e20ad3c877a9f/IMG_2360.jpg)
![image](https://github.com/samuelhsieh0829/Arduino_Gun/blob/80bbd91a63e4892f1d3e34b0ef7e20ad3c877a9f/IMG_2361.jpg)
![image](https://github.com/samuelhsieh0829/Arduino_Gun/blob/80bbd91a63e4892f1d3e34b0ef7e20ad3c877a9f/IMG_2360_.jpg)
