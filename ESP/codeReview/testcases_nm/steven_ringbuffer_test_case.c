#include <gtest/gtest.h>
#include "ringbuffer.h"

unsigned char recive_buffer[MAX_BUFFER];

struct buffer_type
{
	unsigned char *head;
	unsigned char *tail;
	unsigned char *buffer;
};


//function 1 intialize buffer
TEST(init_buffer_test, normal){
	unsigned char rx_buffer[MAX_BUFFER];
    struct buffer_type r;

    init_buffer(&r,rx_buffer);

    EXPECT_EQ(r.head,rx_buffer);
    EXPECT_EQ(r.tail,rx_buffer);
    EXPECT_EQ(r.buffer,rx_buffer);
}

//function 2 test for empty
TEST(empty_buffer_test, test1){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	error_type erResult;
	
	init_buffer(&r,rx_buffer);
	r.head = (r.head+20);
	erResult = empty_buffer(&r);
	EXPECT_EQ(r.head, r.tail); 
	EXPECT_EQ(erResult, OK);
}

//function 3 bufferstate
TEST(get_buffer_state_test, tail_before_head){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	error_type err = OK;
				
	init_buffer(&r,rx_buffer);
	r.tail +=1;
		
	int result = get_buffer_state(&r, &err);
	EXPECT_EQ(result, MAX_BUFFER-1);
	EXPECT_EQ(err, OK);
}

TEST(get_buffer_state_test, head_before_tail){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	error_type err = OK;
	
	init_buffer(&r,rx_buffer);
	r.head +=12;
	
	int result = get_buffer_state(&r, &err);
	EXPECT_EQ(result, 12);
	EXPECT_EQ(err, OK);
}

TEST(get_buffer_state_test, pointer_error){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	error_type err = OK;
	
	init_buffer(&r,rx_buffer);
	r.head = r.buffer + MAX_BUFFER ;
	r.head += 10;
	
	int result = get_buffer_state(&r, &err);
	EXPECT_EQ(result, -1);
	EXPECT_EQ(err, POINTER_ERROR);
}

//function 4: add character
TEST(add_char_to_buffer_test, normal){
	unsigned char rx_buffer[MAX_BUFFER];
	unsigned char message = 'a';
	struct buffer_type r;
	error_type err = OK;
	
	init_buffer(&r,rx_buffer);	
	
	int result = add_char_to_buffer(&r, message , &err);
	EXPECT_EQ(err, OK);
	EXPECT_EQ(result, 1);
	EXPECT_EQ( rx_buffer[0], message);
}

TEST(add_char_to_buffer_test, buffer_full1){
	unsigned char rx_buffer[MAX_BUFFER];
	unsigned char message = 'a';
	struct buffer_type r;
	enum error_type err = OK;
	
	init_buffer(&r,rx_buffer);	
	r.head =  r.buffer + MAX_BUFFER;
	
	int result = add_char_to_buffer(&r, message , &err);
	EXPECT_EQ(err, BUFFER_FULL);
	EXPECT_EQ(result, -1);//-2
}

TEST(add_char_to_buffer_test, buffer_full2){
	unsigned char rx_buffer[MAX_BUFFER];
	unsigned char message = 'a';
	struct buffer_type r;
	enum error_type err = OK;
	
	init_buffer(&r,rx_buffer);	
	r.tail = r.buffer+1;
	
	int result = add_char_to_buffer(&r, message , &err);
	EXPECT_EQ(err, BUFFER_FULL);
	EXPECT_EQ(result, -1);
}

TEST(add_char_to_buffer_test, pointer_error){
	unsigned char rx_buffer[MAX_BUFFER];
	unsigned char message = 'a';
	struct buffer_type r;
	enum error_type err = OK;
	
	init_buffer(&r,rx_buffer);
	r.head = r.buffer+MAX_BUFFER+1;
	
	int result = add_char_to_buffer(&r, message , &err);
	EXPECT_EQ(err, POINTER_ERROR);
	EXPECT_EQ(result, -1);
}

//function 5 next char uitlezen

