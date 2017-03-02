#include "ImageLoader.h"
#include <windows.h>

#include <iostream>
using namespace std;

wxBitmap ImageLoader::loadImageRGBA(const char* id)
{
    HINSTANCE hInst = GetModuleHandle(0);
	
    HANDLE hBitMap = LoadImageA(hInst, id, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
    BITMAP bitmap;
    GetObject(hBitMap, sizeof(BITMAP), &bitmap);

    int width = bitmap.bmWidth;
    int height = bitmap.bmHeight;
    int depth = bitmap.bmBitsPixel;
    int size = height*width*depth/8;

    byte* lpBits = new byte[size];
    GetBitmapBits((HBITMAP) hBitMap, size, lpBits);

    byte* rgb = new byte[(size*4)/4];

    int count = 0;
    for (int i = 0; i < size; i += 4)
    {
		rgb[count] = lpBits[i];  //r
		rgb[count + 1] = lpBits[i + 1];  //g
		rgb[count + 2] = lpBits[i + 2];  //b
		rgb[count + 3] = lpBits[i + 3];  //a
		count += 4;
    }

    delete[] lpBits;

	wxBitmap wxbitmap((const char*) rgb, width, height, depth);
	return wxbitmap;
}

//this procedure doesn't seem to work!
wxBitmap ImageLoader::loadImageRGB(const char* id)
{
    HINSTANCE hInst = GetModuleHandle(0);

    HANDLE hBitMap = LoadImageA(hInst, id, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
    BITMAP bitmap;
    GetObject(hBitMap, sizeof(BITMAP), &bitmap);

    int width = bitmap.bmWidth;
    int height = bitmap.bmHeight;
    int depth = bitmap.bmBitsPixel;
    int size = height*width*depth/8;

    byte* lpBits = new byte[size];
    GetBitmapBits((HBITMAP) hBitMap, size, lpBits);

    byte* rgb = new byte[size*3/4];

    int count = 0;
    for (int i = 0; i < size; i += 4)
    {
       rgb[count] = lpBits[i];  //r  //this used to be b with + 2
       rgb[count + 1] = lpBits[i + 1];  //g
       rgb[count + 2] = lpBits[i + 2];  //b  //this used to be r without + 2
       //skip alpha
       count += 3;
    }

    delete[] lpBits;
	
	wxBitmap wxbitmap((const char*) rgb, width, height, depth);
	return wxbitmap;
}
