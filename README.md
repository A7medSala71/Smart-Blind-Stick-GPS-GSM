
# Smart Blind Stick with GPS and GSM Module

A safety-focused, assistive technology project designed to enhance the mobility and independence of visually impaired individuals. This smart blind stick detects obstacles using an IR proximity sensor and provides immediate alerts via LED and buzzer. Additionally, it integrates a GPS module and GSM module to transmit the user's current location via SMS in case of emergencies.

## 📌 Features

- **Obstacle Detection:** Uses IR proximity sensors to detect objects in close range.
- **Auditory & Visual Alerts:** Triggers a buzzer and LED when an obstacle is nearby.
- **Emergency SMS:** Sends the user's location via SMS using GPS and GSM modules when a button is pressed.
- **Low-Pass Filter:** Ensures signal clarity by filtering out noise in sensor readings.
- **Custom Threshold Control:** Adjustable sensitivity using a potentiometer and comparator (LM358).

## 🛠️ Hardware Components

- Arduino Uno
- IR LED and Photodiode
- LM358 Comparator IC
- GPS Module (e.g., Neo-6M)
- GSM Module (e.g., SIM800L)
- LED and Buzzer
- 10kΩ Resistor, Potentiometer
- Push Button
- Power Supply

## 🔧 Circuit Overview

- The IR sensor sends infrared rays which reflect off nearby objects and are detected by a photodiode.
- Voltage output from the photodiode is processed by an LM358 comparator.
- If an object is detected (voltage exceeds threshold), a buzzer and LED are activated.
- A low-pass filter is used to clean noisy sensor signals.
- When the user presses a button, the Arduino reads GPS coordinates and sends an SMS with the location using the GSM module.

## 🧪 Simulation & Testing

- Simulated in LTSpice to verify circuit behavior.
- Signal noise reduction validated via spectrum analysis (cutoff at 10 kHz).
- Final output voltage stabilizes at ~4V during obstacle detection.
- Physical implementation confirms accurate detection and messaging.

## 🚀 How It Works

1. **Power On:** System becomes active and ready to detect obstacles.
2. **Obstacle Detected:** LED and buzzer are triggered.
3. **Emergency Activated:** Press the push button to send your location via SMS.
4. **SMS Sent:** The receiver gets a text with GPS coordinates.

## 📂 Project Structure

```
SmartBlindStick/
│
├── IR_Proximity_Circuit_Diagram.png   # Circuit schematic
├── Arduino_Code/                      # Arduino sketch for sensors and GSM/GPS
├── Report.pdf                         # Final report with theory, analysis, and results
├── Readme.md                          # This file
```

## 🧠 Team Members

- Ahmed Salah (202200212)
- Ahmed Mohamed (202200977)
- Ahmed Mohamed Nasr (202200294)
- Ahmed Gamal (202200133)
- Mohamed Ghaith

## 📚 References

- [SIM800 GSM Module Datasheet](https://www.electronicwings.com/nodemcu/sim800l-gsm-gprs-module)
- [Neo-6M GPS Module Guide](https://randomnerdtutorials.com/guide-to-neo-6m-gps-module-with-arduino/)
- [LM358 Comparator Datasheet](https://www.ti.com/lit/ds/symlink/lm358.pdf)

## 📜 License

This project is for educational purposes and is distributed under the MIT License.

---

Feel free to fork, contribute, or suggest enhancements!
