# $Id$
# plain simple Makefile to build make

CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall -Wextra -ansi -g
LDFLAGS = 

HEADERS = driver.h parser.h scanner.h node.h \
    y.tab.h FlexLexer.h location.hh position.hh stack.hh

all: main

# Generate scanner and parser

parser.cc: parser.yy
	$(YACC) -o parser.cc --defines=parser.h parser.yy

scanner.cc: scanner.ll
	$(LEX) -o scanner.cc scanner.ll

# Implicit rule to compile c++ files

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

# Link executable

main: main.o parser.o scanner.o driver.o 
	$(CXX) $(LDFLAGS) -o $@ main.o parser.o scanner.o driver.o node.cc

clean:
	rm -f main *.o

extraclean: clean
	rm -f parser.cc parser.h scanner.cc
