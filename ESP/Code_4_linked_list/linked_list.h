
typedef struct linked_list{
	char* data;
	int index; /* normally not used with linked lists, just for the exercises */
	struct linked_list *next;
	struct linked_list *previous;
} linked_list;


int add_to_list(linked_list *ll, char *s);

int display_item(linked_list *ll);

int display_list(linked_list *ll);

linked_list * search_from_list(linked_list *ll, char *s);

int delete_from_list(linked_list *ll, int index);

int empty_list(linked_list *ll);

int swap_items(linked_list *f, linked_list *s);

int sort_list(linked_list*ll);

int linkedlist_status(linked_list *ll);

int compare_strings(char*f, char*s);
