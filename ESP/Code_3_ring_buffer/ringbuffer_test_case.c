// MAX_BUFFER declared in ringbuffer.h with 5
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

TEST(empty_buffer_test, test_OK)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	EXPECT_EQ(0, empty_buffer(&b));
	ERROR_TYPE_t err = OK;
	EXPECT_EQ(err, empty_buffer(&b));
	EXPECT_EQ(b.head, b.tail);
}

TEST(empty_buffer_test, test_changed_OK)
{	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	b.head += 3;
	b.tail += 1;
	EXPECT_EQ(0, empty_buffer(&b));
	EXPECT_EQ(b.head, b.tail);
}

TEST(get_buffer_state_test, test_empty)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t err;
	//init_buffer(&b, buff);
	EXPECT_EQ(0, get_buffer_state(&b, &err));
}

TEST(get_buffer_state_test, test_different_pos)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t err;
	//init_buffer(&b, buff);
	b.head +=3;
	b.tail +=1;	
	EXPECT_EQ(2, get_buffer_state(&b, &err));

	b.head = buff+1;
	b.tail = buff+3;
	EXPECT_EQ(3, get_buffer_state(&b, &err));

	b.head = buff + 4;
	b.tail = buff +1;
	EXPECT_EQ(3, get_buffer_state(&b, &err));


}

TEST(get_buffer_state_test, test_out_of_bounds_head)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t err;
	//init_buffer(&b, buff);
	b.head +=5;
	b.tail +=1;	
	EXPECT_EQ(-1, get_buffer_state(&b, &err));

}

TEST(get_buffer_state_test, test_out_of_bounds_tail)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t err;
	//init_buffer(&b, buff);
	b.head +=1;
	b.tail +=5;	
	EXPECT_EQ(-1, get_buffer_state(&b, &err));

}

TEST(get_buffer_state_test, test_out_of_bounds_tail_negativ)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t err;
	//init_buffer(&b, buff);
	b.head +=2;
	b.tail +=-1;	
	EXPECT_EQ(-1, get_buffer_state(&b, &err));

}

TEST(get_buffer_state_test, test_out_of_bounds_head_negativ)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	ERROR_TYPE_t err;
	//init_buffer(&b, buff);
	b.head +=-2;
	b.tail +=2;	
	EXPECT_EQ(-1, get_buffer_state(&b, &err));

}

TEST(add_char_to_buffer_test, test_default)
{	
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	unsigned char getAdded = 'a';
	int count = add_char_to_buffer(&b, getAdded, &err);	
	char result = *(b.head-1);
	EXPECT_EQ(1, count);
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

TEST(add_char_to_bufferTest, head_to_start_test) {
	b.head = buff+4;
	b.tail = buff+1;
	b.buffer = buff;
	ERROR_TYPE_t err;
	int count = add_char_to_buffer(&b, 'e',  &err);
	EXPECT_EQ((int)'e', (int)*(b.buffer+4));
	EXPECT_EQ(4, count);
	ERROR_TYPE_t res = BUFFER_FULL;
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

TEST(add_char_to_bufferTest, test_error_buffer_circle_full) {
	b.head = buff+4;
	*(b.head-1) = 'u';
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = BUFFER_FULL;
	int count = add_char_to_buffer(&b, 'c',  &err);

	EXPECT_EQ((int)'u', (int)(*(b.head-1)));
	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);
}

TEST(add_char_to_buffer_test, test_buffer_circle_full_2) {

	b.head = buff+3;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = BUFFER_FULL;
	int count = add_char_to_buffer(&b, 'd',  &err);

	EXPECT_EQ((int)'d', (int)*(b.head-1));
	EXPECT_EQ(4, count);
	EXPECT_EQ(res, err);
}

TEST(add_char_to_bufferTest, test_add_empty)
{
	b.head = buff+3;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res; 
	int count = add_char_to_buffer(&b, '\0',  &err);
	EXPECT_EQ(3, count);
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
	*(b.head) = getAdded;
	*(b.head+1)= getAdded;
	b.head += 2;

	char result = get_char_from_buffer(&b, &err);
	EXPECT_EQ((int)result, (int)getAdded);
	EXPECT_EQ(b.tail, b.head-1);
	EXPECT_EQ(res, err);
}

TEST(get_char_from_buffer_test, test_default_mid)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	b.head += 3;
	b.tail += 3;

	unsigned char getAdded = 'b';
	*(b.head) = getAdded;
	b.head += 1;
	char result = get_char_from_buffer(&b, &err);
	EXPECT_EQ((int)result, (int)getAdded);
	EXPECT_EQ(b.tail, b.head);
	EXPECT_EQ(res, err);
}

