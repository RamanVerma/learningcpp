GCC         := g++
GCC_OPT	    := -g --std=c++17
BOOST_HOME  := $(HOME)/code/boost/build
BOOST_INCL  := $(BOOST_HOME)/include
BOOST_LIB   := $(BOOST_HOME)/lib
CCFILES     := $(wildcard *.cc)
BINS        := $(CCFILES:.cc=.t)

.PHONY: all
all: $(BINS)

%.t: %.cc
	$(GCC) $(GCC_OPT) $< -o $@ -I $(BOOST_INCL) -L $(BOOST_LIB)

clean:
	rm *.t
