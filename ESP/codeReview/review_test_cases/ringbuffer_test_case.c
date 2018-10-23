#include <gtest/gtest.h>
#include "ringbuffer.h"


TEST(ErrorCategory, ErrTEst)
{
unsigned char recive_buffer[MAX_BUFFER];
struct buffer_type z;

empty_buffer(&z);

EXPECT_EQ(0, empty_buffer(&z));
EXPECT_EQ(0, empty_buffer(&z));
EXPECT_EQ(0, empty_buffer(&z));
}


TEST(Category, Test1)
{
    unsigned char rx_buffer[1024];
    struct buffer_type r;


    init_buffer(&r,rx_buffer);

    EXPECT_EQ(r.head,rx_buffer);
    EXPECT_EQ(r.tail,rx_buffer);
    EXPECT_EQ(r.buffer,rx_buffer);
}

TEST(Category, Test2)
{

	unsigned char recive_buffer[MAX_BUFFER];
	struct buffer_type b;
	error_type err;
	b.head=&recive_buffer[5];
	b.tail=&recive_buffer[3];
	b.buffer=&recive_buffer[0];
	EXPECT_EQ(2,get_buffer_state(&b,&err));
	//EXPECT_EQ(0,err);
}

TEST(Category, Test3)
{
	unsigned char recive_buffer[MAX_BUFFER];
	unsigned char c='a';
	struct buffer_type b;
	error_type err;
	b.head=&recive_buffer[5];
	b.tail=&recive_buffer[5];
	b.buffer=&recive_buffer[0];
	EXPECT_EQ(1, add_char_to_buffer(&b,c,&err));	
}

TEST(Category, Test4)
{
	unsigned char recive_buffer[MAX_BUFFER];
	
	unsigned char c='a';
	recive_buffer[3]=c;
	struct buffer_type b;
	error_type err;
	b.head=&recive_buffer[5];
	b.tail=&recive_buffer[3];
	b.buffer=&recive_buffer[0];
	EXPECT_EQ('a', get_char_from_buffer(&b,&err));	
}

TEST(Category, Test5)
{
	unsigned char recive_buffer[MAX_BUFFER]="jesjesjes";
	struct buffer_type b;
	error_type err;
	b.head=&recive_buffer[6];
	b.tail=&recive_buffer[3];
	b.buffer=&recive_buffer[0];
	EXPECT_EQ(3, print_buffer(b,&err));
	EXPECT_EQ('j', recive_buffer[3]);	
	EXPECT_EQ('e', recive_buffer[4]);	
	EXPECT_EQ('s', recive_buffer[5]);	
}
