
include ../../make/make.local

SOURCE_FILES = SATData.cc 
OBJECT_FILES = SATData.o
HEADER_FILES = SATData.hh  

nSAT: $(OBJECT_FILES)
	g++ $(OBJECT_FILES) $(LINKOPTS) -o nSAT

SATData.o: SATData.cc SATData.hh
	g++ -c $(COMPOPTS) SATData.cc

SATBasics.o: SATBasics.cc SATBasics.hh SATData.hh
	g++ -c $(COMPOPTS) SATBasics.cc

SATHelpers.o: SATHelpers.cc SATHelpers.hh SATBasics.hh SATData.hh
	g++ -c $(COMPOPTS) SATHelpers.cc

SATMain.o: SATMain.cc SATHelpers.hh SATBasics.hh SATData.hh
	g++ -c $(COMPOPTS) SATMain.cc

clean:
	rm -f $(OBJECT_FILES) nSAT

