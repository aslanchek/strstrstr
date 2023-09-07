#### Directories
LIB 	= lib
OBJ     = obj
INCLUDE = include

#### Compiler
CC = gcc

#### Compiler options
CFLAGS_WARNS   = -Wall -Wextra -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion  -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types  -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused  -Wvariadic-macros  -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-protector

CFLAGS_SANITZS = address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

CFLAGS_LIBS    = -lm

CFLAGS         = -O0 -g $(CFLAGS_LIBS) -I$(INCLUDE) -fsanitize=$(CFLAGS_SANITZS) $(CFLAGS_WARNS)

#### Libraries
LIBS     	= $(LIB)/dumb_puts.c $(LIB)/dumb_strcat.c $(LIB)/dumb_strchr.c $(LIB)/dumb_strcpy.c $(LIB)/dumb_strlen.c $(LIB)/dumb_strncat.c $(LIB)/dumb_strncpy.c $(LIB)/dumb_strnlen.c $(LIB)/dumb_fgets.c $(INCLUDE)/dumb_stpcpy.c $(INCLUDE)/dumb_string.h

LIBS_OBJ  	= $(OBJ)/dumb_puts.o $(OBJ)/dumb_strcat.o $(OBJ)/dumb_strchr.o $(OBJ)/dumb_strcpy.o $(OBJ)/dumb_strlen.o $(OBJ)/dumb_strncat.o $(OBJ)/dumb_strncpy.o $(OBJ)/dumb_strnlen.o $(OBJ)/dumb_fgets.o $(OBJ)/dumb_stpcpy.o


EXECUTABLE = main

#### Targets

all: init $(EXECUTABLE)

init: $(OBJ)

$(OBJ):
	@echo initialization
	@mkdir -p $@

$(EXECUTABLE): $(OBJ)/$(EXECUTABLE).o $(LIBS_OBJ)
	@echo [CC] $^ -o $@
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/$(EXECUTABLE).o: $(EXECUTABLE).c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ)/dumb_puts.o: $(LIB)/dumb_puts.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_strchr.o: $(LIB)/dumb_strchr.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_strlen.o: $(LIB)/dumb_strlen.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_strnlen.o: $(LIB)/dumb_strnlen.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_strcpy.o: $(LIB)/dumb_strcpy.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_strncpy.o: $(LIB)/dumb_strncpy.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_strcat.o: $(LIB)/dumb_strcat.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_strncat.o: $(LIB)/dumb_strncat.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_fgets.o: $(LIB)/dumb_fgets.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(OBJ)/dumb_stpcpy.o: $(LIB)/dumb_stpcpy.c
	@echo [CC] $< -o $@
	@$(CC) $(CFLAGS) -c $^ -o $@ 

clean:
	@echo 'removed object files'
	@rm -rf $(OBJ)

	@echo 'removed precompiled headers'
	@rm -f $(INCLUDE)/*.gch
