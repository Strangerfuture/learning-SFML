# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Isrc

# SFML libraries
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Source and output
SRC = flappybird.cpp
OUT = flappybird


all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

run:
	./$(OUT)	


clean:
	rm -f $(OUT)


