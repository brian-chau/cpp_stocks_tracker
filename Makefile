# 'make depend'      uses makedepend to automatically generate dependencies
#                    (dependencies are added to end of Makefile)
# 'make'             build executable file 'mycc'
# 'make clean'       removes all .o files
# 'make clean all'   removes all .o files and executable file

# define the C++ compiler to use
CC := g++
RM := rm -rf

# define any compile-time flags
CFLAGS := -Wall -Werror -g -std=c++11

# define any directories containing header files other than /usr/include
#
INC := ./headers ./sources
INCLUDES := $(foreach d, $(INC), -I$d)

LFLAGS := -L./libs

# This should generate a shared object
LDFLAGS := -shared

LIBS := -lcurl

# define the C++ source files
SRCS := $(wildcard sources/*.cpp)

OBJS := $(SRCS:.cpp=.o)

# define the executable file
MAIN := stocks_tracker

.PHONY: depend clean clean_all

all:    $(MAIN)
	@echo  'stocks_tracker' has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) sources/*.o *~
	$(RM) $(MAIN).dSYM

clean_all:
	$(RM) sources/*.o *~ $(MAIN)
	$(RM) $(MAIN).dSYM

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
