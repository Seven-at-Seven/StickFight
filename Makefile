CC := g++
CFLAGS := -std=c++11 
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


SRCDIR := source
INCDIR := headers
BUILDDIR := build


SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
MAIN := main.cpp


TARGET := Stick_Fight_9000
RM := rm -f

ifeq ($(OS),Windows_NT)
    # Change forward slashes to backslashes for Windows paths
    
    TARGET := $(TARGET).exe

    
endif


$(TARGET): $(OBJECTS) $(MAIN)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $(MAIN) $(OBJECTS) $(SFML_LIBS)


$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<


clean:
	$(RM) $(BUILDDIR)/*.o $(TARGET)
