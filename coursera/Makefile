# compiler
CC	:=g++
# C++ compile flags
CXXFLAGS:=--std=c++14
# build directory
BUILD_DIR:=build

all: $(BUILD_DIR)
	$(CC) $(CXXFLAGS) -o $(BUILD_DIR)/w1E1_convertToC++ w1E1_convertToC++.cc

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm $(BUILD_DIR)/*
