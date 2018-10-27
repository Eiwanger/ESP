#include <gtest/gtest.h>
#include "linked_list.h"





/***************************************************************************/
/*                 Test for add_to_list function                           */
/***************************************************************************/

// test the add_to_list function when the head already exits 
TEST(add_to_list_test,test_normal) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL; 
	head->data=str; 
	head->index=0;

	i=add_to_list(head,str1);
	EXPECT_EQ(1,i);

	i=add_to_list(head,str2);
	EXPECT_EQ(2,i);

	i=add_to_list(head,str3);
	EXPECT_EQ(3,i);

	i=add_to_list(head,str4);
	EXPECT_EQ(4,i);

	i=add_to_list(head,str5);
	EXPECT_EQ(5,i);

	i=add_to_list(head,str6);
	EXPECT_EQ(6,i);

}

/*-------------------------------------------------------------------------*/

// test if the function returns -1 in case the head is null
TEST(add_to_list_test, test_head_equals_null)
{
	char str[15]="List Start";
	int i;
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head = NULL;

	// expect -1 for an error
	i = add_to_list(head, str);

	EXPECT_EQ(i, -1);

}

/*-------------------------------------------------------------------------*/

// test if the function returns -1 when the string is null
TEST(add_to_list_test, test_string_equals_null)
{
	char* str = NULL;
	int i;
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;


	i = add_to_list(head, str);

	EXPECT_EQ(i, -1);

}

/***************************************************************************/


/***************************************************************************/
/*                 Test for display_item function                          */
/***************************************************************************/

// test the display_item function, the return value is the same as the index
TEST(display_item_test, test_normal)
{
	char str[20] = "User check me out";
	int i;
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	// print it two times, so the tester can see if it works in the terminal
	printf("%s\n", str);
	i = display_item(head);


	EXPECT_EQ(i, 0);
}

/*-------------------------------------------------------------------------*/

// test return value ok of a listelement in the middle of a list
TEST(display_item_test, test_return_ok)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	printf("%s\n", str4);
	i = display_item(head->next->next->next->next);

	EXPECT_EQ(i, 0);
}


/*-------------------------------------------------------------------------*/
// test the display_item function if the pointer is null
TEST(display_item_test, test_nullpointer)
{
	char str[20] = "User check me out";
	int i;
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i = display_item(head->next);

	// Expect an error and so -1

	EXPECT_EQ(i, -1);
}

/***************************************************************************/


/***************************************************************************/
/*                 Test for display_list function                          */
/***************************************************************************/

TEST(display_list_test,test_empty)
{
	int result;
	char str[15]="List Start";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->next=NULL;
	head->data=str;
	head->index=0;

	result = display_list(head);

	// there is 1 value which is in the list so we expect 1
	EXPECT_EQ(result, 1);
}

/*-------------------------------------------------------------------------*/
// test display_list if it returns -1 in case of a nullpointer
TEST(display_list_test,test_nullpointer)
{
	int result;
	char str[15]="List Start";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
	head = NULL;

	// head point to null => list does not exits so we expect -1
	result = display_list(head);

	EXPECT_EQ(result, -1);

}


/*-------------------------------------------------------------------------*/
// test display_list and check return value of the function
TEST(display_list,test_normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;


	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	printf("Expect list looks like this\n");

	printf("%s\n",str);	
	printf("%s\n",str1);	
	printf("%s\n",str2);	
	printf("%s\n",str3);	

	i = display_list(head);

	// 5 values in the list => we expect a 5
	EXPECT_EQ(i, 5);
}

/***************************************************************************/


/***************************************************************************/
/*                 Test for search_from_list function                      */
/***************************************************************************/

// test a normal search in search_from_list function
TEST(search_from_list_test,test_normal)
{
	char str[15]="List Start";
	char str1[15]="second";
	char str2[15]="third";

	linked_list *found;
	struct linked_list *head;

	head = (struct linked_list*) malloc(sizeof(linked_list));
	head->data=str;
	head->index=0;


	head->next = (struct linked_list*) malloc(sizeof(linked_list));
	head->data=str1;
	head->index=1;

	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));
	head->next->index=2;
	head->next->data=str2;


	head->next->next->next = 0;


	found=search_from_list(head,(char *)"second");
	EXPECT_EQ(found->index, 1);
	EXPECT_STREQ(str1,found->data);
}

