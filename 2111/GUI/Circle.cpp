#include "Circle.h"

Circle::Circle(Color* clr, int r, CSC2110::String* t)
{
   color = clr;
   radius = r;
   text = t;
}

Circle::~Circle()
{
   delete color;
}

void Circle::draw(wxDC& dc, int x, int y)
{
	const char* text_ch = text->getText();
	wxBrush circle_brush;
	wxColour circle_color(color->getRed()*255, color->getGreen()*255, color->getBlue()*255);
	circle_brush.SetColour(circle_color);
	dc.SetBrush(circle_brush); 
	dc.SetPen(wxPen(wxColour(0,0,0), 5));
	dc.DrawCircle(wxPoint(x, y), radius);
	
	wxString font_str("Verdana");
	wxFont font(font_str);
	font.SetPointSize(12);
	dc.SetFont(font);
	wxString text(text_ch);
	dc.DrawText(text, x - 10, y - 13);
}
