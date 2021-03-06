# Name
PROJECT = Aula 8

# Objects
OBJECTS = pratica9.o fila.o
BIN = pratica9

# Maintainer flags
CPP_FLAGS = -I.
C_FLAGS = -Wall -Werror
LD_FLAGS = -lm
CC = gcc
MAKE = make

# Install prefix
PREFIX=.

# Default target
all: $(BIN)

# Binary
$(BIN) : $(OBJECTS)
	$(CC) $(CPP_FLAGS) $(LD_FLAGS) $(LDFLAGS) $^ -o $@

# Pattern rule for object-source dependences
%.o : %.c
	$(CC) $(CPP_FLAGS) $(CPPFLAGS) $(C_FLAGS) $(CFLAGS)-c $<

# Automatic object-header dependences
makefiles = $(OBJECTS:%.o=%.d)

ifeq (, $(filter clean uninstall, $(MAKECMDGOALS)))
include $(makefiles)
endif

%.d : %.c
	$(CC) $(CPP_FLAGS) $(CPPFLAGS) -c $<  -MM -MT '$(<:.c=.o) $@' $< > $@

# Running
run:
	@./$(BIN)

# Zip
zip:
	zip $(BIN).zip $(OBJECTS:%.o=%.c) $(OBJECTS:%.o=%.h) Makefile

# Memory leak verification
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(BIN)

# Cleaning
.PHONY : clean

clean:
	rm -f $(OBJECTS) $(makefiles) $(BIN) *.zip
	rm -f *~ \#*
	rm -rf $(PROJECT)