/*-------------------------------------------------------------------------*/
// test different lenght, special letters, and strings which differ only in the last char
TEST(search_from_list_test,test_special_cases)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="zert";
	char str3[40]="This string tests special letters!";
	char str4[40]="This string tests special letters+";
	char str5[40]="This string tests_special letters";
	char str6[40]="This string tests-special letters";
	int i;

	linked_list *found;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->index=5;
	head->next->next->next->next->next->data=str5;
	head->next->next->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->next->index=6;
	head->next->next->next->next->next->next->data=str6;
	head->next->next->next->next->next->next->next = NULL;


	// tests with strings which differ only in the last character
	found=search_from_list(head,(char *)"This string tests special letters+");
	EXPECT_EQ(found->index, 4);
	EXPECT_STREQ(str4,found->data);

	found=search_from_list(head,(char *)"This string tests_special letters");
	EXPECT_EQ(found->index, 5);
	EXPECT_STREQ(str5,found->data);

	found=search_from_list(head,(char *)"This string tests-special letters");
	EXPECT_EQ(found->index, 6);
	EXPECT_STREQ(str6,found->data);

	found=search_from_list(head,(char *)"zero");
	EXPECT_EQ(found->index, 1);
	EXPECT_STREQ(str1,found->data);

	found=search_from_list(head,(char *)"zert");
	EXPECT_EQ(found->index, 2);
	EXPECT_STREQ(str2,found->data);

	// tests if the string differ in lenght
	found=search_from_list(head,(char *)"This string tests special l");
	EXPECT_EQ((int*)found, (int*)NULL);
}

/*-------------------------------------------------------------------------*/
// test return value of search_from_list if value was not found
TEST(search_from_list,test_not_found)
{
	char str[15]="List Start";

	linked_list *found;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->next=NULL;
	head->data=str;
	head->index=0;

	found=search_from_list(head,(char *)"third");

	EXPECT_EQ((int *)found,(int *)NULL);
}

/*-------------------------------------------------------------------------*/
// test return value of search_from_list if head or string are nullpointer 
TEST(search_from_list,test_nullpointer)
{
	char str[15]="List Start";

	linked_list *found;

	linked_list *head;
	head = NULL;

	// list doesn't exist so we expect NULL as for found 
	found=search_from_list(head,(char *)"third");

	EXPECT_EQ((int *)found,(int *)NULL);

	// test result if string is a nullpointer
	head = (struct linked_list*) malloc(sizeof(linked_list));  
	head->next = NULL;
	head->index = 0;
	head->data = str;

	found=search_from_list(head,(char*)NULL);
	EXPECT_EQ((int*)found, (int*)NULL);
}

/***************************************************************************/


/***************************************************************************/
/*                 Test for delete_from_list function                      */
/***************************************************************************/

// test delete_from_list, add some list elements and delete one
TEST(delete_from_list_test,test_normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	// check if str2 is on pos index 2
	EXPECT_STREQ(head->next->next->data,str2);

	i = delete_from_list(head,2);
	// after deleting index 2, str3 should now be on the pos of index 2
	EXPECT_STREQ(head->next->next->data,str3);
	// we delete one, so there a still 4 elements left in the list
	EXPECT_EQ(i,4);

	printf("%d : %s \n", head->index, head->data);
	printf("%d : %s \n", head->next->index, head->next->data);
	printf("%d : %s \n", head->next->next->index, head->next->next->data);
	printf("%d : %s \n", head->next->next->next->index, head->next->next->next->data);
}

/*-------------------------------------------------------------------------*/
// test delete_from_list to return -1 in case of nullpointer
TEST(delete_from_list_test,test_nullpointer)
{
	char str[15]="List Start";

	linked_list *found;
	int result;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
	head = NULL;

	// list doesn't exist so we expect -1 for result 
	result = delete_from_list(head, 3);
	EXPECT_EQ(result, -1);
}

