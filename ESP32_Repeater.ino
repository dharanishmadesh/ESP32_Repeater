#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char* sta_ssid = "Your_Home_WiFi";   // Existing WiFi SSID
const char* sta_password = "Your_WiFi_Password"; // Existing WiFi Password
const char* ap_ssid = "ESP32_Repeater";   // SSID of the new extended network
const char* ap_password = "12345678";     // Password for the new network

void setup() {
    Serial.begin(115200);
    
    // Connect to the existing WiFi network
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

    // Create a new WiFi network (Access Point)
    WiFi.softAP(ap_ssid, ap_password);
    Serial.println("WiFi Repeater Started");
    Serial.print("Access Point IP Address: ");
    Serial.println(WiFi.softAPIP());
}

void loop() {
    // Keep the ESP32 active
}
