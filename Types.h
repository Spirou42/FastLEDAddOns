/**
Types.h
a collection of usefull Types, mostly collections
*/
// some datatype to map Names(Strings) palettes or Effects


#include <Arduino.h>
#include <vector>
//#include <tuple>

#include <FastLED.h>


typedef std::pair<const String,CRGBPalette16> PalettePair;
typedef std::vector<PalettePair*> PaletteList;

typedef void(*simpleEffectHandler)(void);
typedef std::pair<const String, simpleEffectHandler> SimpleEffectPair;
typedef std::vector<SimpleEffectPair*> SimpleEffectList;

/**
  you have to define and initialise the following by yourself
**/
extern PaletteList systemPalettes;
extern PaletteList::iterator currentSystemPalette;
