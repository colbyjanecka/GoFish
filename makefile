final: go_fish.o player.o deck.o card.o
	g++ -o go_fish gofish.o player.o deck.o card.o
driver: go_fish.cpp player.h deck.h card.h
	g++ -c go_fish.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
