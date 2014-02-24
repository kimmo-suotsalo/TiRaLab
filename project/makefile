objects := \
./src/sourceFiles/Application.o \
./src/sourceFiles/FileOperator.o \
./src/sourceFiles/Heap.o \
./src/sourceFiles/Main.o \
./src/sourceFiles/Searcher.o \
./test/sourceFiles/FileOperatorTest.o \
./test/sourceFiles/HeapTest.o \
./test/sourceFiles/SearcherTest.o \
./test/sourceFiles/Test.o 
  
all: $(objects)
	g++ -L../src/headerFiles -L../test/headerFiles -o "runApplication" $(objects)
