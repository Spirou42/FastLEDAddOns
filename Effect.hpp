/**
Effects.hpp
*/

#ifndef __EFFECT_H__
#define __EFFECT_H__
#include <Arduino.h>
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

protected:
  String _name;
};

int effectRunner(unsigned long now, void* userdata);
#endif
