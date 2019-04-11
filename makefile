final: gofish.o player.o deck.o card.o
	g++ -o gofish gofish.o player.o deck.o card.o
driver: gofish.cpp player.h deck.h card.h
	g++ -c gofish.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
