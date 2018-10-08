#define MAX_BUFFER 5

typedef enum error_type{
	OK,
	BUFFER_OVER_FLOW,
	EMPTY_BUFFER,
	POINTER_ERROR,
	BUFFER_FULL
} ERROR_TYPE_t;

struct buffer_type
{
	unsigned char *head;
	unsigned char *tail;
	unsigned char *buffer;
};

void init_buffer(struct buffer_type *b, unsigned char *buffer);

error_type empty_buffer(struct buffer_type *b);

int get_buffer_state(struct buffer_type *b);

int add_char_to_buffer(struct buffer_type *b, unsigned char a, error_type *err);

char get_char_from_buffer(struct buffer_type*b, error_type *err);

int print_buffer(struct buffer_type b, error_type *err);

int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err);

int get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err);


