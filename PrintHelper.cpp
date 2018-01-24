#include <PrintHelper.h>
#include <FastLED.h>
#include <Streaming.h>

Print& operator<<(Print& out,q88 data){
  float p = data.i+(data.f /256.0);
  out.print(p,6);
  return out;
}
