
CC := g++
CFLAGS := -std=c++11 -Wall -Wextra
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system


SRCDIR := source
INCDIR := headers
BUILDDIR := build


SRCDIRS := $(shell find $(SRCDIR) -type d)
SOURCES := $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))

OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
MAIN := main.cpp


TARGET := my_game
RM := rm -rf

ifeq ($(OS),Windows_NT)
    # Change forward slashes to backslashes for Windows paths
    
    TARGET := $(TARGET).exe

    
endif


$(TARGET):  $(OBJECTS) $(MAIN) 
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $(MAIN) $(OBJECTS) $(SFML_LIBS) -g 

BUILDDIRS:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | BUILDDIRS
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $< -g

clean:
	$(RM) $(BUILDDIR) $(TARGET)
