// This #include statement was automatically added by the Particle IDE.
#include "Grove_LCD_RGB_Backlight/Grove_LCD_RGB_Backlight.h"

// This #include statement was automatically added by the Particle IDE.
#include "Grove_LCD_RGB_Backlight/Grove_LCD_RGB_Backlight.h"

int data0=0;
int dark=0;
rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 0;

void breath(unsigned char color)
{

    for(int i=0; i<255; i++)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
    for(int i=254; i>=0; i--)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
}



void setup() {
    //set up the LCD's number of columns and rows:
   Particle.variable("dark", &dark, INT);
   Serial.begin(9600);
   
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    //Print a message to the LCD
    lcd.print("Merry Christmas!");
    
    
    
    delay(1000);
}

void loop() {
    
    data0=analogRead(A1);
    
    // Turn off the display:
    lcd.noDisplay();
    delay(500);
    
    if (data0>4000){
        dark=1;
        // Turn on the display:
        lcd.display();
        delay(500);
        breath(REG_RED);
        breath(REG_GREEN);
    }
    
    else
        dark=0;
    
    Serial.print(data0);
    Serial.println();
    

   
   
    //set the cursor to column 0, line 1
    //(note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0,1);

}