CC := g++
CFLAGS := -std=c++11 -Wall -Wextra
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system


SRCDIR := source
INCDIR := headers
BUILDDIR := build


SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
MAIN := main.cpp


TARGET := my_game
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
	$(RM) $(BUILDDIR)*.o $(TARGET)