G++ := g++
USR_HOME := $(HOME)
BOOST_ROOT := $(USR_HOME)/boost
BOOST_INCL := $(BOOST_ROOT)/include
BOOST_LIB := $(BOOST_ROOT)/lib
BUILD_DIR := $(HOME)/code/sm/builds

all: helloworld stopwatch

helloworld:
	$(G++) --std=c++11 helloworld.cc -o $(BUILD_DIR)/helloworld -I $(BOOST_INCL) -L $(BOOST_LIB)

stopwatch:
	$(G++) --std=c++11 stopwatch.cc -o $(BUILD_DIR)/stopwatch -I $(BOOST_INCL) -L $(BOOST_LIB)

clean:
	rm -rf $(BUILD_DIR)/*
