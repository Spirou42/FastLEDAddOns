/**
Effects.hpp
*/

#ifndef __EFFECT_H__
#define __EFFECT_H__
#include <Arduino.h>
#include <Types.h>
/**
baseclass for LED Effects
*/
class Effect {

public:
  Effect():_name(String()){};
  Effect(String name):_name(name){};

  /**
		called after the effect programm got switch and before the first frame.
		put your book keeping and initialization in here
	*/
	virtual void startEffect(){}; 											///< book keeping on startup

  /**
		called for each and every fram
	*/
	virtual void frame(unsigned long now){};

	/**
	called after the last frame. restore your book keeping here and clean up your dynamic objects
	*/
	virtual void stopEffect(){};
  String name(){return _name;}
protected:
  String _name;
};

/** if you use the effectRunner method you have to declare the following: **/

extern EffectList systemEffectList;
extern EffectList::iterator currentRunningEffect;

int effectRunner(unsigned long now, void* userdata);

#endif
