# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Target executable
TARGET = database

# Source and object files
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
OBJECTS = main.o Database.o FileManager.o IndexManager.o

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

# Compile individual object files
main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Database.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp

Database.o: $(SRC_DIR)/Database.cpp $(INCLUDE_DIR)/Database.h $(INCLUDE_DIR)/FileManager.h $(INCLUDE_DIR)/IndexManager.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Database.cpp

FileManager.o: $(SRC_DIR)/FileManager.cpp $(INCLUDE_DIR)/FileManager.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/FileManager.cpp

IndexManager.o: $(SRC_DIR)/IndexManager.cpp $(INCLUDE_DIR)/IndexManager.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IndexManager.cpp

# Clean generated files
clean:
	rm -f *.o $(TARGET)
