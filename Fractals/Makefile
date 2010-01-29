# Project: Fractals
# Using WizSDL_2DEngine
# Makefile for building WIZ binary

ARMDIR    = /opt/arm-openwiz-linux-gnu
CXX       = $(ARMDIR)/bin/arm-openwiz-linux-gnu-c++
OBJ       = src/WizSDLapp.o src/Shape.o src/Textures.o src/Move.o
LIBS      = -L$(ARMDIR)/lib -Wl,-rpath,$(ARMDIR)/lib -lSDL -lSDL_mixer
INCS      = -I$(ARMDIR)/include/ -I$(ARMDIR)/include/SDL
BIN       = Fractals.gpe
DEFINES   = -DWIZ
CXXFLAGS  = $(INCS) $(DEFINES) -fno-rtti -fno-exceptions -fno-pcc-struct-return -fstrict-aliasing -O2


all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) src/Fractals.cpp -o $(BIN) $(LIBS)

clean:
	rm $(BIN)

cleanall:
	rm $(BIN) $(OBJ)

cleanObj:
	rm $(OBJ)

WizSDLapp.o : src/WizSDLapp.h src/WizSDLapp.cpp
	$(CXX) $(CXXFLAGS) src/WizSDLapp.cpp -o $@ -c

Shape.o : src/Shape.h src/Shape.cpp
	$(CXX) $(CXXFLAGS) src/Shape.cpp -o $@ -c

Textures.o : src/Textures.h src/Textures.cpp
	$(CXX) $(CXXFLAGS) src/Textures.cpp -o $@ -c

Move.o : src/Move.h src/Move.cpp
	$(CXX) $(CXXFLAGS) src/Move.cpp -o $@ -c
