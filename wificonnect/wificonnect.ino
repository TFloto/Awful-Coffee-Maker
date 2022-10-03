#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>

const char* ssid     = "ImUrHuckleberry";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "Password#1";     // The password of the Wi-Fi network

ESP8266WebServer webserver(80);

void rootPage() { 
  webserver.send(200, "text/plain", "pee my balls"); 
}

void notfoundPage(){ 
  webserver.send(404, "text/plain", "404: Not found"); 
}

void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop(void){
   webserver.handleClient();  
 }
