#include "ringbuffer.h"
#include <gtest/gtest.h>
#include <stdlib.h>

unsigned char buff[MAX_BUFFER];

struct buffer_type b;

TEST(init_buffer_test, test_OK)
{
	init_buffer(&b, buff);
	EXPECT_EQ(b.head, buff);
	EXPECT_EQ(b.tail, buff);
	EXPECT_EQ(b.buffer, buff);	
}

TEST(empty_buffer_test, test_empty_OK)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	EXPECT_EQ(0, empty_buffer(&b));
	ERROR_TYPE_t err = OK;
	EXPECT_EQ(err, empty_buffer(&b));
}

TEST(empty_buffer_test, test_changed_OK)
{		b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	b.head += 3;
	b.tail += 1;
	EXPECT_EQ(0, empty_buffer(&b));
}

TEST(get_buffer_state_test, test_empty)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	EXPECT_EQ(0, get_buffer_state(&b));
}

TEST(get_buffer_state_test, test_number_2)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=3;
	b.tail +=1;	
	EXPECT_EQ(2, get_buffer_state(&b));
}

TEST(get_buffer_state_test, test_border_top)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=4;
	b.tail +=1;	
	EXPECT_EQ(3, get_buffer_state(&b));
}

TEST(get_buffer_state_test, test_out_of_bounds_head)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=5;
	b.tail +=1;	
	EXPECT_EQ(-1, get_buffer_state(&b));

}

TEST(get_buffer_state_test, test_out_of_bounds_tail)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=1;
	b.tail +=5;	
	EXPECT_EQ(-1, get_buffer_state(&b));

}

TEST(get_buffer_state_test, test_out_of_bounds_negativ)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=1;
	b.tail +=-1;	
	EXPECT_EQ(-1, get_buffer_state(&b));

}

TEST(get_buffer_state_test, test_borders)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=4;
	b.tail +=4;	
	EXPECT_EQ(0, get_buffer_state(&b));

}

TEST(add_char_to_buffer_test, test_default_count)
{	
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	unsigned char getAdded = 'a';
	int count = add_char_to_buffer(&b, getAdded, &err);	
	EXPECT_EQ(1, count);
	EXPECT_EQ(res, err);
}

TEST(add_char_to_buffer_test, test_default_char)
{	
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	unsigned char getAdded = 'a';
	add_char_to_buffer(&b, getAdded, &err);	

	char result = *(b.head-1);
	EXPECT_EQ((int)getAdded,(int)result);
	EXPECT_EQ(res, err);
}

TEST(add_char_to_buffer_test, test_buffer_full)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = BUFFER_FULL;
	b.head += 2;
	b.tail += 4;
	unsigned char getAdded = 'a';
	add_char_to_buffer(&b, getAdded, &err);	

	EXPECT_EQ(res, err);	

}

TEST(add_char_to_buffer_test, test_error_buffer_full)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err = BUFFER_FULL;
	ERROR_TYPE_t res = BUFFER_FULL;
	unsigned char getAdded = 'a';
	int count = add_char_to_buffer(&b, getAdded, &err);	
	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);	

}

TEST(add_char_to_buffer_test, test_set_buffer_full)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = BUFFER_FULL;
	b.head+=1;
	b.tail+=2;
	unsigned char getAdded = 'a';
	int count = add_char_to_buffer(&b, getAdded, &err);	
	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);	

}

TEST(add_char_to_buffer_test, test_pointer_error)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = POINTER_ERROR;
	b.head+=6;
	b.tail+=2;
	unsigned char getAdded = 'a';
	int count = add_char_to_buffer(&b, getAdded, &err);	
	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);	

}

TEST(add_char_to_bufferTest, actbTest1) {
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t eT;
	int retVal = add_char_to_buffer(&b, 'a',  &eT);
	char  expChar[2];
	expChar[1] = '\0';	
	expChar[0] = (char)*(b.head-1);
	EXPECT_STREQ("a", expChar);
	EXPECT_EQ(1, retVal);
	ERROR_TYPE_t eTComp = OK;
	EXPECT_EQ(eTComp, eT);
}

