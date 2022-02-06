mat_lib: main.o mat_lib.o
	g++ -o mat_lib main.o mat_lib.o

main.o: main.cpp mat_lib.h
	g++ -c main.cpp

mat_lib.o: mat_lib.cpp mat_lib.h
	g++ -c mat_lib.cpp

clean:
	rm *.o mat_lib