/*-------------------------------------------------------------------------*/
// test delete_from_list and only delete the head 
TEST(delete_from_list_test,test_delete_head) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	char str7[10]="seventh";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next =  (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->index=5;
	head->next->next->next->next->next->data=str5;
	head->next->next->next->next->next->next =  (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->next->index=6;
	head->next->next->next->next->next->next->data=str6;
	head->next->next->next->next->next->next->next =  (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->next->next->index=7;
	head->next->next->next->next->next->next->next->data=str7;
	head->next->next->next->next->next->next->next->next = NULL; 

	// check indexes 
	EXPECT_STREQ(head->data, str);
	EXPECT_STREQ(head->next->data, str1);
	EXPECT_STREQ(head->next->next->data, str2);

	// remove elements and check the remaining lenght
	i = delete_from_list(head,0);
	EXPECT_EQ(i, -1);

	i = delete_from_list(head,0);
	EXPECT_EQ(i, -1);


}

/*-------------------------------------------------------------------------*/
// test delete_from_list multiple times
TEST(delete_from_list_test,multi) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	char str7[10]="seventh";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next =  (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->index=5;
	head->next->next->next->next->next->data=str5;
	head->next->next->next->next->next->next =  (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->next->index=6;
	head->next->next->next->next->next->next->data=str6;
	head->next->next->next->next->next->next->next =  (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->next->next->next->index=7;
	head->next->next->next->next->next->next->next->data=str7;
	head->next->next->next->next->next->next->next->next = NULL; 

	// check indexes 
	EXPECT_STREQ(head->next->next->data, str2);
	EXPECT_STREQ(head->next->next->next->data, str3);
	EXPECT_STREQ(head->next->next->next->next->data, str4);

	// remove elements and check the remaining lenght
	i = delete_from_list(head,2);
	EXPECT_EQ(i, 7);

	i = delete_from_list(head,3);
	EXPECT_EQ(i, 6);

	i = delete_from_list(head,4);
	EXPECT_EQ(i, 5);

	// check again elements data
	EXPECT_STREQ(head->next->next->data, str3);
	EXPECT_STREQ(head->next->next->next->data, str5);
	EXPECT_STREQ(head->next->next->next->next->data, str7);

}

/*-------------------------------------------------------------------------*/
// test delete_from_list if index is out of bounds
TEST(delete_from_list_test,test_index_out_of_bounds)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	// check if str2 is on pos index 2
	EXPECT_STREQ(head->next->next->data,str2);

	i = delete_from_list(head,400);
	// after deleting index 2, str3 should now be on the pos of index 2
	EXPECT_EQ(i,-1);
}

/*-------------------------------------------------------------------------*/
// test delete_from_list if we delete the last element 
TEST(delete_from_list_test,test_delete_last_elements)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = NULL;

	// delete the first element, expect lenght of 0
	i = delete_from_list(head,1);

	// there is still the head with data so we expect 1
	EXPECT_EQ(i,1);

	// delete the head, it should throw an error so we expect  
	i = delete_from_list(head, 0);	
	EXPECT_EQ(i,-1);
}
/***************************************************************************/


/***************************************************************************/
/*                 Test for empty_list                                     */
/***************************************************************************/

// test empty_list without expected errors
TEST(empty_list_test,test_normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	// call empty_list
	i = empty_list(head);
	// after empty_list call check the amount of items which were in the list
	EXPECT_EQ(i,5);
	// check if head ->next is null
	EXPECT_EQ((linked_list*)head->next, (linked_list*)NULL);
}

/*-------------------------------------------------------------------------*/
// test empty_list with a nullpointer 
TEST(empty_list_test,test_nullpointer)
{
	int i;
	linked_list *head = NULL;

	i = empty_list(head);
	// Expect -1 for an error
	EXPECT_EQ(i,-1);
}

/*-------------------------------------------------------------------------*/
// test empty_list with only one element in the list 
TEST(empty_list_test,test_single_element_in_list)
{
	char str[15]="List Start";
	char str1[10]="zero";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = NULL;

	i = empty_list(head);
	// after empty_list call check the amount of items which were in the list
	EXPECT_EQ(i,2);
	// check if head ->next is null
	EXPECT_EQ((linked_list*)head->next, (linked_list*)NULL);
}
/***************************************************************************/


/***************************************************************************/
/*                 Test for swap_items                                     */
/***************************************************************************/

// test swap_items expecting 0 foor OK 
TEST(swap_items_test,test_normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	// check the strings of the listelements we want to change
	EXPECT_STREQ(head->next->data, str1);
	EXPECT_STREQ(head->next->next->data, str2);


	// call swap_items
	i = swap_items(head->next,head->next->next);
	// check the return value
	EXPECT_EQ(i,0);
	// check the position of the data
	EXPECT_STREQ(head->next->data, str2);
	EXPECT_STREQ(head->next->next->data, str1);
}
/*-------------------------------------------------------------------------*/

// test swap_items with strings which differ in legth expecting 0 foor OK 
TEST(swap_items_test,test_swap_different_length)
{
	char str[15]="List Start";
	char str1[40]="Let's see if this works";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	// check the strings of the listelements we want to change
	EXPECT_STREQ(head->next->data, str1);
	EXPECT_STREQ(head->next->next->data, str2);


	// call swap_items
	i = swap_items(head->next,head->next->next);
	// check the return value
	EXPECT_EQ(i,0);
	// check the position of the data
	EXPECT_STREQ(head->next->data, str2);
	EXPECT_STREQ(head->next->next->data, str1);
}
/*-------------------------------------------------------------------------*/

// test swap_items expecting 0 foor OK 
TEST(swap_items_test,test_nullpointer)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	// check the strings of the listelements we want to change


	// call swap_items
	i = swap_items(head->next,head->next->next->next->next->next);
	// check the return value
	EXPECT_EQ(i,-1);
	// check the position of the data, nothing should have changed
	EXPECT_STREQ(head->data, str);
	EXPECT_STREQ(head->next->data, str1);
	EXPECT_STREQ(head->next->next->data, str2);
	EXPECT_STREQ(head->next->next->next->data, str3);
	EXPECT_STREQ(head->next->next->next->next->data, str4);

	// same test parameter swap

	// call swap_items
	i = swap_items(head->next->next->next->next->next, head->next);
	// check the return value
	EXPECT_EQ(i,-1);
	// check the position of the data, nothing should have changed
	EXPECT_STREQ(head->data, str);
	EXPECT_STREQ(head->next->data, str1);
	EXPECT_STREQ(head->next->next->data, str2);
	EXPECT_STREQ(head->next->next->next->data, str3);
	EXPECT_STREQ(head->next->next->next->next->data, str4);


}
/*-------------------------------------------------------------------------*/


/***************************************************************************/


/***************************************************************************/
/*                 Test for sort_list                                      */
/***************************************************************************/
// test sort_list without expecting errors
TEST(sort_list_test,test_normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	i = sort_list(head);
	// check if i euqals 0 ok
	EXPECT_EQ(i, 0);	
	EXPECT_STREQ(head->data, str2);	
	EXPECT_STREQ(head->next->data, str);	
	EXPECT_STREQ(head->next->next->data, str3);	
	EXPECT_STREQ(head->next->next->next->data, str4);	
	EXPECT_STREQ(head->next->next->next->next->data, str1);	

}

TEST(sort_list_test,test_nullpointer)
{
	int i;

	linked_list *head = NULL;

	i = sort_list(head);

	// check if i euqals -1 error	
	EXPECT_EQ(i, -1);	

}

/***************************************************************************/


/***************************************************************************/
/*                 Test for linkedlist_status                              */
/***************************************************************************/
// test linkedlist_status without expecting errors
TEST(linkedlist_status_test,test_normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->index=0;
	head->data=str;
	head->next=(struct linked_list*) malloc(sizeof(linked_list));

	head->next->index=1;
	head->next->data=str1;
	head->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->index=2;
	head->next->next->data=str2;
	head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->index=3;
	head->next->next->next->data=str3;
	head->next->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));

	head->next->next->next->next->index=4;
	head->next->next->next->next->data=str4;
	head->next->next->next->next->next = NULL;

	// check status
	i = linkedlist_status(head);

	// we expect 5 
	EXPECT_EQ(i , 5);
}

