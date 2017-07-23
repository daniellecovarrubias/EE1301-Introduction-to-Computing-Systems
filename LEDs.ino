// This #include statement was automatically added by the Particle IDE.
#include "neopixel/neopixel.h"

#define PIXEL_PIN D4
#define PIXEL_COUNT 10
#define PIXEL_TYPE WS2811
int dark = 0;
int mode =0;

Adafruit_NeoPixel strip=Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN,PIXEL_TYPE);

void lightOn(const char *event, const char *data)
{
    dark = 1;
}
void lightOff(const char *event, const char *data)
{
    dark = 0;
    mode = 0;
}
void lightSong(const char *event, const char *data)
{
    mode = 1;
}
void lightFlash(const char *event, const char *data)
{
    mode = 0;
}
uint16_t value[10] {0,0,0, 0,0,0, 0,0,0, 0};
void setup() {
    strip.begin();
    Particle.subscribe("Lights_On", lightOn);
    Particle.subscribe("Lights_Off", lightOff);
    Particle.subscribe("Lights_Flash", lightFlash);
    Particle.subscribe("Lights_Song", lightSong);
    
     pinMode(DAC, INPUT);
}

void loop() {

  int PixelColorBlue = strip.Color(0,0,128);
    int PixelColorRed = strip.Color(80,0,4);
    int PixelColorGreen = strip.Color(0,128,0);
    int PixelColorClear = strip.Color(0,0,0);
    if (dark ==1)
 {
if (mode == 1)
    {
   
            value[0] = analogRead(DAC);
        strip.setPixelColor( 0 , strip.Color(0,value[0],0));
        strip.setPixelColor( 1 , strip.Color(value[1],0,0));
        strip.setPixelColor( 2 , strip.Color(0,value[2],0));
        strip.setPixelColor( 3 , strip.Color(value[3],0,0));
        strip.setPixelColor( 4 , strip.Color(0,value[4],0));
        strip.setPixelColor( 5 , strip.Color(value[5],0,0));
        strip.setPixelColor( 6 , strip.Color(0,value[6],0));
        strip.setPixelColor( 7 , strip.Color(value[7],0,0));
        strip.setPixelColor( 8 , strip.Color(0,value[8],0));
        strip.setPixelColor( 9 , strip.Color(value[9],0,0));
        strip.show();
        value[9]=value[8];
        value[8]=value[7];
        value[7]=value[6];
        value[6]=value[5];
        value[5]=value[4];
        value[4]=value[3];
        value[3]=value[2];
        value[2]=value[1];
        value[1]=value[0];
     delay(15);
    }
if (mode == 0)
    {
        strip.setPixelColor( 0 , PixelColorGreen);
        strip.setPixelColor( 2 , PixelColorGreen);
        strip.setPixelColor( 4 , PixelColorGreen);
        strip.setPixelColor( 6 , PixelColorGreen);
        strip.setPixelColor( 8 , PixelColorGreen);
        strip.setPixelColor( 1 , PixelColorRed);
        strip.setPixelColor( 3 , PixelColorRed);
        strip.setPixelColor( 5 , PixelColorRed);
        strip.setPixelColor( 7 , PixelColorRed);
        strip.setPixelColor( 9 , PixelColorRed);

        strip.show();
    	delay(1000);

        strip.setPixelColor( 1 , PixelColorGreen);
        strip.setPixelColor( 3 , PixelColorGreen);
        strip.setPixelColor( 5 , PixelColorGreen);
        strip.setPixelColor( 7 , PixelColorGreen);
        strip.setPixelColor( 9 , PixelColorGreen);
        strip.setPixelColor( 0 , PixelColorRed);
        strip.setPixelColor( 2 , PixelColorRed);
        strip.setPixelColor( 4 , PixelColorRed);
        strip.setPixelColor( 6 , PixelColorRed);
        strip.setPixelColor( 8 , PixelColorRed);
        strip.show();
        
        delay(1000);
    }

  }
       if (dark == 0)
       {
        strip.setPixelColor( 1 , PixelColorClear);
        strip.setPixelColor( 3 , PixelColorClear);
        strip.setPixelColor( 5 , PixelColorClear);
        strip.setPixelColor( 7 , PixelColorClear);
        strip.setPixelColor( 9 , PixelColorClear);
        strip.setPixelColor( 0 , PixelColorClear);
        strip.setPixelColor( 2 , PixelColorClear);
        strip.setPixelColor( 4 , PixelColorClear);
        strip.setPixelColor( 6 , PixelColorClear);
        strip.setPixelColor( 8 , PixelColorClear);
        strip.show();
       }
}