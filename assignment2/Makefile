CC=gcc
CXX=g++
RM=rm -f

SRCS=main.cc parser.cc lex.cc constantes.h
OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) -Wall -Wextra -o main $(OBJS)

main.o: main.cc parser.h
parser.o: parser.cc parser.h
lex.o: lex.cc lex.h
constantes.o: constantes.h

clean:
	$(RM) $(OBJS)
	
distclean: clean
	$(RM) main

build: main
	echo finished

run: build
	./main < positives.txt