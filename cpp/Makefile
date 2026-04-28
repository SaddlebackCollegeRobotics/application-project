EXE  := run_me              # name of the output executable
SRCS := $(wildcard *.cpp) $(wildcard src/*.cpp)   # SRCS holds the names of all *.cpp files
OBJS := $(SRCS:.cpp=.o)     # OBJS holds the same but with .cpp replaced by .o


all: $(EXE)


run: all
	@./$(EXE)


clean:
	rm -f $(OBJS) $(EXE)


$(EXE): $(OBJS)
# g++ -o <target> <all dependencies>
	g++ -o $@ $^


%.o: %.cpp
# g++ -c -o <target> <first dependency>
	g++ -c -o $@ $<


# these targets are not file targets
.PHONY: all run clean
