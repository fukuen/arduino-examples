#include "ST7789V.h"
#include "OV7740.h"
#include "Power.h"

#include "Adafruit_GFX.h"
#include <Wire.h>

SPIClass _spi(0);
ST7789V lcd(240, 320);
OV7740 cam(CAMERA_SDA_PIN, CAMERA_SCL_PIN, 2);

Image *img_ai, *img_display;

void setup() {
    camera_buffers_t buff;

    Serial.begin(115200);
    while (!Serial) {
        ;
    }
    Power.begin();

    if(0x00 != cam.reset(FRAMESIZE_QVGA))
    {
        Serial.printf("camera reset failed\n");
        while(1) {}
    }
    
    cam.get_buffers(&buff);
    if((NULL == buff.disply) || (NULL == buff.ai.r))
    {
        Serial.printf("get camera buffers failed\n");
        while(1) {}
    }

    img_ai = new Image(cam.width(), cam.height(), IMAGE_FORMAT_R8G8B8, buff.ai.r);
    img_display = new Image(cam.width(), cam.height(), IMAGE_FORMAT_RGB565, buff.disply);

    _spi.begin(TFT_CLK_PIN, TFT_MISO, TFT_MOSI, -1);
    lcd.begin();
    lcd.invertDisplay(1);
    lcd.setRotation(1);
    lcd.setTextSize(3);
    lcd.setFrameBuffer(img_display);
}

void loop() {
    if(0x00 != cam.snapshot())
    {
        Serial.printf("camera snapshot failed\n");
        return;
    }

    lcd.setCursor(40, 55);
    lcd.printf("Test1234");

    lcd.refresh();
}
