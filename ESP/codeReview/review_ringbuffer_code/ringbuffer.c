#include "ringbuffer.h"
#include <stdlib.h>
#include <stdio.h>

// initializes the buffer, by placing the pointers to beginning of buffer
void init_buffer(struct buffer_type *b, unsigned char *buffer)
{
	b->head = buffer;
	b->tail = buffer;
	b->buffer = buffer;
}

// Empties the buffer by moving tail to head
error_type empty_buffer(struct buffer_type *b)
{
	b->tail = b-> head;
	return OK;
}

// Checks the status of buffer and returns 
// amount of characters in buffer and -1 in an error condition
int get_buffer_state(struct buffer_type *b, error_type *err)
{
	int count = 0;
	if(
			b->buffer-b->tail > 0 
			|| b->buffer - b->head > 0
			|| b->head - b->buffer > MAX_BUFFER-1
			|| b->tail - b->buffer > MAX_BUFFER-1
	  )
	{
		*err = POINTER_ERROR;
		return -1;
	}

	count = b->head - b->tail;	
	// if negativ then tail > head
	if(count < 0)
	{
		count =MAX_BUFFER + count;
	}
	if(count == 0)
	{
		*err = EMPTY_BUFFER;
	}
	else if(count == MAX_BUFFER-1)
	{
		*err = BUFFER_FULL;
	}
	else
	{
		*err = OK;
	}

	return count;
}

// add one character to buffer and return amount of character in buffer
int add_char_to_buffer(struct buffer_type *b, unsigned char a , error_type *err)
{
	if(get_buffer_state(b, err) == -1)
	{
		return -1;
	} 
	if(*err == BUFFER_FULL)
	{
		return -1;
	} 
	if(a == '\0')
	{
		return get_buffer_state(b, err);
	}

	*(b->head) = a;
	b->head += 1;

	if(b->head - b->buffer > MAX_BUFFER-1)
	{
		b->head = b->buffer;
	}

	return get_buffer_state(b, err);
}

// return one char from the buffer
char get_char_from_buffer(struct buffer_type*b, error_type *err)
{
	char result;

	if(get_buffer_state(b, err) == -1)
	{
		*err = POINTER_ERROR;
		return -1;
	} 
	if(*err == EMPTY_BUFFER)
	{
		*err = EMPTY_BUFFER;
		return -1;
	}
	result = *(b->tail);
	b->tail += 1;

	if(b->tail - b->buffer > MAX_BUFFER-1)
	{
		b->tail = b->buffer;
	}
	if(b->head ==  b->tail)
	{
		*err = EMPTY_BUFFER;
	}

	return result;
}

// prints the buffer without moving the pointers
int print_buffer(struct buffer_type b, error_type *err)
{
	int i = 0; 
	int count = 0;
	unsigned char *tmp;

	if(get_buffer_state(&b, err) == -1)
	{
		return -1;
	}
	if(*err == EMPTY_BUFFER)
	{
		*err = EMPTY_BUFFER;
		return 0;
	}

	tmp = b.tail;

	while(tmp + i != b.head)
	{
		printf("%c", *(tmp+i));
		i++;
		if(tmp+i  == (b.buffer + MAX_BUFFER))
		{
			tmp = b.buffer;
			i = 0;
		}
		count ++;
	}

	get_buffer_state(&b, err);	
	return count;
}

// add a string to the buffer and return the amount of added characters
// return -1 with BUFFER_OVER_FLOW if not all character could be added
// the buffer remains then unchanged
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err)
{
	int string_size;
	int state = get_buffer_state(b, err);
	int a = 0; // a as a count variable

	for(string_size = 0; s[string_size] != '\0'; string_size++){}
	if(state == -1)
	{
		return -1;
	}
	if(MAX_BUFFER-1 - state < string_size )
	{	
		*err = BUFFER_OVER_FLOW;
		return -1;
	}	

	*err = OK;

	while(*err == OK && a < string_size)
	{
		add_char_to_buffer(b,s[a] ,err);
		a++;
	}
	if(*err == BUFFER_FULL)
	{
		return a;
	}

	*err = OK;
	return a;
}

// get a amount of character from the buffer and returns the read amount
int get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err)
{
	// i as a count variable
	int i = 0;
	while(i < len)
	{	get_buffer_state(b, err);
		if(*err != EMPTY_BUFFER)
		{
			dest[i]= get_char_from_buffer(b, err);
			i++;
			if(*err == POINTER_ERROR)
			{
				return -1;
			}
		}else{

			dest[i] = '\0';
			return i;
		}
	}

	dest[i] = '\0';
	get_buffer_state(b, err);
	return i;	
}

