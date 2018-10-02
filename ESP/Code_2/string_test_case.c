#include "string.h"
#include <gtest/gtest.h>
#include <stdlib.h>

TEST (my_strlen_test, test_null)
{
	char* s = NULL;
	EXPECT_EQ(-1, my_strlen(s));
}

TEST (my_strlen_test, test_norm)
{
	char s[] = "Hello World";
	EXPECT_EQ(11, my_strlen(s));
}

TEST (my_strlen_test, test_empty)
{
	char s[] = "";
	EXPECT_EQ(0, my_strlen(s));
}

TEST (my_strlen_test, test_special)
{
	char s[] = "0+-*&%$ _!";
	EXPECT_EQ(10, my_strlen(s));
}


TEST (str2upper_test, test_null)
{
	char* s = NULL;
	EXPECT_EQ(-1, str2upper(s));
}

TEST (str2upper_test, test_empty)
{
	char s[] = "";
	EXPECT_EQ(0, str2upper(s));
}

TEST (str2upper_test, test_norm)
{
	char s[] = "Hallo Welt";
	char e[] = "HALLO WELT";
	EXPECT_EQ(7, str2upper(s));
	EXPECT_STREQ(e, s);
}

TEST (str2upper_test, test_special)
{
	char s[] = "-hi+ ver?";
	char e[] = "-HI+ VER?";
	EXPECT_EQ(5, str2upper(s));
	EXPECT_STREQ(e, s);
}

TEST (str2upper_test, test_allUp)
{
	char s[] = "HELLO WORLD";
	char e[] = "HELLO WORLD";
	EXPECT_EQ(0, str2upper(s));
	EXPECT_STREQ(e, s);
}

TEST (str2lower_test, test_null)
{
	char* s = NULL;
	EXPECT_EQ(-1, str2lower_(s));
}

TEST (str2lower_test, test_empty)
{
	char s[] = "";
	EXPECT_EQ(0, str2lower_(s));
}

TEST (str2lower_test, test_norm)
{
	char s[] = "Hallo Welt";
	char e[] = "hallo welt";
	EXPECT_EQ(2, str2lower_(s));
	EXPECT_STREQ(e, s);
}

TEST (str2lower_test, test_special)
{
	char s[] = "-HI+ VER?";
	char e[] = "-hi+ ver?";
	EXPECT_EQ(5, str2lower_(s));
	EXPECT_STREQ(e, s);
}

TEST (str2lower_test, test_alllow)
{
	char s[] = "hello world";
	char e[] = "hello world";
	EXPECT_EQ(0, str2lower_(s));
	EXPECT_STREQ(e, s);
}

TEST (str_strip_numbers_test, test_null)
{
	// unsigned
	char* s = NULL;
	EXPECT_EQ(-1, str_strip_numbers(s));
}

TEST (str_strip_numbers_test, test_empty)
{
	// unsigned
	char s[] = "";
	EXPECT_EQ(0, str_strip_numbers(s));	
}

TEST (str_strip_numbers_test, test_norm)
{
	// unsigned
	char s[] = "1Hello234 World1";
	// unsigned
	char e[] = "Hello World";
	EXPECT_EQ(11, str_strip_numbers(s));
	EXPECT_STREQ(e, s);
}

TEST (str_strip_numbers_test, test_special)
{
	// unsigned
	char s[] = "1+Hello-?5";
	// unsigned
	char e[] = "+Hello-?";
	EXPECT_EQ(8, str_strip_numbers(s));
	EXPECT_STREQ(e, s);
}

TEST (mystrcpy_test, test_empty)
{
	char s[] = "";
	char d[] = "";

	mystrcpy(s, d);
	EXPECT_STREQ(s, d);
}

TEST (mystrcpy_test, test_norm)
{
	char s[] = "Hello";
	char d[5] = "";

	mystrcpy(s, d);
	EXPECT_STREQ(s, d);
}

TEST (mystrcpy_test, test_spec)
{
	char s[] = "H +l?!";
	char d[6] = "";

	mystrcpy(s, d);
	EXPECT_STREQ(s, d);
}

TEST (mystrcmp_test, test_null)
{
	char* s = NULL;
	char* d = NULL;

	EXPECT_EQ(0, mystrcmp(s, d));	
}

TEST (mystrcmp_test, test_empty)
{
	char s[] = "";
	char d[] = "";

	EXPECT_EQ(0, mystrcmp(s, d));	
}

TEST (mystrcmp_test, test_norm_zero)
{
	char s[] = "Hello World";
	char d[] = "Hello World";

	EXPECT_EQ(0, mystrcmp(s, d));	
}

TEST (mystrcmp_test, test_norm_four_neg)
{
	char s[] = "Hello World";
	char d[] = "Hellu World";

	EXPECT_EQ(-4, mystrcmp(s, d));	
}

TEST (mystrcmp_test, test_norm_four_pos)
{
	char s[] = "Hello World";
	char d[] = "Hella World";

	EXPECT_EQ(4, mystrcmp(s, d));	
}

TEST (mystrcmp_test, test_special_space)
{
	char s[] = "Hella World";
	char d[] = "Hell  ?%$ld";

	EXPECT_EQ(4, mystrcmp(s, d));	
}

TEST (mystrcmp_test, test_special)
{
	char s[] = "Hella World";
	char d[] = "Hell+ ?%$ld";

	EXPECT_EQ(4, mystrcmp(s, d));	
}

TEST (mystrcmp_test, test_diff_case_zero)
{
	char s[] = "HELLO WORLD";
	char d[] = "hello world";

	EXPECT_EQ(0, mystrcmp(s,d));
}

TEST (mystrcmp_test, test_diff_case_five)
{
	char s[] = "hello WORLD";
	char d[] = "hello world";

	EXPECT_EQ(-6, mystrcmp(s,d));
}

TEST (mystrcmp_test, test_diff_length)
{
	char s[] = "Hello World";
	char d[] = "Hello";
	EXPECT_EQ(5, mystrcmp(s,d)); 
}

TEST (mystrcmp_test, test_diff_length2)
{
	char s[] = "World of Warcraft";
	char d[] = "World of Warcraft - Battle of Azeroth";
	EXPECT_EQ(-17, mystrcmp(s,d)); 
}

TEST (strdupl_test, test_null)
{
	char* s = NULL;
	EXPECT_EQ(NULL, strdupl(s));
}

TEST (strdupl_test, test_empty)
{
	char s[] = "";
	char* c = strdupl(s);
	EXPECT_STREQ(s, c);
}

TEST (strdupl_test, test_norm)
{
	char s[] = "Hello World";
	char* c = strdupl(s);
	EXPECT_STREQ(s, c);
}

TEST (strdupl_test, test_special)
{
	char s[] = "!$%&(+-";
	char* c = strdupl(s);
	EXPECT_STREQ(s, c);
}

