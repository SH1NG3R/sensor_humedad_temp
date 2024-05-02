/*Se importan las librerías*/
#include <Adafruit_GFX.h> //Liberia para gráficos
#include <Adafruit_SSD1306.h> 

#include <OneWire.h>
#include <DallasTemperature.h>

#define OLED_RESET 13 
Adafruit_SSD1306 display(OLED_RESET);

#define ONE_WIRE_BUS 3
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


int SensorPin = A0;
int humedad;
float porcentaje;

#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif
void setup() {
Serial.begin(9600);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

Serial.print("Contrutecc Digital Temperature & Moisture Sensor");

display.setTextSize(1); //Establece el tamaño de fuente, admite tamaños de 1 a 8
display.setTextColor(WHITE); //Establece el color 
display.setCursor(0,10);
display.print("Contrutecc");
display.setCursor(0,20);
display.print("Digital Sensor");
display.setCursor(0,30);
display.print("Temp & Hum");
delay(3000);

sensors.begin();
}


void loop() {
display.clearDisplay();

int humedad = analogRead(SensorPin);

float porcentaje = map(analogRead(SensorPin), 0, 1023, 100, 0)-8.6;

sensors.requestTemperatures();
float temp = sensors.getTempCByIndex(0);

Serial.print(porcentaje);
Serial.print(",");
Serial.println(temp);

display.setTextSize(1); //Establece el tamaño de fuente, admite tamaños de 1 a 8
display.setTextColor(WHITE); //Establece el color 
display.setCursor(0,10); //Establecer las coordenadas para mostrar la posición del texto
display.print("Hum%:");
display.println(porcentaje);
display.setCursor(0,20); //Establecer las coordenadas para mostrar la posición del texto
display.print("Temp C:");
display.println(temp);
display.display(); //Muestra el texto 
delay(2000);
}

