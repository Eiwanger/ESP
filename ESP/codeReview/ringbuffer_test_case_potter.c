#include <gtest/gtest.h>
#include "ringbuffer.h"
#include "stdio.h"

#define MAX_BUFFER 6
/*enum error_type {
	OK, BUFFER_OVER_FLOW, EMPTY_BUFFER, POINTER_ERROR, BUFFER_FULL
};

unsigned char recive_buffer[MAX_BUFFER];

struct buffer_type {
	unsigned char *head;
	unsigned char *tail;
	unsigned char *buffer;
};
*/
//exercise init
TEST( InitCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";

	struct buffer_type b;
	init_buffer(&b, buffer);

	EXPECT_EQ(b.buffer, buffer);
	EXPECT_EQ(b.head, buffer);
	EXPECT_EQ(b.tail, buffer);
}

//test empty_buffer function

TEST( EmptyCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	init_buffer(&b, buffer);
	b.head = (b.head + 3);
	EXPECT_EQ(empty_buffer(&b), 0);

	EXPECT_EQ(b.tail, b.head);
}

//test get_buffer_state function

TEST( SizeCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	init_buffer(&b, buffer);
	b.head = (b.tail + 3);
	EXPECT_EQ(get_buffer_state(&b), 3);
}

TEST( SizeCatogory, MyTest2) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	init_buffer(&b, buffer);
	b.head = (b.buffer + 1);
	b.tail = (b.buffer + 2);
	EXPECT_EQ(get_buffer_state(&b), 5);
}

TEST( SizeCatogory, MyTest3) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	init_buffer(&b, buffer);
	EXPECT_EQ(get_buffer_state(&b), 0);
}

//test add_char_to_buffer function

TEST( AddCharCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	unsigned char a = 'A';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 0);
	a = 'B';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 1);
	EXPECT_EQ(get_buffer_state(&b), 2);
	EXPECT_EQ(buffer[0], 'A');
	EXPECT_EQ(buffer[1], 'B');
	EXPECT_EQ(err, 0);
}

TEST( AddCharCatogory, MyTest2) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	unsigned char a = 'A';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 0);
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 1);
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 2);
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 3);
	a = 'D';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 4);
	a = 'F';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 5);
	EXPECT_EQ(get_buffer_state(&b), 6);
	EXPECT_EQ(buffer[0], 'A');
	EXPECT_EQ(buffer[4], 'D');
	EXPECT_EQ(buffer[5], 'F');
	EXPECT_EQ(err, 4);
}

TEST( AddCharCatogory, MyTest3) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	unsigned char a = 'A';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 0);
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 1);
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 2);
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 3);
	a = 'D';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 4);
	a = 'F';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 5);
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), -1);
	EXPECT_EQ(get_buffer_state(&b), 6);
	EXPECT_EQ(buffer[0], 'A');
	EXPECT_EQ(buffer[4], 'D');
	EXPECT_EQ(buffer[5], 'F');
	EXPECT_EQ(err, 1);
}

//test get_char_from_buffer function

TEST( getCharCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	unsigned char a = 'A';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 0);
	a = 'B';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 1);
	EXPECT_EQ(get_buffer_state(&b), 2);
	EXPECT_EQ(get_char_from_buffer(&b, &err), 'A');
	EXPECT_EQ(err, 0);
}

TEST( getCharCatogory, MyTest2) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	unsigned char a = 'A';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 0);
	a = 'B';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 1);
	EXPECT_EQ(get_buffer_state(&b), 2);
	EXPECT_EQ(get_char_from_buffer(&b, &err), 'A');
	EXPECT_EQ(get_char_from_buffer(&b, &err), 'B');
	EXPECT_EQ(err, 2);
}

TEST( getCharCatogory, MyTest3) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	EXPECT_EQ(get_buffer_state(&b), 0);
	EXPECT_EQ(get_char_from_buffer(&b, &err), -1);
	EXPECT_EQ(err, 2);
}

//test print_buffer function

