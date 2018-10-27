#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

/* 
   Function will create a new list item and add that to end of list
   create a new element (malloc)
   add s to data item of new element
   make link from last element to new element (next)
   add NULL to new elements next
   write new index (last+1) to new elements index
 *ll is pointing to head of the list
 return -1 as error (no space left), index position in success
 */
int add_to_list(linked_list *ll, char*s)
{
	linked_list *new_box;
	linked_list *previous;



	// check if ll is null, then return -1, because we can't change a nullpointer
	// check if s is null, it's no use storing a nullpointer
	if(ll == NULL || s == NULL)
	{
		return -1;
	}

	//malloc new space for the new element
	if((new_box = (linked_list*) malloc(sizeof(linked_list))) == NULL)
	{
		// not enough memory space
		return -1;
	}


	// ll wasn't null so set the data and count till tmp->next is null
	new_box -> next = NULL; // set next and data
	new_box -> data = s;

	while(ll->next != NULL){
		ll = ll->next;
	} 
	// now we are at the last position
	new_box -> index = ll -> index + 1;

	ll -> next = new_box;

	return new_box -> index;
}


// displays the required element 
// (pointed by parameter linked_list *ll) in a list
// Return: -1 if element was not found else 0 ok
int display_item(linked_list *ll)
{
	// check if the item exists
	if(ll == NULL)
	{
		return -1;
	}

	// print data in a seperated lien
	printf("\n%s\n", ll->data);

	return 0;
}




// List all elements in a list
// return: number of elements in list
int display_list(linked_list *ll)
{

	linked_list *tmp = ll;
	if(ll == NULL)
	{
		// list does not exits therefore I return -1
		return -1;
	}
	while(ll != NULL)
	{
		printf("\n----------------------------------\n");
		printf("%s\n", ll->data);
		tmp = ll;
		ll = ll->next;

	}
	printf("\n----------------------------------\n");

	return tmp->index + 1;

}

// search for a data *s from a list
// Return: NULL if not found else pointer to to data

linked_list * search_from_list(linked_list *ll, char *s)
{
	// listobject or string doesn't exist
	if(ll == NULL || s == NULL)
	{
		return NULL;
	}

	int length_of_data_string;
	int length_of_given_string;
	int i = 0;

	// count both strings
	for(length_of_data_string = 0; ll->data[length_of_data_string] != '\0'; length_of_data_string++);
	for(length_of_given_string = 0; s[length_of_given_string] != '\0'; length_of_given_string++);

	if(length_of_data_string != length_of_given_string)
	{
		// check  if the lenght of both string is the same
		// if not I don't need to compare the strings
		return search_from_list(ll->next, s);
	}

	while( i < length_of_given_string)
	{
		if(ll -> data[i] != s[i])
		{
			return search_from_list(ll->next, s);
		}
		i++;
	}
	// if I get to this point, the data and s should be the same
	return ll;
}


// Delete item from a list and free the space
// Rest of the list items index will be countet again
// Return value: -1 on error else length of remaining list
int delete_from_list(linked_list *ll, int index)
{
	linked_list *last;
	// return -1 if list doesn't exist or is empty
	// or someone tries to remove the head which is not possible without a 
	// diffrent return type or parametertype of linked_list**
	if(ll == NULL || index == 0)
	{
		return -1;
	}


	last = ll;
	while(ll->next != NULL)
	{
		if(ll->index == index)
		{	
			last ->next = ll->next;
			free(ll);
			ll = last->next;
			while(ll -> next != NULL)
			{
				ll->index = last -> index + 1;
				last = ll;
				ll = ll->next;
			}
			// don't forget the last one
			ll->index = last -> index + 1;
			// list got new indexes
			// return the end index +1 (don't forget the value at 0)
			return ll -> index + 1; 
		}
		last = ll;
		ll = ll->next;

	}
	// look if the last element is the one we want to delete
	if( ll->index == index)
	{
		last -> next = NULL;
		free(ll);
		return last->index + 1;
	}

	// we didn't find the index, bail out with -1
	return -1;
}

// remove all items from the list and will free allocated memory
// return value items deleted from list
int empty_list(linked_list *ll)
{
	linked_list *tmp;
	linked_list *last;
	int last_index;
	// list does not exist
	if(ll == NULL)
	{
		return -1;
	}

	//first count items in list
	tmp = ll;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	// now we are at the last position
	last_index = tmp->index;

	// check if the first element is null, if not delete it
	while(ll->next != NULL)
	{
		tmp = ll;
		last = ll; // in case we only have 1 element

		// start at the end and delete every item
		while(tmp->next != NULL)
		{
			last = tmp;
			tmp = tmp->next;

		}
		free(tmp);
		last->next = NULL;

	}
	// there is still the head left, but like in delete_from_list 
	// it is not possible for me to delete it 

	// on index 0 we also store something, so index+1 is our itemcount	
	return last_index;

}


// swap order of two items
// return value 0 if ok, -1 if either item was not in the list(content of the list did not chagne)
int swap_items(linked_list *f, linked_list *s)
{
	char* tmp_f;

	// check if s and f exist
	if(f == NULL || s == NULL)
	{
		return -1;
	}

	// save the data in the temporary string
	tmp_f = f -> data;

	// swap the data
	f->data = s->data;
	s->data = tmp_f;

	return 0;
}

// sort list in rising order based on data
// only works with same capital letter
// else ascii numbers will be used and could differ the result
int sort_list(linked_list*ll)
{
	linked_list* outer_iterator = ll;	
	linked_list* inner_iterator = ll;

	int comp;
	// list does not exist
	if(ll == NULL)
	{
		return -1;
	}

	while(outer_iterator != NULL)
	{
		while(inner_iterator != NULL)
		{
			// use own function to compare strings
			comp = compare_strings(outer_iterator->data, inner_iterator->data);
			if(comp == 1)
			{
				// the new element is smaller, so we call swap to change it 
				// to the place of the compared string
				swap_items(outer_iterator, inner_iterator);
			}
			inner_iterator = inner_iterator->next;
		}
		outer_iterator = outer_iterator->next;
		inner_iterator = outer_iterator;
	}
	// when we are here everything worked fine and we return 0
	return 0;

}

// check if 2 given strings are the same return 1 if the first is greater than the second
// 0 if they are the same and -1 if the second string is bigger
int compare_strings(char* f, char* s)
{
	// return 0 in case of a nullpointer, so no swap will be executed
	if(f == NULL || s == NULL)
	{
		return 0;
	}
	int i = 0;
	while (f[i] != '\0')
	{
		if (s[i] == '\0')
		{
			return 1;
		}
		if (s[i] > f[i])
		{
			return -1;
		}
		if (f[i] > s[i])
		{
			return 1;
		}
		i++;
	}
	if(s[i] != '\0')
	{
		return -1;
	}
	return 0; // strings are the same
}

// will count the number of elements in the list
// return value: amount
int linkedlist_status(linked_list *ll)
{
	// list does not exits return -1
	if(ll == NULL)
	{
		return -1;
	}
	if(ll->next == NULL)
	{
		// if ll->next is null return the index +1 because of the value at index 0
		return ll->index+1;
	}else{
		// if ll->next is not null call the function recursive with ll->next as ll
		return linkedlist_status(ll->next);
	}
}
