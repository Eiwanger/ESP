#include <gtest/gtest.h>
#include "linked_list.h"


// This is the implemention of the basic functions
// the parameter is always the head of the linked list

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

	// create a head and then add strings to the list
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL; 
	head->data=str; 
	head->index=0;
	// check the return value of the add_to_list function
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

// test the display_item function, the return value is 0
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
// test return value 0 of a listelement in the middle of a list
TEST(display_item_test, test_return_value)
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

	// try to delete an invalid index
	i = delete_from_list(head, -1);
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

	EXPECT_EQ(i,1);
	// delete the head, it should throw an error so we expect -1 
	i = delete_from_list(head, 0);	
	EXPECT_EQ(i,-1);

}
/***************************************************************************/


/***************************************************************************/
/*                 Test for combined functions                             */
/***************************************************************************/

// test the implemention of two functions display_list and add_to_list
TEST(combination_test,DISABLED_display_list_add_to_list_test)
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
/***************************************************************************/
