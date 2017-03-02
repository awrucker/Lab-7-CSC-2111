#include "Line.h"

Line::Line(Color* clr, double l_w)
{
   color = clr;
   line_width = l_w;
}

Line::~Line()
{
   delete color;
}

void Line::draw(wxDC&  dc, int x1, int y1, int x2, int y2)
{
    dc.SetPen( wxPen( wxColor(color->getRed()*255, color->getGreen()*255, color->getBlue()*255), line_width ) ); 
    dc.DrawLine(x1, y1, x2, y2); 
}

