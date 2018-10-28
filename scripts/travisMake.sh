
cd /home/travis/build/Eiwanger/ESP/ESP/Code_4_linked_list
g++ -isystem -std=c++11 ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
ar -rv libgtest.a gtest-all.o



#g++ -c -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} Gtest_main.c 

#g++ -c -std=c++11 -isystem ${GTEST_DIR}/include -I ${GTEST_DIR} linked_list_test_case.c linked_list.h -o linked_list_test_case.o
#g++ -Wall -c -std=c++11 -g linked_list.c linked_list.h -o linked_list_test.o
#g++ -I ${GTEST_DIR}/include -pthread -std=c++11 linked_list_test_case.o Gtest_main.o libgtest.a linked_list_test.o -g -o unit_test 

g++ -isystem ${GTEST_DIR}/include -pthread -std=c++11 linked_list_test_case.c linked_list.c linked_list.h Gtest_main.c libgtest.a -o unit_test
