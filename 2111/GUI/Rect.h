#ifndef RECT_H
#define RECT_H

#include "Color.h"
#include "wx/wx.h"

class Rect
{
   private:
      int width;
      int height;
      Color* color;

   public:
      Rect(Color* color, int width, int height);
      virtual ~Rect();
      void draw(wxDC& dc, int x, int y);
};

#endif

