AutomatedMakefile = am
CC = g++
CXXFLAGS = -Wno-deprecated-declarations

PROJECT_PATH = $(CURRENT_DIR)
GUI_PATH = $(DRIVE_LETTER)/TDM-GCC-64/wxWidgets-3.1.0

INC_DIRS = -I$(CURRENT_DIR)/../CSC2110 -I$(GUI_PATH)/include -I$(GUI_PATH)/lib/gcc510TDM_x64_dll/mswu
#INC_DIRS = -I$(CURRENT_DIR)/../CSC2110 -I$(GUI_PATH)/include -I$(GUI_PATH)/lib/gcc510TDM_x64_dll/mswud
LIB_DIRS = -L$(CURRENT_DIR)/../CSC2110 -L$(GUI_PATH)/lib
LIBS = -lCSC2110 -lwxmsw31u_core -lwxbase31u
#LIBS = -lCSC2110 -lwxmsw31ud_core -lwxbase31ud

COMPILE = $(CC) $(CXXFLAGS) $(INC_DIRS) -c
LINK = $(CC) $(CXXFLAGS) $(LIB_DIRS) -o

FILES = Color.o Line.o Circle.o Rect.o ImageLoader.o DrawPanel.o

all: GUI_LIB

GUI_LIB: 		$(FILES)

Color.o:		Color.h Color.cpp
			$(COMPILE) Color.cpp

Line.o:			Line.h Line.cpp
			$(COMPILE) Line.cpp

Circle.o:		Circle.h Circle.cpp
			$(COMPILE) Circle.cpp

Rect.o:			Rect.h Rect.cpp
			$(COMPILE) Rect.cpp

ImageLoader.o:		ImageLoader.h ImageLoader.cpp
			$(COMPILE) ImageLoader.cpp

DrawPanel.o:		Drawable.h DrawPanel.h DrawPanel.cpp
			$(COMPILE) DrawPanel.cpp


