#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

// implemention of the basic functions

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
	if((new_box = (linked_list*) malloc(sizeof(linked_list))) == NULL)
	{
		// not enough memory space
		return -1;
	}
	// check if ll is null, then return -1, because we can't change a nullpointer
	// check if s is null, it's no use storing a nullpointer
	if(ll == NULL || s == NULL)
	{
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

// int displays the required element 
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
	while(tmp->next != NULL)
	{
		printf("\n----------------------------------\n");
		printf("%s\n", tmp->data);
		tmp = tmp->next;

	}
	printf("\n----------------------------------\n");

	return tmp->index+1;

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
	// or someone tries to remove the head or an invalid pointer
	if(ll == NULL || index <= 0)
	{
		return -1;
	}

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
			// return the end index
			return ll -> index+1; 
		}
		last = ll;
		ll = ll->next;

	}
	// look if the last element is the one we want to delete
	if( ll->index == index)
	{
		last -> next = NULL;
		free(ll);
		return last->index+1;
	}

	// we didn't find the index, bail out with -1
	return -1;
}
