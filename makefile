CFLAGS   = -g `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_gfx -lSDL2_ttf -lm
PROG = main
CXX = gcc
OBJS   = main.c

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
%.o: %.c %.h defs.h
	$(CXX) $(CFLAGS) -c $<

# linking the program
$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) $(LDFLAGS)

# cleaning everything that can be automatically recreated with "make"
clean:
	rm $(PROG) *.o