TEST(get_char_from_buffer_test, normal){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	
	init_buffer(&r,rx_buffer);
	
	add_char_to_buffer(&r, 'a', &err);
	add_char_to_buffer(&r, 'b', &err);
	add_char_to_buffer(&r, 'c', &err);
	
	EXPECT_EQ(get_char_from_buffer(&r, &err), 'a');
	EXPECT_EQ(get_char_from_buffer(&r, &err), 'b');
	EXPECT_EQ(get_char_from_buffer(&r, &err), 'c');
	EXPECT_EQ(err, OK);
}

TEST(get_char_from_buffer_test, pointer_error){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	
	init_buffer(&r,rx_buffer);	
	r.tail = r.buffer + MAX_BUFFER +10;
	
	get_char_from_buffer(&r, &err);
	EXPECT_EQ(err, POINTER_ERROR);
}

TEST(get_char_from_buffer_test, empty_buffer){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	
	init_buffer(&r,rx_buffer);
	
	get_char_from_buffer(&r, &err);
	EXPECT_EQ(err, EMPTY_BUFFER);
}

//function 6 print buffer

TEST(print_buffer_test, normaal){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	
	init_buffer(&r,rx_buffer);
	
	add_char_to_buffer(&r, 'a', &err);
	add_char_to_buffer(&r, 'b', &err);
	add_char_to_buffer(&r, 'c', &err);
	
	result = print_buffer(r, &err);
	EXPECT_EQ(err, OK);
	EXPECT_EQ(result, 3);
}

TEST(print_buffer_test, empty_buffer){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	
	init_buffer(&r,rx_buffer);
	result = print_buffer(r, &err);
	EXPECT_EQ(err, EMPTY_BUFFER);
	EXPECT_EQ(result, -1);
}

TEST(print_buffer_test, POINTER_ERROR){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	
	init_buffer(&r,rx_buffer);
	r.head = r.buffer + MAX_BUFFER + 3;
	
	result = print_buffer(r, &err);
	EXPECT_EQ(err, POINTER_ERROR);
	EXPECT_EQ(result, -1);
}

//next function, i lost count, adding a string 

TEST(add_string_to_buffer, normal){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	unsigned char message[] = "abc";
	
	init_buffer(&r,rx_buffer);
	
	result = add_string_to_buffer(&r, message, &err);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(rx_buffer[0], 'a');
}

TEST(add_string_to_buffer, head_before_tail){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	unsigned char message[] = "abc";
	
	init_buffer(&r,rx_buffer);
	r.head += 20;
	
	result = add_string_to_buffer(&r, message, &err);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(rx_buffer[20], 'a');
}

TEST(add_string_to_buffer, tail_before_head){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	unsigned char message[] = "abc";
	
	init_buffer(&r,rx_buffer);
	r.tail += 20;
	
	result = add_string_to_buffer(&r, message, &err);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(rx_buffer[0], 'a');
}

TEST(add_string_to_buffer, buffer_to_small){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	unsigned char message[] = "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789000123456789+212121212121azertyuiopqsdfghjklmwxcvbn";
	
	init_buffer(&r,rx_buffer);
	
	result = add_string_to_buffer(&r, message, &err);
	EXPECT_EQ(result, -1);
	EXPECT_EQ(err, BUFFER_FULL);
}

// just next function, gets string from buffer

TEST(get_string_from_buffer_test, normal){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	int len = 3;
	unsigned char s[3] ;	
	unsigned char message[] = "abc";

	init_buffer(&r,rx_buffer);
	add_string_to_buffer(&r, message, &err);
	
	result = get_string_from_buffer(&r, s, len, &err);
	EXPECT_EQ(result, 3);
	EXPECT_STREQ((const char*)message, (const char*)s);
}

TEST(get_string_from_buffer_test, pointer_error){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	enum error_type err = OK;
	int result = 0;
	int len = 3;
	unsigned char s[3] ;
	unsigned char message[] = "abc";

	init_buffer(&r,rx_buffer);
	r.head = r.buffer + MAX_BUFFER +20;
	add_string_to_buffer(&r, message, &err);
	
	result = get_string_from_buffer(&r, s, len, &err);
	EXPECT_EQ(result, 3);
	EXPECT_STREQ((const char*)message, (const char*)s);
}