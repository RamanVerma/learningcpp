CC	:=g++
# C++ compile flags
CXXFLAGS:=--std=c++14
BUILDDIR:=build
TESTDIR:=test

all: $(BUILD_DIR)
	$(CC) $(CXXFLAGS) -o $(BUILDDIR)/w1E1_convertToC++ w1E1_convertToC++.cc
	$(CC) $(CXXFLAGS) -o $(BUILDDIR)/w2E1_Dijkstra w2E1_Dijkstra.cc

tests:
	$(MAKE) -C $(TESTDIR) all

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(TESTDIR) $@
	rm $(BUILDDIR)/*
