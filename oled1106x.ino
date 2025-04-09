#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BITMAP_WIDTH 128
#define BITMAP_HEIGHT 64

const unsigned char bitmap1[] PROGMEM = { 

  //bitmaps aqui
};


const unsigned char bitmap2[] PROGMEM = { 

  //bitmaps aqui
};

const unsigned char bitmap3[] PROGMEM = { 

  //bitmaps aqui
};

const unsigned char bitmap4[] PROGMEM = { 

  //bitmaps aqui
};

const unsigned char bitmap5[] PROGMEM = { 

  //bitmaps aqui
};


const unsigned char bitmap6[] PROGMEM = { 

  //bitmaps aqui
};


const unsigned char bitmap7[] PROGMEM = { 

  //bitmaps aqui
};
const unsigned char bitmap8[] PROGMEM = { 
  
  //bitmaps aqui
  
  };
    const unsigned char bitmap9[] PROGMEM = { 
//bitmaps aqui 
};


  const unsigned char bitmap10[] PROGMEM = { 
//bitmaps aqui 
};
// Luego arma la matriz
const unsigned char* bitmaps[5][2] = {
  {bitmap1, bitmap2},
  {bitmap3, bitmap4},
  {bitmap5, bitmap6},
  {bitmap7, bitmap8},
  {bitmap9, bitmap10},
};

void setup() {
  Serial.begin(9600);
  delay(250);
  display.begin(i2c_Address, true);
  display.display();
  delay(200);
  display.clearDisplay();
}

void loop() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      display.clearDisplay();
      // Dibuja desde la memoria PROGMEM
      display.drawBitmap(0, 0, bitmaps[i][j], BITMAP_WIDTH, BITMAP_HEIGHT, 1);
      display.display();
      delay(2000);
    }
  }
}