TEST(get_char_from_buffer_test, test_multiple_reads_over_edge) {
	b.buffer = buff;
	b.head = buff+1;
	b.tail = buff+3;	
	*(b.tail) = 'a';
	*(b.tail+1) = 'b';
	*(b.buffer) = 'c';
	ERROR_TYPE_t err1;
	ERROR_TYPE_t err2;
	ERROR_TYPE_t err3;
	char readVal1 = get_char_from_buffer(&b, &err1);
	char readVal2 = get_char_from_buffer(&b, &err2);
	char readVal3 = get_char_from_buffer(&b, &err3);
	char result1 = 'a';
	char result2 = 'b';
	char result3 = 'c';
	EXPECT_EQ(result1, readVal1);
	EXPECT_EQ(result2, readVal2);
	EXPECT_EQ(result3, readVal3);
	EXPECT_EQ(0, err1);
	EXPECT_EQ(0, err2);
	EXPECT_EQ(2, err3);
}

TEST(get_char_from_buffer_test, test_buffer_is_empty)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err = OK;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	char tmp = get_char_from_buffer(&b, &err);
	EXPECT_EQ(-1, (int)tmp);
	EXPECT_EQ(res, err); 

}

TEST(get_char_from_buffer_test, test_error_buffer_empty_mid)
{
	b.head = buff+1;
	b.tail = buff+1;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err = OK;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	unsigned char a = 'a';
	*(b.head) = a;
	b.head += 1;
	char tmp = get_char_from_buffer(&b, &err);
	EXPECT_EQ((int)a, (int)tmp);
	EXPECT_EQ(res, err); 
}

TEST(get_char_from_buffer_test, test_error_buffer_empty_circle)
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
	*(b.head) = a;
	b.head = b.buffer;
	char tmp = get_char_from_buffer(&b, &err);
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
	char tmp = get_char_from_buffer(&b, &err);
	EXPECT_EQ(-1, (int)tmp);
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
	*(b.head) = 'H';
	*(b.head+1) = 'i';
	b.head += 2;

	EXPECT_EQ(2, print_buffer(b, &err));
	EXPECT_EQ(res, err);

}


TEST(print_buffer_test, test_pointer_error)
{
	b.head = buff + 8;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = POINTER_ERROR;

	EXPECT_EQ(-1, print_buffer(b, &err));
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
	char hell[] = "Hell";

	for(int i = 0; hell[i] != '\0'; i++)
	{
		*(b.head) = hell[i];
		b.head +=1;
		if(b.head == (b.buffer + MAX_BUFFER))
		{
			b.head = b.buffer;
		}
	}

	EXPECT_EQ(4, print_buffer(b, &err));
	EXPECT_EQ(res, err);

}

TEST(print_buffer_test, test_over_border)
{
	b.head = buff + 3;
	b.tail = buff + 3;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	char hell[] = "Hell";

	for(int i = 0; hell[i] != '\0'; i++)
	{
		*(b.head) = hell[i];
		b.head +=1;
		if(b.head == (b.buffer + MAX_BUFFER))
		{
			b.head = b.buffer;
		}
	}

	EXPECT_EQ(4, print_buffer(b, &err));
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

	EXPECT_EQ(0, print_buffer(b, &err));
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

TEST(add_string_to_buffer_test, test_special_letters)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	unsigned char test[] = "?-+";
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int count = add_string_to_buffer(&b, test, &err);
	EXPECT_EQ(3, count);
	EXPECT_EQ(res, err);
	unsigned char result[4];
	result[0] = *(b.head - 3);
	result[1] = *(b.head - 2);
	result[2] = *(b.head - 1);
	result[3] = '\0';
	EXPECT_STREQ((char*)result, (char*)test);
}

TEST(add_string_to_buffer_test, test_buffer_becomes_full)
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

