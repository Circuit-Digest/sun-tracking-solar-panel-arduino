# Sun Tracking Solar Panel Using Arduino

[![Arduino](https://img.shields.io/badge/Arduino-Uno-blue?style=for-the-badge)](https://circuitdigest.com/microcontroller-projects/building-your-own-sun-tracking-solar-panel-using-arduino) [![Language: Embedded C++](https://img.shields.io/badge/Language-EmbeddedC++-orange?style=for-the-badge)]() [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

This project demonstrates how to build an **Arduino-based Sun Tracking Solar Panel** to automatically follow the sun’s position and maximize solar energy harvesting. By using a couple of **LDRs**, a **servo motor**, and basic logic, we can increase power output by **up to 35%** over fixed panels.

![Sun Tracking Solar Panel](https://circuitdigest.com/sites/default/files/other/Sun-Tracking-Solar-panel.gif)

---

## 🚀 Features

- Real-time sun tracking using LDR feedback
- Increased efficiency over fixed panel designs
- Simple and low-cost components
- Single-axis tracking with optional calibration
- Night mode and automatic reset
- Open-source hardware & software

---

## 🛠️ Hardware Requirements

| Component       | Description                                 |
|----------------|---------------------------------------------|
| Arduino Uno     | Main controller                             |
| Servo Motor     | Rotates panel (SG90 or similar)             |
| Solar Panel     | Small-scale panel for demonstration         |
| 2 x LDRs        | Detect sunlight direction                   |
| 2 x 10k Resistor| Pull-down resistors for LDRs                |
| Jumper Wires    | For connections                             |
| MDF Board       | Mounting base                               |

---

## ⚙️ Working Principle

The system continuously compares light intensity from **two LDR sensors**. Depending on which side receives more light, the **servo motor** rotates the solar panel towards that direction. The Arduino reads analog values from LDRs and moves the servo accordingly to track the sun throughout the day.

### Light Detection Logic

- **East LDR > West LDR** → Rotate panel to the right (East)
- **West LDR > East LDR** → Rotate panel to the left (West)
- **Low light on both** → Reset to morning position (East)

---

## 🔌 Circuit Connection

- LDRs connected to **A0 (East)** and **A1 (West)**
- Servo motor signal pin → **Digital Pin 9**
- LDR voltage divider resistors (10kΩ) connected to GND
- VCC (5V) and GND from Arduino to all components
- Power drawn directly from Arduino (no external supply required)

![Circuit Diagram](https://circuitdigest.com/sites/default/files/circuitdiagram_mic/Solar-Tracking-System-Circuit.png)

---

## 🧰 Assembly Instructions

- Mount servo on vertical MDF board piece
- Create L-shaped bracket to hold solar panel
- Attach LDRs on both sides of the solar panel
- Wire resistors and connect everything to Arduino
- Secure components using hot glue for prototype stability

![Hardware Assembly](https://circuitdigest.com/sites/default/files/other/Sun-Tracking-Solar-Panel-Hardware.jpg)

---

## 🧠 Troubleshooting

| Issue                | Cause                         | Solution                                      |
|---------------------|-------------------------------|-----------------------------------------------|
| No servo movement   | Power issue                   | Check USB connection & wiring                 |
| Erratic tracking     | LDR mismatch                  | Adjust calibration constant in code           |
| Servo jitter        | Noisy analog input            | Add capacitor across LDR terminals            |
| Limited rotation    | Physical blockage             | Check mounting and servo orientation          |

---

## 💻 Arduino Code Overview

- Uses `Servo.h` library
- LDR readings via analog pins
- Decision-making via difference threshold
- Calibration option for mismatched sensors
- Auto-reset at low light levels (e.g., evening)

```cpp
#include <Servo.h>
Servo servo;

int eastLDR = 0;
int westLDR = 1;
int calibration = 0;
int servoposition = 90;

void setup() {
  servo.attach(9); 
}

void loop() {
  int east = calibration + analogRead(eastLDR);  
  int west = analogRead(westLDR);
  int error = east - west;

  if (east < 350 && west < 350) {
    while (servoposition <= 150) {
      servoposition++;
      servo.write(servoposition);
      delay(100);
    }
  }

  if (error > 30 && servoposition <= 150) {
    servoposition++;
    servo.write(servoposition);
  } else if (error < -30 && servoposition >= 20) {
    servoposition--;
    servo.write(servoposition);
  }

  delay(100);
}
```

---

## ⚙️ Servo Motor Specifications

| Parameter          | Specification       | Application Benefit                 |
|-------------------|---------------------|-------------------------------------|
| Operating Voltage | 4.8V - 6V           | Direct Arduino power compatibility |
| Rotation Range    | 0° - 180°           | Complete sun path coverage         |
| Torque            | 2.5 kg⋅cm           | Sufficient for small solar panels  |
| Speed             | 0.1s/60°            | Smooth tracking movement           |

---

## 💡 LDR Sensor Overview

Light Dependent Resistors (LDRs) are photoresistors that change their resistance based on light intensity. In this project:

- Higher light → Lower resistance → Higher voltage at analog pin
- Two LDRs placed on opposite edges of the panel
- Arduino compares analog values to detect direction

---

## 🔮 Future Enhancements

- Add **dual-axis tracking** with second servo
- Add **IoT monitoring** using ESP8266/ESP32
- Use **relay control** and higher-torque servos for large panels
- Display system info on **OLED/LCD display**
- Solar charging circuit for standalone operation

---

## 📱 Applications

- Smart solar home systems
- Off-grid solar charging stations
- STEM education kits and labs
- Energy-efficient IoT installations
- DIY renewable energy setups

---

## 🔗 Links

- 📖 [Complete Tutorial on Circuit Digest](https://circuitdigest.com/microcontroller-projects/building-your-own-sun-tracking-solar-panel-using-arduino)
- 🔌 [Arduino Uno Board Info](https://store.arduino.cc/products/arduino-uno-rev3)
- 📘 [More Arduino Solar Projects](https://circuitdigest.com/tags/solar-panel)
- 📚 [Arduino Projects Archive](https://circuitdigest.com/arduino-projects)

---

## ⭐ Support

If you found this helpful, please ⭐ star this repository and share it with others!

---

**Built with ☀️ by [Circuit Digest](https://circuitdigest.com/)**  
_Making Electronics Simple for Everyone_

---

### 🔖 Keywords

`Arduino Solar Tracker` `Sun Tracking Panel` `LDR Sun Sensor` `Servo Motor Solar Control`  
`DIY Solar Project` `Energy Efficiency Arduino` `Single Axis Solar Tracker`  
`Renewable Energy DIY` `Arduino Uno Servo Project`