TEST(add_char_to_bufferTest, actbTest2) {
	b.head = buff+3;
	b.tail = buff+1;
	b.buffer = buff;
	ERROR_TYPE_t eT;
	int retVal = add_char_to_buffer(&b, 'b',  &eT);
	char  expChar[2];
	expChar[1] = '\0';	
	expChar[0] = (char)*(b.head-1);
	EXPECT_STREQ("b", expChar);
	EXPECT_EQ(3, retVal);
	ERROR_TYPE_t eTComp = OK;
	EXPECT_EQ(eTComp, eT);
}

TEST(add_char_to_bufferTest, actbTest3) {
	b.head = buff+4;
	*(b.head-1) = 'u';
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t eT;
	int retVal = add_char_to_buffer(&b, 'c',  &eT);
	char  expChar[2];
	expChar[1] = '\0';	
	expChar[0] = (char)*(b.head-1);
	EXPECT_STREQ("u", expChar);
	EXPECT_EQ(-1, retVal);
	ERROR_TYPE_t eTComp = BUFFER_FULL;
	EXPECT_EQ(eTComp, eT);
}

TEST(add_char_to_bufferTest, actbTest4) {
	b.head = buff+3;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t eT;
	int retVal = add_char_to_buffer(&b, 'd',  &eT);
	char  expChar[2];
	expChar[1] = '\0';	
	expChar[0] = (char)*(b.head-1);
	EXPECT_STREQ("d", expChar);
	EXPECT_EQ(4, retVal);
	ERROR_TYPE_t eTComp = BUFFER_FULL;
	EXPECT_EQ(eTComp, eT);
}

TEST(add_char_to_bufferTest, actbTest5) {
	b.head = buff;
	b.tail = buff+2;
	b.buffer = buff;
	ERROR_TYPE_t eT;
	int retVal = add_char_to_buffer(&b, 'e',  &eT);
	char  expChar[2];
	expChar[1] = '\0';	
	expChar[0] = (char)*(b.head-1);
	EXPECT_STREQ("e", expChar);
	EXPECT_EQ(4, retVal);
	ERROR_TYPE_t eTComp = BUFFER_FULL;
	EXPECT_EQ(eTComp, eT);
}



TEST(get_char_from_buffer_test, test_default)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;

	unsigned char getAdded = 'a';
	add_char_to_buffer(&b, getAdded, &err);
	add_char_to_buffer(&b, getAdded, &err);	
	unsigned char result = get_char_from_buffer(&b, &err);
	EXPECT_EQ((int)result, (int)getAdded);
	EXPECT_EQ(res, err);
}

TEST(get_char_from_buffer_test, test_default_mid)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	b.head += 3;
	b.tail += 3;

	unsigned char getAdded = 'b';
	add_char_to_buffer(&b, getAdded, &err);	
	unsigned char result = get_char_from_buffer(&b, &err);
	EXPECT_EQ((int)result, (int)getAdded);

}

TEST(get_char_from_buffer_test, test_error_buffer_empty)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err = OK;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	unsigned char tmp = get_char_from_buffer(&b, &err);
	// change 7 to 255 or a different value 
	EXPECT_EQ(7, (int)tmp);
	EXPECT_EQ(res, err); 

}

TEST(get_char_from_buffer_test, test_error_buffer_empty_2)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=1;
	b.tail +=1;
	ERROR_TYPE_t err = OK;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	unsigned char a = 'a';
	add_char_to_buffer(&b, a, &err);
	unsigned char tmp = get_char_from_buffer(&b, &err);
	// change 7 to 255 or a different value 
	EXPECT_EQ((int)a, (int)tmp);
	EXPECT_EQ(res, err); 
}

TEST(get_char_from_buffer_test, test_error_buffer_empty_3)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=4;
	b.tail +=4;
	ERROR_TYPE_t err = OK;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	unsigned char a = 'a';
	add_char_to_buffer(&b, a, &err);
	unsigned char tmp = get_char_from_buffer(&b, &err);
	// change 7 to 255 or a different value 
	EXPECT_EQ((int) a, (int)tmp);
	EXPECT_EQ(res, err); 
}

