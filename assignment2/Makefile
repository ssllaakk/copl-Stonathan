
all: main

main: main.o parser.o
	g++ -Wall -Wextra main.o parser.o lex.o tree.o -o main

main.o: main.cc parser.o
	g++ -Wall -Wextra -c main.cc

parser.o: parser.cc parser.h lex.o tree.o
	g++ -Wall -Wextra -c parser.cc

lex.o: lex.cc lex.h token.h constantes.h
	g++ -Wall -Wextra -c lex.cc

tree.o: tree.cc tree.h node.h token.h constantes.h
	g++ -Wall -Wextra -c tree.cc



clean:
	rm -f *.o 
	rm main
	
build: main
	echo finished

run: build
	./main < positives.txt