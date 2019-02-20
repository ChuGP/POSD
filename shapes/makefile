.PHONY: clean run
all: clean hw3 run
hw3:  src/main.cpp src/circle.h src/triangle.h src/rectangle.h src/sort.h src/shape.h src/tool.h src/storage.h
		g++ -std=c++11 src/main.cpp -o bin/hw3  -lgtest -pthread

clean:
		rm -f bin/hw3
run:
		bin/hw3
