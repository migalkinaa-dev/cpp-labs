CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g -fsanitize=address -fno-omit-frame-pointer
TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)