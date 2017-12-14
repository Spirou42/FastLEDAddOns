/* simple Matrix test code */

#include <FastLED.h>
#include <FastLEDAddOns.h>
#include <Queue.h>
#include "MatrixTest.h"


CRGB leds[NUM_LEDS+1];        // frameBuffer
CRGB backBuffer [NUM_LEDS+1];  // backbuffer
Queue taskQueue;
XYMatrix display(13,10,leds,backBuffer,true,true,true);

int processLEDEffects(unsigned long now,void* data){
  static int line = 0;
  static int delayedFrame = 0;
  static int step = 1;
  display.clear();
  FLPoint s(0,line);
  FLPoint e(12,line);
  display.line(s,e,CRGB::White);
  display.flush();

  delayedFrame++;
  if(delayedFrame > 10){
    delayedFrame = 0;
    line +=step;
    if (line >=9){
      line = 9;
      step = -1;
    }else if (line <=0){
      step = 1;
      line = 0;
    }
  }
  return 0;

}

int backbufferBlender(unsigned long now, void *data){
  uint8_t frac = 7;
  static uint8_t lastFrac =0;
  if(frac != lastFrac){
  	//		Serial << "frac"<<frac<<endl;
  	lastFrac = frac;
  }

  #if DEBUG_EFFECTS
  Serial <<".";
  #endif
  // if(frac < 4){
  // 	#if DEBUG_EFFECTS
  // 	Serial << "Frac cliped to 4, was "<<frac<<endl;
  // 	#endif
  // 	frac = 4;
  // }
  for(uint16_t i=0;i<NUM_LEDS;i++){
  	leds[i]=nblend(leds[i],backBuffer[i],frac);
  }
  // if( millis() < 5000 ) {
  // 	FastLED.setBrightness( scale8( Brightness.currentValue(), (millis() * 256) / 5000));
  // } else {
  // 	FastLED.setBrightness(Brightness.currentValue());
  // }
  FastLED.show();
  return 0;
}

void setup(){
  FastLED.addLeds<CHIPSET, LED_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(COLOR_CORRECTION);
  FastLED.clear(true);
  FastLED.show();
  FastLED.setBrightness( LED_BRIGHTNESS );
  fill_solid(leds,NUM_LEDS,CRGB::Red);
  FastLED.show();

  taskQueue.scheduleFunction(processLEDEffects,NULL,"EFFC",0,1000/FRAMES_PER_SECOND);
  taskQueue.scheduleFunction(backbufferBlender,NULL,"BBLN",0,1000/120);
}

void loop(){
  taskQueue.Run(millis());
}
