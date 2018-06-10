all: arr

arr: main.o count.o
	g++ -o arr main.o count.o
main.o:	main.cpp
	g++ -c -o main.o main.cpp
count.o: count.cpp
	g++ -c -o count.o count.cpp
clean: 
	rm main.o count.o
