//#include <gtest/gtest.h>
#include "ringbuffer.h"

//initializes the buffer, by placing the pointers to beginning of buffer
void init_buffer(struct buffer_type *b, unsigned char *buffer)
{
	b->head=buffer;
    	b->tail=buffer;
    	b->buffer=buffer;
}

//Empties the buffer by moving tail to head
//error_type  indicates error condition (use enum error_type)
//Only OK as a return value is used in this function
error_type empty_buffer(struct buffer_type *b){
	b->tail = NULL; //point to nowhere
	b->tail = b->head;
	return OK;
}

//Checks the status of buffer and returns
//Amount of characters in buffer
//-1 in error condition
/*
int get_buffer_state(struct buffer_type *b, error_type *err){
	int x = (int)b->tail;
	int y = (int)b->head;
	//printf("Tail: %d.\n", x);
	//printf("Head: %d.\n", y);
	//check status of the buffer
	if(x == ((y+1)%MAX_BUFFER)){
		*err = (error_type) 4;
		//printf("Buffer is full.\n");
		return MAX_BUFFER;
	}
	else if(x > ((y+1)%MAX_BUFFER)){
		*err = (error_type) 3;
		//printf("Pointer error.\n");
		return -1;
	}
	else if(x==y){
		*err = (error_type) 2;
		//printf("Buffer is empty.\n");
		return 0;
	}
	else if(y > (x + MAX_BUFFER)){
		*err = (error_type) 1;
		//printf("Buffer is overflow.\n");
		return -1;
	}
	else{
		*err = (error_type) 0; //buffer is ok
		int amount = y - x;		
		//printf("Buffer is OK, amount: %d.\n", amount);
		if(amount>0){
			return amount;
		}else{
			return (amount + MAX_BUFFER);
		}
	}
}
*/
int get_buffer_state(struct buffer_type *b, error_type *err){
	unsigned char* x = b->tail;
	unsigned char* y = b->head;
	//printf("Tail: %d.\n", x);
	//printf("Head: %d.\n", y);
	//check status of the buffer
	if(x == ((y+1)%MAX_BUFFER)){
		*err = (error_type) 4;
		//printf("Buffer is full.\n");
		return MAX_BUFFER;
	}
	else if(x > ((y+1)%MAX_BUFFER)){
		*err = (error_type) 3;
		//printf("Pointer error.\n");
		return -1;
	}
	else if(x==y){
		*err = (error_type) 2;
		//printf("Buffer is empty.\n");
		return 0;
	}
	else if(y > (x + MAX_BUFFER)){
		*err = (error_type) 1;
		//printf("Buffer is overflow.\n");
		return -1;
	}
	else{
		*err = (error_type) 0; //buffer is ok
		int amount = y - x;		
		//printf("Buffer is OK, amount: %d.\n", amount);
		if(amount>0){
			return amount;
		}else{
			return (amount + MAX_BUFFER);
		}
	}
}
//adding one character to buffer
//return amount of character in buffer 
//-1 - in error condition and infor of error
int add_char_to_buffer(struct buffer_type *b,  unsigned char c, error_type *err){
	//if buffer is over flow, pointer error or full
	if(*err == 1 || *err == 3 || *err == 4){
		//printf the error infor
		return -1;
	}
	else{	
		//printf("\n***Add char to buffer***\n");
		*(b->head) = c;
		//printf("Added char: %c\n", *(b->head));
		(b->head)++;
		//check state and get amount of character
		int amount = get_buffer_state(b, err);
		return amount;
	}
}

//function will return character read from buffer
//-1 - in error condition,  err more info of error
unsigned char get_char_from_buffer(struct buffer_type *b, error_type *err){
	//if buffer is over flow, pointer error or empty
	if(*err == 1 || *err == 3 || *err == 2){
		//printf the error infor
		return -1;
	}
	else{	
		//printf("\n***Get char from buffer***\n");
		unsigned char c;
		c = *(b->tail);
		//printf("Tail: %d\n", (int)(b->tail));
		//printf("Read char: %c\n", c);
		(b->tail)++;
		return c;
	}
}

//list characters from buffer, use clear reading printing (without moving pointers)
//Function will return amount of character in buffer 
//-1 in error condition,  err more info of error
/*
int print_buffer(struct buffer_type *b, error_type *err){
	//create a copy of pointer b
	struct buffer_type *copy_b = (buffer_type *)malloc(sizeof(b));
	copy_b->tail = b->tail;	
	copy_b->head = b->head;

	
	printf("Tail: %d\n", (int)(b->tail));
	printf("head: %d\n", (int)(b->head));
	printf("Tail: %d\n", (int)(copy_b->tail));
	printf("head: %d\n", (int)(copy_b->head));
	

	while(get_buffer_state(copy_b,err)){
		printf("%c", get_char_from_buffer(copy_b, err));
	}
	printf("\n");
	
//	printf("Tail: %d\n", (int)(b->tail));
//	printf("head: %d\n", (int)(b->head));
//	printf("Tail: %d\n", (int)(copy_b->tail));
//	printf("head: %d\n", (int)(copy_b->head));
	

	return get_buffer_state(b,err);
}
*/
int print_buffer(struct buffer_type b, error_type *err){
	//create a copy of pointer b
	struct buffer_type copy_b = b;
	copy_b.tail = b.tail;	
	copy_b.head = b.head;

/*	
	printf("Tail: %d\n", (int)(b->tail));
	printf("head: %d\n", (int)(b->head));
	printf("Tail: %d\n", (int)(copy_b->tail));
	printf("head: %d\n", (int)(copy_b->head));
*/	

	while(get_buffer_state(&copy_b,err)){
		printf("%c", get_char_from_buffer(&copy_b, err));
	}
	printf("\n");
	
//	printf("Tail: %d\n", (int)(b->tail));
//	printf("head: %d\n", (int)(b->head));
//	printf("Tail: %d\n", (int)(copy_b->tail));
//	printf("head: %d\n", (int)(copy_b->head));
	

	return get_buffer_state(&b,err);
}
//functions that will add string to buffer
//return amount of character added to buffer
//-1 if all string connot be added and string remain unchanged.
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err){
	int amount = get_buffer_state(b,err);
	int add=0;
	int size = strlen((const char *)s);
	//OK or EMPTY
	if(*err == 0 || *err == 2){
		if((amount+size)<=MAX_BUFFER){
			while(*s){
				*(b->head) = *s;
				(b->head)++;
				s++;
				add++;
		}
		return add;
		}	
		else{
			return -1;
		}
	}
	else{
		return -1;
	}
}

//get numbers of characters to be read from buffer by parameter
//will return amount of characters read from buffer
//-1 error condition, err will have reason
int get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err){
	int amount=get_buffer_state(b,err);
	int get=0;
	//OK or FULL
	if(*err == 0 || *err == 4){
		//if there is enough char to get
		if((amount-len)>=0){
			while(get<len){
			dest[get] = *(b->tail);
			(b->tail)++;
			get++;
			}
			return get;
		}	
		else{
			return -1;
		}
	}	
	else{
		return -1;
	}
}




























