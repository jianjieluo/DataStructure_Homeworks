CC := g++

CXXFLAGS :=-Wall -g -std=c++11
LIN :=-lm

all : magic_square leipishu

magic_square : magic_square.cpp
	$(CC) $(CXXFLAGS) $< -o $@ $(LIN)

leipishu : 雷劈数.cpp
	$(CC) $(CXXFLAGS) $< -o $@ $(LIN)

clean :
	rm -f magic_square
	rm -f leipishu
