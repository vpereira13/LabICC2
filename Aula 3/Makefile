# Name
PROJECT = Aula 3

# Objects
OBJECTS = pratica4.o listaligada.o
BIN = pratica4

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
	$(CC) $(LD_FLAGS) $(LDFLAGS) $^ -o $@

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
	valgrind --leak-check=full --show-leak-kinds=all -v ./$(BIN)

# Cleaning
.PHONY : clean

clean:
	rm -f $(OBJECTS) $(makefiles) $(BIN) *.zip
	rm -f *~ \#*
	rm -rf $(PROJECT)
