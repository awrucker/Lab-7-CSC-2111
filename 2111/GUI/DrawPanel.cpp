#include "DrawPanel.h"
#include "Color.h"

#include <iostream>
using namespace std;

// some useful events
/*
 void BasicDrawPane::mouseMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseDown(wxMouseEvent& event) {}
 void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
 void BasicDrawPane::rightClick(wxMouseEvent& event) {}
 void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
 void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
 void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
 */
 
 BEGIN_EVENT_TABLE(DrawPanel, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */
 
EVT_LEFT_DOWN(DrawPanel::mouseLeftDown)
 
// catch paint events
EVT_PAINT(DrawPanel::paintEvent)
 
END_EVENT_TABLE()
 
DrawPanel::DrawPanel(wxFrame* parent, Drawable* d) : wxPanel(parent)
{
	drawable = d;
	SetBackgroundStyle(wxBG_STYLE_PAINT); 
}

void DrawPanel::mouseLeftDown(wxMouseEvent& event)
{
	int x = event.GetX();
	int y = event.GetY();
	drawable->mouseClicked(x, y);
	Refresh();
}
 
/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */
 
void DrawPanel::paintEvent(wxPaintEvent & evt)
{
	wxAutoBufferedPaintDC dc(this);
    //wxPaintDC dc(this);
    render(dc);
}
 
/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 *
 * In most cases, this will not be needed at all; simply handling
 * paint events and calling Refresh() when a refresh is needed
 * will do the job.
 */
 /*
void DrawPanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}
 */
 
/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void DrawPanel::render(wxDC&  dc)
{
	int width = 0;
	int height = 0;
	dc.GetSize(&width, &height);
	
	Color color(255, 255, 255);
	Rect rect(&color, width, height);
	rect.draw(dc, width/2, height/2);
	
	drawable->draw(dc, width, height);
}

