#include "Rect.h"

Rect::Rect(Color* clr, int w, int h)
{
	color = clr;
	width = w;
	height = h;
}

//Rect is not the owner of color, so shouldn't delete color
Rect::~Rect()
{
	//delete color;
}

void Rect::draw(wxDC& dc, int x, int y)
{
	//draw a Rectangle centered on (x, y)
	int w_2 = width/2;
	int h_2 = height/2;
	
	wxPen rect_pen;
	wxBrush rect_brush;
	wxColour rect_color(color->getRed()*255, color->getGreen()*255, color->getBlue()*255);
	rect_pen.SetColour(rect_color);
	rect_brush.SetColour(rect_color);
	dc.SetPen(rect_pen);
	dc.SetBrush(rect_brush);
	dc.DrawRectangle(wxPoint(x - w_2, y - h_2), wxSize(width, height));  
}

