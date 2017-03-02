#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "wx/wx.h"

class ImageLoader
{
   public:
      static wxBitmap loadImageRGB(const char* id);
      static wxBitmap loadImageRGBA(const char* id);
};

#endif 
