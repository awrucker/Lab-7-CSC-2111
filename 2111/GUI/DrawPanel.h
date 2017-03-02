#ifndef DRAWPANEL_H
#define DRAWPANEL_H

#include "Drawable.h"
#include "Rect.h"
#include "wx/wx.h"
#include "wx/dcbuffer.h"

class DrawPanel : public wxPanel
{
 
public:
    DrawPanel(wxFrame* parent, Drawable* drawable);
	Drawable* drawable;
	
	void mouseLeftDown(wxMouseEvent& event);
 
    void paintEvent(wxPaintEvent& evt);
    //void paintNow();
 
    void render(wxDC& dc);
 
    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */
 
    DECLARE_EVENT_TABLE()
};

#endif
