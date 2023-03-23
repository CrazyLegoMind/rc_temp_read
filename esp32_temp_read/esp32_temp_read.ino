#include <Adafruit_MLX90614.h>
#include <WiFi.h>
#include <WebServer.h>
#include "webpage.h"
#include "pass.h"
Adafruit_MLX90614 mlx = Adafruit_MLX90614();


// IP Address details
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
  
  /*   SoftAP MODE
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);


  Serial.print("Connect to My access point: ");
  Serial.println(ssid);

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100);
  //*/

  ///* WIFI STA MODE
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while(WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(500); Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //-------------------------------------------------
  server.on("/", handleRoot);
  server.on("/readPOT", handlePOT);
  server.on("/readAmbient", readAmbient);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  /*
  Serial.print("Ambient temperature = "); 
  Serial.print(mlx.readAmbientTempC());
  Serial.print("°C");      
  Serial.print("   ");
  Serial.print("Object temperature = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("°C");
  //*/
  delay(1);
}


void handleRoot()
{
 server.send(200, "text/html", webpageCode);
}
//---------------------------------------
void handlePOT()
{
 String POTval = String(mlx.readObjectTempC());
 server.send(200, "text/plane", POTval);
}
void readAmbient()
{
 String AmbientC = String(mlx.readAmbientTempC());
 server.send(200, "text/plane", AmbientC);
}