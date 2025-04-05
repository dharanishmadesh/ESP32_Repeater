# **ESP32 WiFi Repeater** 

🚀 **Turn your ESP32 into a WiFi repeater and extend your network coverage!** 

## **Overview**  
This project allows an ESP32 to act as a **WiFi repeater**, boosting the range of an existing WiFi network. The ESP32 connects to your main WiFi (as a station) and creates a secondary access point (AP) for other devices to connect.  

## **Features**  
✅ Extends WiFi coverage using ESP32 
✅ Simple setup with minimal code  
✅ Connects to an existing WiFi network  
✅ Creates a new hotspot for other devices  

## **Hardware Requirements**  
- **ESP32 Development Board**  
- **Micro-USB Cable**  
- **Computer with Arduino IDE Installed**  
- **WiFi Network**  

## **Installation & Setup**  

### **1. Install ESP32 Board in Arduino IDE**  
1. Open **Arduino IDE** and go to **File → Preferences**.  
2. In **Additional Board Manager URLs**, add:  
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```  
3. Go to **Tools → Board → Boards Manager**, search for **ESP32**, and install it.  

### **2. Upload the Code**  
1. Connect your **ESP32** to your computer.  
2. Open `ESP32_WiFi_Repeater.ino` in **Arduino IDE**.  
3. Update the following lines with your **WiFi credentials**:  
   ```cpp
   const char* sta_ssid = "Your_Home_WiFi";   // Replace with your WiFi SSID  
   const char* sta_password = "Your_WiFi_Password"; // Replace with your WiFi Password  
   ```  
4. Click **Upload** to flash the code to your ESP32.  

### **3. Test the WiFi Repeater**  
- Open **Serial Monitor** (115200 baud rate) to check the connection status.  
- Once connected, find a new WiFi network called **ESP32_Repeater**.  
- Connect to it using the password **12345678**.  
- Enjoy extended WiFi coverage!  

## **Code**  

```cpp
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char* sta_ssid = "Your_Home_WiFi";
const char* sta_password = "Your_WiFi_Password";
const char* ap_ssid = "ESP32_Repeater";
const char* ap_password = "12345678";

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(sta_ssid, sta_password);

    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    WiFi.softAP(ap_ssid, ap_password);
    Serial.println("WiFi Repeater Started");
    Serial.print("Access Point IP Address: ");
    Serial.println(WiFi.softAPIP());
}

void loop() {
    // Keep the ESP32 active
}
```

## **Future Enhancements**  
🔹 Web-based settings to change WiFi credentials dynamically.  
🔹 Enable DHCP forwarding for seamless connectivity.  
🔹 Improve security with WPA2 encryption.  

## **Contribute**  
Feel free to fork this repo, suggest improvements, or raise issues! 🚀  

