CC	:=g++
# C++ compile flags
CXXFLAGS:=--std=c++14
BUILDDIR:=build
TESTDIR:=test

all: $(BUILD_DIR)
	$(CC) $(CXXFLAGS) -o $(BUILDDIR)/w1E1_convertToC++ w1E1_convertToC++.cc

tests:
	$(MAKE) -C $(TESTDIR) all

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm $(BUILDDIR)/*
	$(MAKE) -C $(TESTDIR) $@
