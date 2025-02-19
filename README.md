# Gas Safety Monitoring System Using IOT

This project is a **Gas Safety Monitoring System** that continuously detects **air quality, gas leakage, temperature, and humidity** using **MQ-135, MQ-06, and DHT11 sensors**. The readings are displayed on a **0.96-inch OLED screen**, and an alert is triggered using a **buzzer** when dangerous levels are detected.

## 🚀 Features  
- **Gas Detection:** MQ-135 (Air Quality) & MQ-06 (LPG, Butane, Methane)  
- **Temperature & Humidity Monitoring:** DHT11 Sensor  
- **Visual Alerts:** OLED display with animated progress bars  
- **Audio Alert:** Buzzer activation for hazardous conditions  

## 🛠️ Components Used  
- **ESP8266 NodeMCU / Arduino Uno**  
- **MQ-135 Gas Sensor**  
- **MQ-06 Gas Sensor**  
- **DHT11 Temperature & Humidity Sensor**  
- **0.96-inch OLED Display (SSD1306, I2C)**  
- **Buzzer**  
- **Jumper Wires & Breadboard**  

## 🔧 Circuit Connection  
<img width="557" alt="image" src="https://github.com/user-attachments/assets/52c75461-c7eb-4e99-be84-38b37dcdf755" />


## 📜 Installation & Usage  
1. **Install required libraries**  
   - `Adafruit GFX`  
   - `Adafruit SSD1306`  
   - `DHT Sensor Library`  
2. **Upload the code** `Gas_Safety_Monitor.ino` to your Arduino Uno
3. **Connect the components as per the circuit Connection**  
4. **Power the board and observe real-time monitoring on the OLED display**  

## 📷 OLED Display Output  
  
![20250219_075745](https://github.com/user-attachments/assets/ef9f7f36-3166-402a-9cbd-40d884793d23)
![20250219_075808](https://github.com/user-attachments/assets/119b3a33-5730-43ef-841d-c3e9fd8b73f7)
![20250219_075756](https://github.com/user-attachments/assets/e21d9174-929b-4092-901a-8a4b2b48e0e7)
![20250219_075751](https://github.com/user-attachments/assets/e719090b-c9aa-4cb9-85a9-aac028d6ae3c)

---
### 📌 **Developed by:** *Arun Roshan*  

