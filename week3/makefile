
CXXFLAGS := -Wall -g -std=c++11
INC := -I./include

bin/main : build/main.o build/stack.o build/queue.o
	@mkdir -p bin
	g++ $(CXXFLAGS) $(INC) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p build
	g++ $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -rf bin/ build/
