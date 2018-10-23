#include <gtest/gtest.h>
#include "ringbuffer.h"

//Initalize Buffer
TEST(InitBuffer,NormalTest)
{
	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	init_buffer(&b,recive_buffer);
	EXPECT_EQ(b.head, recive_buffer);
	EXPECT_EQ(b.tail, recive_buffer);
	EXPECT_EQ(b.buffer, recive_buffer);
}

//Empty Buffer
TEST(EmptyBuffer,NormalTest)
{
	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	empty_buffer(&b);
	EXPECT_EQ(0, empty_buffer(&b));
	EXPECT_EQ(0, empty_buffer(&b));
	EXPECT_EQ(0, empty_buffer(&b));
}

//Buffer State
TEST(BufferState,NormalTest)
{
	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[5];
	b.tail = &recive_buffer[3];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(2, get_buffer_state(&b, &err));
	EXPECT_EQ(0, err);
}
TEST(BufferState,ErrorTest)
{
	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[5];
	b.tail = &recive_buffer[5];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(-1, get_buffer_state(&b, &err));
	EXPECT_EQ(2, err);
}

//Add Character to Buffer
TEST(AddCharToBuffer,NormalTest1)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char c = 'x';
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[5];
	b.tail = &recive_buffer[5];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(1, add_char_to_buffer(&b, c, &err));
	EXPECT_EQ('x', recive_buffer[5]);
	EXPECT_EQ(0, err);
}
TEST(AddCharToBuffer,NormalTest2)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char c = '1';
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[0];
	b.tail = &recive_buffer[0];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(1, add_char_to_buffer(&b, c, &err));
	EXPECT_EQ('1', recive_buffer[0]);
	EXPECT_EQ(0, err);
}
TEST(AddCharToBuffer,NormalTest3)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char c = 'R';
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[6];
	b.tail = &recive_buffer[5];
	b.buffer = &recive_buffer[5];
	EXPECT_EQ(2, add_char_to_buffer(&b, c, &err));
	EXPECT_EQ('R', recive_buffer[6]);
	EXPECT_EQ(0, err);
}
TEST(AddCharToBuffer,ErrorTest1)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char c;
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[5];
	b.tail = &recive_buffer[5];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(-1, add_char_to_buffer(&b, c, &err));
	EXPECT_EQ(2, err);
}
TEST(AddCharToBuffer,ErrorTest2)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char c = 'R';
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[4];
	b.tail = &recive_buffer[6];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(-1, add_char_to_buffer(&b, c, &err));
	EXPECT_EQ(3, err);
}

//Get Character from Buffer
TEST(GetCharFromBuffer,NormalTest1)
{
	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[5];
	b.tail = &recive_buffer[5];
	b.buffer = &recive_buffer[0];
	recive_buffer[5] = 'x';
	EXPECT_EQ('x', get_char_from_buffer(&b, &err));
	EXPECT_EQ(0, err);
}
TEST(GetCharFromBuffer,NormalTest2)
{
	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[0];
	b.tail = &recive_buffer[0];
	b.buffer = &recive_buffer[0];
	recive_buffer[0] = '1';
	EXPECT_EQ('1', get_char_from_buffer(&b, &err));
	EXPECT_EQ(0, err);
}

//Print Buffer
TEST(PrintBuffer,NormalTest1)
{
	unsigned char recive_buffer[MAX_BUFFER] = "abcdReneabcdefg";
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[8];
	b.tail = &recive_buffer[4];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(4, print_buffer(b, &err));
	EXPECT_EQ('R', recive_buffer[4]);
	EXPECT_EQ('e', recive_buffer[5]);
	EXPECT_EQ('n', recive_buffer[6]);
	EXPECT_EQ('e', recive_buffer[7]);
	EXPECT_EQ(&recive_buffer[8], b.head);
	EXPECT_EQ(0, err);
}
TEST(PrintBuffer,NormalTest2)
{
	unsigned char recive_buffer[MAX_BUFFER] = "ReneMikhael";
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[11];
	b.tail = &recive_buffer[4];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(7, print_buffer(b, &err));
	EXPECT_EQ('M', recive_buffer[4]);
	EXPECT_EQ('i', recive_buffer[5]);
	EXPECT_EQ('k', recive_buffer[6]);
	EXPECT_EQ('h', recive_buffer[7]);
	EXPECT_EQ('a', recive_buffer[8]);
	EXPECT_EQ('e', recive_buffer[9]);
	EXPECT_EQ('l', recive_buffer[10]);
	EXPECT_EQ(&recive_buffer[11], b.head);
	EXPECT_EQ(0, err);
}
TEST(PrintBuffer,ErrorTest1)
{
	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[0];
	b.tail = &recive_buffer[0];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(-1, print_buffer(b, &err));
	EXPECT_EQ(&recive_buffer[0], b.head);
	EXPECT_EQ(2, err);
}
TEST(PrintBuffer,ErrorTest2)
{
	unsigned char recive_buffer[MAX_BUFFER] = "ReneMikhael";
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[4];
	b.tail = &recive_buffer[11];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(-1, print_buffer(b, &err));
	EXPECT_EQ(&recive_buffer[4], b.head);
	EXPECT_EQ(3, err);
}

//Add String to Buffer
TEST(AddStringToBuffer,NormalTest)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char s[] = "ReneEiOsaa";
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[0];
	b.tail = &recive_buffer[0];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(10, add_string_to_buffer(&b, s, &err));
	EXPECT_EQ('R', recive_buffer[0]);
	EXPECT_EQ('e', recive_buffer[1]);
	EXPECT_EQ('n', recive_buffer[2]);
	EXPECT_EQ('e', recive_buffer[3]);
	EXPECT_EQ(&recive_buffer[10], b.head);
	EXPECT_EQ(0, err);
}
TEST(AddStringToBuffer,ErrorTest)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char s[] = "";
	struct buffer_type b;
	error_type err;
	b.head = &recive_buffer[0];
	b.tail = &recive_buffer[0];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(0, add_string_to_buffer(&b, s, &err));
	EXPECT_EQ(&recive_buffer[0], b.head);
	EXPECT_EQ(3, err);
}

//Get String from Buffer
TEST(GetStringFromBuffer,NormalTest)
{
	unsigned char recive_buffer[MAX_BUFFER] = "ReneEiOsaa";
	struct buffer_type b;
	error_type err;
	unsigned char dest;
	int len = 10;
	b.head = &recive_buffer[0];
	b.tail = &recive_buffer[0];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(10, get_string_from_buffer(&b, &dest, len, &err));
	EXPECT_EQ('R', recive_buffer[0]);
	EXPECT_EQ('e', recive_buffer[1]);
	EXPECT_EQ('n', recive_buffer[2]);
	EXPECT_EQ('e', recive_buffer[3]);
	EXPECT_EQ(&recive_buffer[10], b.tail);
	EXPECT_EQ(0, err);
}

TEST(GetStringFromBuffer,ErrorTest)
{
	unsigned char recive_buffer[MAX_BUFFER] = "";
	struct buffer_type b;
	error_type err;
	unsigned char dest;
	int len = 0;
	b.head = &recive_buffer[0];
	b.tail = &recive_buffer[0];
	b.buffer = &recive_buffer[0];
	EXPECT_EQ(0, get_string_from_buffer(&b, &dest, len, &err));
	EXPECT_EQ(&recive_buffer[0], b.tail);
	EXPECT_EQ(2, err);
}