TEST(get_char_from_buffer_test, test_error_pointer_error)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.head +=10;
	ERROR_TYPE_t err = OK;
	ERROR_TYPE_t res = POINTER_ERROR;
	unsigned char tmp = get_char_from_buffer(&b, &err);
	// change 7 to 255 or a different value 
	EXPECT_EQ(7, (int)tmp);
	EXPECT_EQ(res, err); 

}


TEST(print_buffer_test, test_default)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;

	add_char_to_buffer(&b, 'H', &err);	
	add_char_to_buffer(&b, 'i', &err);	

	EXPECT_EQ(2, print_buffer(&b, &err));
	EXPECT_EQ(res, err);

}

TEST(print_buffer_test, test_border)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;

	add_char_to_buffer(&b, 'H', &err);	
	add_char_to_buffer(&b, 'e', &err);	
	add_char_to_buffer(&b, 'l', &err);	
	add_char_to_buffer(&b, 'l', &err);	

	EXPECT_EQ(4, print_buffer(&b, &err));
	EXPECT_EQ(res, err);

}

TEST(print_buffer_test, test_is_buffer_empty)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = EMPTY_BUFFER;

	EXPECT_EQ(-1, print_buffer(&b, &err));
	EXPECT_EQ(res, err);

}

TEST(print_buffer_test, test_set_buffer_empty)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err = EMPTY_BUFFER;
	ERROR_TYPE_t res = EMPTY_BUFFER;

	EXPECT_EQ(-1, print_buffer(&b, &err));
	EXPECT_EQ(res, err);

}

TEST(add_string_to_buffer_test, test_OK)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	unsigned char test[] = "tes";
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int count = add_string_to_buffer(&b, test, &err);
	EXPECT_EQ(3, count);
	EXPECT_EQ(res, err);
}

TEST(add_string_to_buffer_test, test_buffer_full)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	unsigned char test[] = "test";
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = BUFFER_FULL;
	int count = add_string_to_buffer(&b, test, &err);
	EXPECT_EQ(4, count);
	EXPECT_EQ(res, err);
}

TEST(add_string_to_buffer_test, test_buffer_overflow)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	unsigned char test [] = "this test will crash the buffer";
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = BUFFER_OVER_FLOW;
	int count = add_string_to_buffer(&b, test, &err);

	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);
}

TEST(add_string_to_buffer_test, test_add_over_border)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	unsigned char test [] = "hex";
	b.head += 3;
	b.tail += 3;
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int count = add_string_to_buffer(&b, test, &err);

	EXPECT_EQ(3, count);
	EXPECT_EQ(res, err);
}

TEST(get_string_from_buffer_test, test_read_default_3)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int len = 3;
	add_char_to_buffer(&b, 'H', &err);	
	add_char_to_buffer(&b, 'e', &err);	
	add_char_to_buffer(&b, 'y', &err);
	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
}

TEST(get_string_from_buffer_test, test_read_border)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int len = 4;
	add_char_to_buffer(&b, 'H', &err);	
	add_char_to_buffer(&b, 'e', &err);	
	add_char_to_buffer(&b, 'l', &err);
	add_char_to_buffer(&b, 'l', &err);
	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
}

TEST(get_string_from_buffer_test, test_read_over_border)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.tail += 3;
	b.head += 4;

	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int len = 4;
	add_char_to_buffer(&b, 'H', &err);	
	add_char_to_buffer(&b, 'e', &err);	
	add_char_to_buffer(&b, 'l', &err);
	add_char_to_buffer(&b, 'l', &err);
	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
}

TEST(get_string_from_buffer_test, test_pointer_error)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.tail += 6;
	b.head += 4;

	ERROR_TYPE_t err;
	ERROR_TYPE_t res = POINTER_ERROR;
	int len = 4;
	add_char_to_buffer(&b, 'H', &err);	
	add_char_to_buffer(&b, 'e', &err);	
	add_char_to_buffer(&b, 'l', &err);
	add_char_to_buffer(&b, 'l', &err);
	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
}

TEST(get_string_from_buffer_test, test_empty_buffer)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	ERROR_TYPE_t err;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	int len = 4;
	add_char_to_buffer(&b, 'H', &err);	
	add_char_to_buffer(&b, 'e', &err);	
	add_char_to_buffer(&b, 'l', &err);
	add_char_to_buffer(&b, 'l', &err);
	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
}

