clean:
	rm `find . -name "*.o"`

main: main.o parser/input.o parser/parser.o
	gcc main.o parser/{input.o,parser.o} -o main -g -l m

parser/input.o: parser/input.c
	cd parser; make input.o

parser/parser.o: parser/parser.c
	cd parser; make parser.o

main.o: main.c
	gcc main.c -c -g
