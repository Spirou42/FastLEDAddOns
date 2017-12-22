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
  XYMatrix(uint8_t w, uint8_t h, CRGB* buffer,CRGB* bBuffer=NULL,bool serp=true,bool flipped=true,bool rot=true):_width(w),_height(h),_buffer(buffer),_backBuffer(bBuffer),_isSerpentine(serp),_isFlipped(flipped),_isRotated(rot){};

  uint8_t width(){return _width;}
  uint8_t height(){return _height;}

  void setPixel(uint8_t x, uint8_t y, CRGB color);
	void setPixel(FLPoint coord,CRGB color);
	CRGB getPixel(uint8_t x, int8_t y);
	CRGB getPixel(FLPoint coord);
  void clear();

	void clearAll();
	void fill(CRGB color);
  void fadeToBlack(uint8_t by);

	void flush();
	void setBrightness(uint8_t b);
	uint8_t brightness();

  void setFlipped(bool flag){_isFlipped = flag;}
  bool isFlipped(){return _isFlipped;}
	// Bresenham line algorythm
	void line(FLPoint st, FLPoint en, CRGB color);
  uint16_t XY(uint8_t x, uint8_t y);

protected:
  uint8_t _width,_height;    ///< dimensions of the Matrix
  CRGB* _buffer;
  CRGB* _backBuffer;
  bool _isSerpentine;
  bool _isFlipped;
  bool _isRotated;
};

#endif
