assignment2_2: a2p2.o
	g++ a2p2.o -o assignment2_2
a2p2.o: a2p2.cpp
	g++ -c a2p2.cpp
debug: a2p2.cpp
	g++ -Wall -ansi -pedantic -g a2p2.cpp -o debug
test:
	./assignment2_2 < test.in > test.out
compare:
	diff orig.out test.out
clean:
	@rm -rf a2p2.o debug
