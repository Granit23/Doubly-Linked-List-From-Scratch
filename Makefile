
output: main.o Node.o DubLinkList.o Menu.o validateInput.o
	g++ -std=c++11 main.o Node.o DubLinkList.o Menu.o validateInput.o -o dll 

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Node.o: Node.cpp Node.hpp
	g++ -std=c++11 -c Node.cpp

DubLinkList.o: DubLinkList.cpp DubLinkList.hpp
	g++ -std=c++11 -c DubLinkList.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

validateInput.o: validateInput.cpp validateInput.hpp
	g++ -std=c++11 -c validateInput.cpp

clean:
	rm *.o dll
