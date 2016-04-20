clean:
	rm `find . -name "*.o"`

main: main.o parser/input.o parser/parser.o global/mines.o
	gcc main.o parser/{input.o,parser.o} global/mines.o -o main -g -l m

parser/input.o: parser/input.c
	cd parser; make input.o

parser/parser.o: parser/parser.c
	cd parser; make parser.o

global/mines.o: global/mines.c
	cd global; make mines.o

main.o: main.c
	gcc main.c -c -g
