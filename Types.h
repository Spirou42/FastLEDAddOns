/**
Types.h
a collection of usefull Types, mostly collections
*/
// some datatype to map Names(Strings) palettes or Effects

#ifndef __TYPES_H__
#define __TYPES_H__

#include <Arduino.h>
#include <vector>
//#include <tuple>

#include <FastLED.h>
class Effect;

/** some usefull collections */

/** a list of named Palettes, easy to synchronise with a selection menu */
struct Palette_t{
 public:
  Palette_t(CRGBPalette16 p, bool b):palette(p),loop(b){};
  CRGBPalette16 palette;
  bool  loop;
};
typedef std::pair<const String,Palette_t> PalettePair;
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
#endif
