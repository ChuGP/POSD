.PHONY:clean run 
all:clean midterm2 run
midterm2: test/* src/*
		g++ -std=c++11 test/ut_midterm2.cpp -o bin/midterm2 -lgtest  -pthread
clean:
		rm -rf bin/* 
run:		
		bin/midterm2