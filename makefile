CFLAGS   = `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs`
PROG = GOL
CXX = gcc
OBJS   = main.c game_functions.c render_functions.c

# top-level rule to create the program.
all: $(PROG)

# compiler
$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) $(CFLAGS) $(OBJS) -o $(PROG)

# cleaning everything that can be automatically recreated with "make"
clean:
	rm $(PROG) *.o
