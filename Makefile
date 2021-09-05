CC := g++
TARGET = main
SRCS = main.cpp
SRCS += dijkstra.cpp
OBJS = $(SRCS:.cpp=.o)

# dir path having include files
INCDIR =-I /usr/include/eigen3/
 
# dir path having lib files
LIBDIR =-L /usr/lib/
 
# lib files to add
# LIBS    = 

# make target file
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
	
# make obj file
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

# "make all" -> execute "make clean" and "make" at the same time 
all: clean $(OBJS) $(TARGET)

# "make clean" -> detele obj file and execute file and .d file
clean:
	-rm -f $(OBJS) $(TARGET) *.d