/**
Types.h
a collection of usefull Types, mostly collections
*/
// some datatype to map Names(Strings) palettes or Effects


#include <Arduino.h>
#include <vector>
//#include <tuple>

#include <FastLED.h>
class Effect;

/** some usefull collections */

/** a list of named Palettes, easy to synchronise with a selection menu */
typedef std::pair<const String,CRGBPalette16> PalettePair;
typedef std::vector<PalettePair*> PaletteList;

/** a list of named effect functions as a simple way to implement effects*/
typedef void(*simpleEffectHandler)(void);
typedef std::pair<const String, simpleEffectHandler> SimpleEffectPair;
typedef std::vector<SimpleEffectPair*> SimpleEffectList;


typedef std::vector<Effect*> EffectList;
/**
  you have to define and initialise the following by yourself
**/
extern PaletteList systemPalettes;
extern PaletteList::iterator currentSystemPalette;
