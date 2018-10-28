
cd /home/travis/build/Eiwanger/ESP/ESP/Code_4_linked_list
g++ -c -isystem ${GTEST_DIR}/include -I ${GTEST_DIR} Gtest_main.c 
g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/home/travis/build    /Eiwanger/src/gtest-all.cc
ar -rv libgtest.a gtest-all.o

g++ -c -isystem ${GTEST_DIR}/include -I ${GTEST_DIR} linked_list_test_case.c -o linked_list    _test_case.o
g++ -Wall -c -g linked_list.c -o linked_list_test.o
g++ -I ${GTEST_DIR}/include -pthread linked_list_test_case.o Gtest_main.o libgtest.a linked    _list_test.o -g -o unit_test 