// test linkedlist_status in case of a nullpointer
TEST(linkedlist_status_test,test_nullpointer)
{
	int i;

	linked_list *head = NULL;

	// check status
	i = linkedlist_status(head);

	// we expect an error so -1 
	EXPECT_EQ(i , -1);
}


/***************************************************************************/



/***************************************************************************/
/*                 Test for combined functions                             */
/***************************************************************************/


TEST(combination_test,display_list_add_to_list_test)
{
	int result;
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *find;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	EXPECT_EQ(head->next->index,1);
	EXPECT_EQ(i,1);
	EXPECT_STREQ(head->next->data,str1);

	i=add_to_list(head,str2);
	display_list(head);
	EXPECT_EQ(head->next->next->index,2);
	EXPECT_EQ(i,2); // should be 2 i think
	EXPECT_STREQ(head->next->next->data,str2);

	i=add_to_list(head,str3);
	display_list(head);
	EXPECT_EQ(head->next->next->next->index,3);
	EXPECT_EQ(i,3);
	EXPECT_STREQ(head->next->next->next->data,str3);

	i=add_to_list(head,str4);
	display_list(head);
	EXPECT_EQ(head->next->next->next->next->index,4);
	EXPECT_EQ(i,4);
	EXPECT_STREQ(head->next->next->next->next->data,str4);

	i=add_to_list(head,str5);
	display_list(head);
	EXPECT_EQ(head->next->next->next->next->next->index,5);
	EXPECT_EQ(i,5);
	EXPECT_STREQ(head->next->next->next->next->next->data,str5);

	i=add_to_list(head,str6);
	display_list(head);
	EXPECT_EQ(head->next->next->next->next->next->next->index,6);
	EXPECT_EQ(i,6);
	EXPECT_STREQ(head->next->next->next->next->next->next->data,str6);

}
