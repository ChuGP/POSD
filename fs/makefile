BIN=bin
OBJ=obj
.PHONY: clean $(BIN) $(OBJ)

all: clean dirs $(BIN)/hw8

$(BIN)/hw8: src/tree_test.cpp src/tree_test.h src/tree_frame.h | $(BIN)
	g++ $< `wx-config --libs` `wx-config --cxxflags` -o $@

dirs:
	mkdir -p $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)
run:		
		$(BIN)/hw8
