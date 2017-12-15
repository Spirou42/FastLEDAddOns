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
/**
  you have to define and initialise the following by yourself
**/
extern PaletteList systemPalettes;
extern PaletteList::iterator currentSystemPalette;