TEST( printBufferCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	unsigned char a = 'A';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 0);
	a = 'B';
	EXPECT_EQ(add_char_to_buffer(&b, a, &err), 1);
	EXPECT_EQ(get_buffer_state(&b), 2);
	EXPECT_EQ(print_buffer(b, &err), 2);
	EXPECT_EQ(err, 0);
}

TEST( printBufferCatogory, MyTest2) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	init_buffer(&b, buffer);
	EXPECT_EQ(get_buffer_state(&b), 0);
	EXPECT_EQ(print_buffer(b, &err), -1);
	EXPECT_EQ(err, 2);
}

//test add_string_to_buffer function

TEST( addStringCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	unsigned char s[] = "HELLO";
	init_buffer(&b, buffer);
	EXPECT_EQ(add_string_to_buffer(&b, s, &err), 5);
	EXPECT_EQ(get_buffer_state(&b), 5);
	EXPECT_EQ(get_char_from_buffer(&b, &err), 'H');
	EXPECT_EQ(get_char_from_buffer(&b, &err), 'E');
	EXPECT_EQ(buffer[2], 'L');
	EXPECT_EQ(buffer[3], 'L');
	EXPECT_EQ(buffer[4], 'O');
	EXPECT_EQ(err, 0);
}

TEST( addStringCatogory, MyTest2) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	unsigned char s[] = "HELLOW";
	init_buffer(&b, buffer);
	EXPECT_EQ(add_string_to_buffer(&b, s, &err), 6);
	EXPECT_EQ(err, 4);
	EXPECT_EQ(get_buffer_state(&b), 6);
	EXPECT_EQ(get_char_from_buffer(&b, &err), 'H');
	EXPECT_EQ(buffer[3], 'L');
	EXPECT_EQ(buffer[5], 'W');
}

TEST( addStringCatogory, MyTest3) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	unsigned char s[] = "HELLOWORLD";
	init_buffer(&b, buffer);
	EXPECT_EQ(add_string_to_buffer(&b, s, &err), -1);
	EXPECT_EQ(err, 1);
	EXPECT_EQ(get_buffer_state(&b), 0);
}

//test get_string_from_buffer function

TEST( getStringCatogory, MyTest1) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	unsigned char s[] = "HELLO";
	int length = 4;
	unsigned char r[(length + 1)];
	init_buffer(&b, buffer);
	EXPECT_EQ(add_string_to_buffer(&b, s, &err), 5);
	EXPECT_EQ(get_buffer_state(&b), 5);
	EXPECT_EQ(get_string_from_buffer(&b, r, length, &err), 4);
	EXPECT_STREQ((const char*) r, "HELL");
	EXPECT_EQ(err, 0);
}

TEST( getStringCatogory, MyTest2) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	unsigned char s[] = "HELLO";
	int length = 7;
	unsigned char r[(length + 1)];
	init_buffer(&b, buffer);
	EXPECT_EQ(add_string_to_buffer(&b, s, &err), 5);
	EXPECT_EQ(get_buffer_state(&b), 5);
	EXPECT_EQ(get_string_from_buffer(&b, r, length, &err), -1);
	EXPECT_STREQ((const char*) r, "");
	EXPECT_EQ(err, 3);
}

TEST( getStringCatogory, MyTest3) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	int length = 3;
	unsigned char r[(length + 1)];
	init_buffer(&b, buffer);
	EXPECT_EQ(get_buffer_state(&b), 0);
	EXPECT_EQ(get_string_from_buffer(&b, r, length, &err), -1);
	EXPECT_STREQ((char*) r, "");
	EXPECT_EQ(err, 2);
}

TEST( getStringCatogory, MyTest4) {
	unsigned char buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err = OK;
	unsigned char s[] = "HELLO";
	int length = 5;
	unsigned char r[(length + 1)];
	init_buffer(&b, buffer);
	EXPECT_EQ(add_string_to_buffer(&b, s, &err), 5);
	EXPECT_EQ(get_buffer_state(&b), 5);
	EXPECT_EQ(get_string_from_buffer(&b, r, length, &err), 5);
	EXPECT_STREQ((const char*) r, "HELLO");
	EXPECT_EQ(err, 2);
}
