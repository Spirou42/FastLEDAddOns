/**
  XYMatrix.h

  mapping class for simple rectangular LED Mapping

  */

#ifndef __XYMATRIX_H__
#define __XYMATRIX_H__
#include <Arduino.h>
#include <Streaming.h>
#include <FastLED.h>

typedef struct _FLPoint{
  int16_t x;              ///< x-part
  int16_t y;              ///< y-part
  _FLPoint(int16_t X,int16_t Y):x(X),y(Y){}; ///< Basic constructor
  _FLPoint():x(0),y(0){};                     ///< empty constructor creates a (0,0)
  _FLPoint( const _FLPoint& k){x=k.x;y=k.y;};
  bool operator==(_FLPoint p){return (x==p.x)&&(y==p.y);}
  bool operator!=(_FLPoint p){return !(*this == p);}
  _FLPoint operator+=(_FLPoint p){x+=p.x;y+=p.y;return *this;};
  //_FLPoint operator+(_FLPoint &p){_FLPoint r; r.x=p.x+x;r.y=p.y+y;return r;}
  _FLPoint operator+(_FLPoint p){_FLPoint r; r.x=p.x+x; r.y= p.y+y;return r;}
}FLPoint;

typedef struct _FLSize{
  int16_t w,h;
  _FLSize():w(0),h(0){};
  _FLSize(const _FLSize & k){w=k.w;h=k.h;};
  _FLSize(int16_t w, int16_t h):w(w),h(h){};
  bool operator==(_FLSize s){return (s.w == w)&&(s.h == h);}
  bool operator!=(_FLSize s){return !(*this == s);}
  _FLSize operator+=(_FLSize s){w+=s.w;h+=s.h; return *this;};
  _FLSize operator+(_FLSize p){_FLSize r; r.w=p.w+w;r.h=p.h+h;return r;}
  _FLPoint operator+(_FLPoint p){_FLPoint r; r.x =p.x+w; r.y = p.y+h; return r; }
  _FLSize operator+=(int t){w+=t;h+=t; return *this;};
  _FLSize operator*(int k){_FLSize l;l.w=k*w;l.h=k*h;return l;}
}FLSize;

typedef struct _FLRect{
  FLPoint origin;
  FLSize  size;
  _FLRect():origin(),size(){};
  _FLRect(const _FLRect &k){origin = k.origin; size = k.size;};
  _FLRect(FLPoint o, FLSize s){origin = o; size = s;};
  _FLRect(int16_t x, int16_t y, int16_t w, int16_t h):origin(x,y),size(w,h){};
}FLRect;

class XYMatrix {
public:
  XYMatrix(uint16_t w, uint16_t h, CRGB* buffer,bool serp=true,bool flipped=false):_width(w),_height(h),_buffer(buffer),_isSerpentine(serp){};

  uint16_t width(){return _width;}
  uint16_t height(){return _height;}

  void setPixel(int16_t x, int16_t y, CRGB color);
	void setPixel(FLPoint coord,CRGB color);
	CRGB getPixel(int16_t x, int16_t y);
	CRGB getPixel(FLPoint coord);
  void clear();

	void clearAll();
	void fill(CRGB color);

	void flush();
	void setBrightness(uint8_t b);
	uint8_t brightness();

	// Bresenham line algorythm
	void line(FLPoint st, FLPoint en, CRGB color);

protected:
  uint16_t _width,_height;    ///< dimensions of the Matrix
  CRGB* _buffer;
  bool _isSerpentine;
  bool _isFlipped;
};

#endif
