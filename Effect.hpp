/**
Effects.hpp
*/

#ifndef __EFFECT_H__
#define __EFFECT_H__
#include <Arduino.h>
#include <Types.h>
#include <FastLEDAddOns_Intern.h>
#include <UI_Helpers.hpp>
/**
baseclass for LED Effects
*/
ADDONS_NAMESPACE_BEGIN
typedef std::vector<ValueWrapper*> ParameterList;
ADDONS_NAMESPACE_END
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

  /** the framerate for the effect */
  virtual uint16_t frameRate(){return 1000/60;}
	/**
	called after the last frame. restore your book keeping here and clean up your dynamic objects
	*/
	virtual void stopEffect(){};

  String name(){return _name;}

  /** parameter handling
  user cocntrolable parameters are stored in
  */
  FastLEDAddOns::ParameterList::iterator parameters(){
    return _parameters.begin();
  }

  virtual size_t 					numberOfParameters(){return 0;};
	virtual ValueWrapper* 	parameterAt(size_t idx){Serial <<"Gnartz";return NULL;};
	virtual String  		    parameterNameAt(size_t idx){Serial <<"Gnartz2";return "";};

protected:
  void addParameter(ValueWrapper* value){
    _parameters.push_back(value);
  }
  FastLEDAddOns::ParameterList _parameters;
  String        _name;
};

/** if you use the effectRunner method you have to declare the following: **/

ADDONS_NAMESPACE_BEGIN
extern EffectList systemEffectList;
extern EffectList::iterator currentRunningEffect;

int effectRunner(unsigned long now, void* userdata);
extern volatile int16_t requestedFrameRate;
ADDONS_NAMESPACE_END
#endif
