/**
Effect.cpp
**/


#include "Effect.hpp"
#include <Streaming.h>
ADDONS_NAMESPACE_BEGIN
typedef void(*postFrameCallback)(unsigned long now);
volatile int16_t requestedFrameRate;

int effectRunner(unsigned long now, void* userdata){
  static EffectList::iterator lastTimeEffect = systemEffectList.end();
  //Serial << "EffectR:"<<(*currentRunningEffect)->name()<<endl;
  if(lastTimeEffect != currentRunningEffect){
    Serial<< "Changed Effect"<<endl;
    if(lastTimeEffect != systemEffectList.end()){
      (*lastTimeEffect)->stopEffect();
      Serial<<"Stop: "<<(*lastTimeEffect)->name()<<endl;
    }
    (*currentRunningEffect)->startEffect();
    Serial << "Start: "<<(*currentRunningEffect)->name()<<endl;
    lastTimeEffect = currentRunningEffect;
    //requestedFrameRate = (*currentRunningEffect)->frameRate();
  }
  (*currentRunningEffect)->frame(now);
  requestedFrameRate = (*currentRunningEffect)->frameRate();
  if(userdata){
    postFrameCallback p = (postFrameCallback)userdata;
    p(now);
  }
  return 0;
}
ADDONS_NAMESPACE_END
