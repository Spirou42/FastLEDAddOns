/**
Effect.cpp
**/


#include "Effect.hpp"
#include <Streaming.h>
ADDONS_NAMESPACE_BEGIN
int effectRunner(unsigned long now, void* userdata){
  static EffectList::iterator lastTimeEffect = systemEffectList.end();
  //Serial << "EffectR:"<<endl;
  if(lastTimeEffect != currentRunningEffect){
    //Serial<< "Changed Effect"<<endl;
    if(lastTimeEffect != systemEffectList.end()){
      (*lastTimeEffect)->stopEffect();
      //Serial<<"Stop: "<<(*lastTimeEffect)->name()<<endl;
    }
    (*currentRunningEffect)->startEffect();
    //Serial << "Start: "<<(*currentRunningEffect)->name()<<endl;
    lastTimeEffect = currentRunningEffect;
  }
  (*currentRunningEffect)->frame(now);
  return 0;
}
ADDONS_NAMESPACE_END
