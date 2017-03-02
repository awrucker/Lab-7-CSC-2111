#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "wx/wx.h"

class Drawable
{
   private:

   public:
      Drawable() {};
      virtual ~Drawable() {};
	  
      virtual void draw(wxDC&  dc, int width, int height) = 0;
      virtual void mouseClicked(int x, int y) = 0;
};

#endif
