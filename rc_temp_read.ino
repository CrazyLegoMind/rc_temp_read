/* This code works with MLX90614 (GY906) and OLED screen
 * It measures both ambient and object temperature in Fahrenheit and display it on the screen
 * Please visit www.surtrtech.com for more details
 */

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include "cst_font.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int reads = 0;
float sum = 0;
float temp_max = 0;

void setup() {  
  mlx.begin(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  
  display.clearDisplay();
  display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,0);
  display.println("Starting");
  display.display();
  delay(400);
  display.clearDisplay();
  display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,0);
  display.println("Starting.");
  display.display();
  delay(400);
  display.clearDisplay();
  display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,0);
  display.println("Starting..");
  display.display();
  delay(400);
  display.clearDisplay();
  display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,0);
  display.println("Starting...");
  display.display();
  delay(400);

}

void loop() {
  delay(500);
  display.clearDisplay();
  float temp = mlx.readObjectTempC();
  if(isnan(temp)){
    display.setTextSize(2);                    
    display.setTextColor(WHITE);             
    display.setCursor(0,0);
    display.println("sens ERR");
    display.display();
    return;
  }
  if(temp > temp_max){
    temp_max = temp;
  }

  reads++;
  unsigned long of = sum;
  sum+=temp;
  if(sum < of){
    reads = 1;
    sum = temp;
  }

  display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,0);
  display.print("t: ");
  display.println(temp,1);

  display.setTextSize(1);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,24);
  display.print("a:");
  display.print(sum/reads,1);
  display.print(" m:");
  display.print(temp_max,1);
  display.display();
  

}