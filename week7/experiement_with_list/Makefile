CC := g++
CXXFLAGS:= -Wall -g -std=c++11
INC := -I./include

bin/main: src/main.cpp src/ArrayList.cpp src/NodeList.cpp
	@mkdir -p bin/
	${CC} ${CXXFLAGS} ${INC} $< -o $@

clean:
	@echo "Clean..."
	rm -rf build/ bin/
