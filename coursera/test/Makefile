CC        := g++
SRCDIR    := $(shell dirname `pwd`)
CXXFLAGS  := -g
INCDIR    := -I $(SRCDIR)
LIBS      :=
TSTFILES  := $(wildcard *.cc)
TSTBINS   := $(TSTFILES:%.cc=%.t)

all: $(TSTBINS)

$(TSTBINS): $(TSTFILES)
	@$(CC) $(CXXFLAGS) $(TSTFILES) -o $(TSTBINS) $(INCDIR) $(LIBS)

clean:
	rm $(TSTBINS)