TEST(add_string_to_buffer_test, test_pointer_error)
{
	b.head = buff+7;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	unsigned char test[] = "test";
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = POINTER_ERROR;
	int count = add_string_to_buffer(&b, test, &err);
	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);
}

TEST(add_string_to_buffer_test, test_buffer_is_full)
{

	b.tail = buff;
	b.buffer = buff;
	b.head = b.buffer + 4;
	//init_buffer(&b, buff);

	unsigned char test[] = "test";
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = BUFFER_OVER_FLOW;
	int count = add_string_to_buffer(&b, test, &err);
	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);
}

TEST(add_string_to_buffer_test, test_buffer_overflow)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	unsigned char test [] = "this string is way to long";
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

TEST(get_string_from_buffer_test, test_read_default)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int len = 3;
	unsigned char string[] = "Hey";
	for(int i = 0; i < len; i++)
	{
		*(b.head) = string[i];
		b.head +=1;
	}
	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, 2, &err);	
	EXPECT_EQ(2, count);
	EXPECT_EQ(res, err);
	EXPECT_STREQ((char*)dest,(char*)"He");
}

TEST(get_string_from_buffer_test, test_read_border)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	ERROR_TYPE_t err;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	int len = 4;
	unsigned char string[] = "Hell";

	for(int i = 0; i < len; i++)
	{
		*(b.head) = string[i];
		b.head +=1;
		if(b.head == (b.buffer + MAX_BUFFER))
		{
			b.head = b.buffer;
		}
	}

	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
	EXPECT_EQ(len, count);
	EXPECT_EQ(res, err);
	EXPECT_STREQ((char*)dest,(char*) string);
}

TEST(get_string_from_buffer_test, test_read_over_border)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);
	b.tail += 3;
	*(b.tail) = 'Z';
	b.head += 4;

	ERROR_TYPE_t err;
	ERROR_TYPE_t res = OK;
	int len = 3;

	unsigned char string[] = "Hey";

	for(int i = 0; i < len; i++)
	{
		*(b.head) = string[i];
		b.head +=1;
		if(b.head == (b.buffer + MAX_BUFFER))
		{
			b.head = b.buffer;
		}
	}

	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
	EXPECT_EQ(len, count);
	EXPECT_EQ(res, err);
	EXPECT_STREQ((char*)dest, (char*)"ZHe");
}

TEST(get_string_from_buffer_test, test_get_not_empty_after_test) {

	b.buffer = buff;
	b.head = buff+3;
	b.tail = buff;
	*(b.buffer) = 'H';
	*(b.buffer+1) = 'e';
	*(b.buffer+2) = 'y';
	ERROR_TYPE_t err;
	int len = 2;
	unsigned char dest[len];
	int retVal = get_string_from_buffer(&b, dest, len, &err);
	EXPECT_EQ(0, err);
	EXPECT_EQ(2, retVal);
	EXPECT_STREQ("He", (char *) dest);
	EXPECT_EQ(b.buffer+3, b.head);
	EXPECT_EQ(b.buffer+2, b.tail);
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

	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
	EXPECT_EQ(-1, count);
	EXPECT_EQ(res, err);

}

TEST(get_string_from_buffer_test, test_buffer_empty_after_use)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	ERROR_TYPE_t err;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	int len = 4;
	int biggerLen = 6;
	char string[] = "Hell";

	for(int i = 0; i < len; i++)
	{
		*(b.head) = string[i];
		b.head +=1;
		if(b.head == (b.buffer + MAX_BUFFER))
		{
			b.head = b.buffer;
		}
	}

	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, biggerLen, &err);	
	EXPECT_EQ(len, count);
	EXPECT_EQ(res, err);
	EXPECT_STREQ((char*)dest, (char*)string);


}

TEST(get_string_from_buffer_test, test_buffer_empty_initalised)
{
	b.head = buff;
	b.tail = buff;
	b.buffer = buff;
	//init_buffer(&b, buff);

	ERROR_TYPE_t err;
	ERROR_TYPE_t res = EMPTY_BUFFER;
	int len = 4;
	unsigned char string[] ="";
	unsigned char dest[len];
	int count = get_string_from_buffer(&b, dest, len, &err);	
	EXPECT_EQ(0, count);
	EXPECT_EQ(res, err);
	EXPECT_STREQ((char*)dest, (char*)string);


}
