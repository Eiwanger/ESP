# make - to compile for normal run
# make test - to compile for unit testing
# make clean -  to clean up

# put here the names of your files

PROGRAM_NAME=linked_list
UNIT_TEST_NAME=$(PROGRAM_NAME)_test_case
HEADER_FILE_NAME=$(PROGRAM_NAME)
SHELL =/bin/sh

#Targetfolder
BIN_DIR =bin
MK_DIR =mkdir


# variable to find the test environment
GTEST_DIR =${HOME}/Studium/WS18_fin/prg_c/ESP/googletest/googletest

#Compiler
CC =gcc
CPP =g++


#Flags for the compiler to create .o files
CCFLAGS = -Wall -c -g
CPPFLAGS = -g

COPTS = -fprofile-arcs -ftest-coverage

# Flags for libs
LIBFLAGS=


# target is the result of the makefile.
# make alone will try to create the first target in the file
# Targets:

# make /make Programname
# release: $(PROGRAM_NAME).o main.o
#	$(CC) $(PROGRAM_NAME).o -o $(BIN_DIR)/$(PROGRAM_NAME) $(LIBFLAGS) 

# make test
test: Gtest_main.o libgtest.a $(UNIT_TEST_NAME).o $(PROGRAM_NAME)_test.o $(BIN_DIR)
	$(CPP) -I $(GTEST_DIR)/include -pthread $(UNIT_TEST_NAME).o Gtest_main.o libgtest.a $(PROGRAM_NAME)_test.o $(CPPFLAGS) -o $(BIN_DIR)/unit_test 
	./bin/unit_test
# make coverage test

coverage: Gtest_main.o libgtest.a $(UNIT_TEST_NAME)_coverage.o $(PROGRAM_NAME)_coverage.o $(BIN_DIR)
	$(CPP) $(COPTS) -I $(GTEST_DIR)/include -pthread $(UNIT_TEST_NAME)_coverage.o Gtest_main.o libgtest.a $(PROGRAM_NAME)_coverage.o -o $(BIN_DIR)/$(PROGRAM_NAME)_coverage 
	./coverageAnalysis



##Normal##
#still needs to be finished to compile a the file as an normal application

# $(PROGRAM_NAME).o: $(PROGRAM_NAME).c 
#	$(CC) $(CCFLAGS) $(PROGRAM_NAME).c

#only if the
#main.o: main.c
#	$(CC) $(CCFLAGS) main.c



#### Unit Test ####

Gtest_main.o: Gtest_main.c
	g++ -c -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) Gtest_main.c 

## Google Test Framework ##
libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

## own Unit test code
$(UNIT_TEST_NAME).o: $(UNIT_TEST_NAME).c $(HEADER_FILE_NAME).h
	$(CPP) -c -Wall -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) $(UNIT_TEST_NAME).c -o $(UNIT_TEST_NAME).o


$(PROGRAM_NAME)_test.o: $(PROGRAM_NAME).c 
	$(CPP) $(CCFLAGS) $(PROGRAM_NAME).c -o $(PROGRAM_NAME)_test.o



## coverage test
$(UNIT_TEST_NAME)_coverage.o: $(UNIT_TEST_NAME).c # $(HEADER_FILE_NAME).h
	$(CPP) -c -Wall -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) $(UNIT_TEST_NAME).c -o $(UNIT_TEST_NAME)_coverage.o


$(PROGRAM_NAME)_coverage.o: $(PROGRAM_NAME).c 
	$(CPP) $(COPTS) $(CCFLAGS) $(PROGRAM_NAME).c -o $(PROGRAM_NAME)_coverage.o




$(BIN_DIR):
	$(MK_DIR) $(BIN_DIR)

#### Clean ####
.PHONY: clean
clean:
	rm -f *.o
	rm -rf $(BIN_DIR)
	rm -f *.gcno
	rm -rf cov_output
	rm -f *.gcda
