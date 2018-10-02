#include "ringbuffer.h"
#include <stdlib.h>
#include <stdio.h>

void init_buffer(struct buffer_type *b, unsigned char *buffer)
{
	b->head = buffer;
	b->tail = buffer;
	b->buffer = buffer;
}

error_type empty_buffer(struct buffer_type *b)
{
	b->tail = b-> head;
	return OK;
}

int get_buffer_state(struct buffer_type *b)
{
	int count = 0;
	if(b->buffer-b->tail > 0 || b->buffer - b->head > 0
			|| b->head - b->buffer > MAX_BUFFER-1 || b->tail - b->buffer > MAX_BUFFER-1)
	{
		return -1;
	}


	count = b->head - b->tail;	
	// if negativ then tail > head
	if(count < 0)
	{
		count =MAX_BUFFER + count;
	}

	return count;
}

int add_char_to_buffer(struct buffer_type *b, unsigned char a , error_type *err)
{
	if(b == NULL || get_buffer_state(b) == -1)
	{
		*err = POINTER_ERROR;
		return -1;
	} 
	if(b->tail - b->head == 1)
	{
		*err = BUFFER_FULL;
		return -1;
	}
	if(b->head == (b->buffer+MAX_BUFFER-1)&&(b->tail == b->buffer))
	{
		*err = BUFFER_FULL;
		return -1;
	} 
	if(*err == BUFFER_FULL)
	{
		return -1;
	}

	*(b->head) = a;
	b->head += 1;

	if(b->head - b->buffer > MAX_BUFFER-1)
	{
		b->head = b->buffer;
	}
	else if(b->tail - b->head == 1)
	{
		*err = BUFFER_FULL;
	}
	else if(b->head == (b->buffer+MAX_BUFFER-1)&&(b->tail == b->buffer))
	{
		*err = BUFFER_FULL;
	} 

	return get_buffer_state(b);
}

unsigned char get_char_from_buffer(struct buffer_type*b, error_type *err)
{
	unsigned char rw = 7;
	if(b == NULL || get_buffer_state(b) == -1)
	{
		*err = POINTER_ERROR;
		return rw;
	} 
	if(b->tail == b->head)
	{
		*err = EMPTY_BUFFER;
		return rw;
	}
	if(*err == EMPTY_BUFFER)
	{
		return rw;
	}

	unsigned char result = *(b->tail);
	b->tail += 1;

	if(b->tail - b->buffer > MAX_BUFFER-1)
	{
		b->tail = b->buffer;
		if(b->head-b->tail == 0)
	{
		*err = EMPTY_BUFFER;
}
	}
	else if(b->head - b->tail == 0)
	{
		*err = EMPTY_BUFFER;
	}
/*	else if((b->tail == (b->buffer+MAX_BUFFER-1)) && (b->head == b->buffer))
	{
		*err = EMPTY_BUFFER;
	}
*/
	return result;
}

int print_buffer(struct buffer_type *b, error_type *err)
{
	if(get_buffer_state(b) == -1)
	{
		*err = POINTER_ERROR;
		return -1;
	}
	if(b->head == b->tail)
	{
		*err = EMPTY_BUFFER;
		return -1;
	}
	if(*err == EMPTY_BUFFER)
	{
		return -1;
	}


	unsigned char *tmp = b->tail;
	int i =0; 
	while(tmp+i != b->head)
	{
		printf("%c", *(b->tail+i));
		i++;
		if(tmp+i - b->buffer > MAX_BUFFER-1)
		{
			tmp = b->buffer;
		}
	}


	*err = OK;
	return i;
}

int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err)
{
	int i;
	for(i = 0; s[i] != '\0'; i++){}
	int state = get_buffer_state(b);
	if(MAX_BUFFER-1 - state < i )
	{	
			*err = BUFFER_OVER_FLOW;
			return -1;
	}	
	int a = 0;
	while(*err == OK && a < i)
	{
		add_char_to_buffer(b,s[a] ,err);
		a++;
	}
	if(*err == OK)
	{
		return a;
	}
	if(*err == POINTER_ERROR)
	{
		return -1;
	}
	if(*err == BUFFER_FULL && s[a] == '\0')
	{
		return a;
	}
	if(*err == BUFFER_FULL && s[a] != '\0')
	{
		*err = BUFFER_OVER_FLOW;

	}

	return -1;
}

int get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err)
{
	int i = 0;

	while(*err == OK && i<len)
	{
		dest[i] = get_char_from_buffer(b, err);
		i++;
	}
	if(*err == OK || *err == EMPTY_BUFFER)
	{
		dest[i] = '\0';
		return i;
	}
	if(*err == POINTER_ERROR)
	{
		return -1;
	}
	return 0;
}


