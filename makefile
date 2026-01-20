CXX = g++
CXXFLAGS = -std=c++20 -Iinclude -Wall -Wextra -O2

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
MAIN = main.cpp
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJ) $(MAIN)
	$(CXX) $(CXXFLAGS) $(OBJ) $(MAIN) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
