#include "string.h"
#include <stdlib.h>



// return length of a given string
int my_strlen(char *s)
{
	int length = -1;
	if(s == NULL)
	{
		return length;
	}
	else
	{
		length =0;
		int i;
		for(i = 0; s[i]!='\0'; i++)
		{
			length++;	
		}
	}

	return length;
}

// converts all character from a given string to upper case and returns the
// number of changed characters
int str2upper(char *s)
{
	int i;
	int count = 0;
	if(s == NULL)
	{
		return -1;
	}
	for(i = 0; s[i]!='\0'; i++)
	{
		if(s[i] > 96 && s[i] < 123)
		{
			s[i] -=32;
			count++;
		} 
	}
	return count;
}



// converts all character from a given string to lower case and returns the
// number of changed characters 
int str2lower_(char *s)
{
	int i;
	int count = 0;
	if(s == NULL)
	{
		return -1;
	}
	for(i = 0; s[i]!='\0'; i++)
	{
		if(s[i] > 64 && s[i] < 90)
		{
			s[i] +=32;
			count++;
		} 
	}
	return count;
}

// removes all numbers from a string and returns the new lenght of the string
int str_strip_numbers(char *s)
{
	int i, j, count = 0;
	if(s == NULL)
	{
		return -1;
	}

	for(i = 0; s[i] != '\0'; i++)
	{
		while ((s[i] >= 48 && s[i] <= 57))
		{
			for(j = i; s[j] != '\0'; ++j)
			{
				s[j] = s[j+1];
			}
			s[j] = '\0';

		}
	}
	while(s[count] != '\0')
	{
		count++;
	}
	return count;
}

// copy a given string to anther given string
void mystrcpy(char *s, char *d)
{
	int i;
	if(*s == '\0')
	{
		*d ='\0' ;
	}
	else
	{

		for(i = 0; s[i]!='\0'; i++)
		{
			d[i] = s[i];
		}
		d[i] = '\0';
	}
}

// compare to string together and return the place of the first
// different character. 0 if strings are equal
// -n if s is ordered before in alphabet than d
// n if d is ordered before s
int mystrcmp(char *s, char *d)
{
	int i, count_S, count_D;
	if(s == NULL || d == NULL)
	{
		return 0;
	}
	for(count_S = 0; s[count_S] != '\0'; count_S++);
	for(count_D = 0; d[count_D] != '\0'; count_D++); 

	i = 0;
	while(i != count_S && i != count_D)
	{
		if(s[i] < d[i])
			return -i;
		else if(s[i] > d[i]){
			return i;
		}
		i++;
		if(s[i] == '\0' && d[i] == '\0') 
		{
			return 0;
		}		
		if(s[i] == '\0')
		{
			return -i;
		}
		if(d[i] == '\0')
		{
			return i;
		}
	}
return 0;
}

// creates a duplicate of a given string and returns a pointer to 
// the new string
char* strdupl(char *s)
{
	int i = 0;
	if(s == NULL)
	{
		return NULL;
	}


	for(i = 0; s[i] != '\0'; i++){}

	char* c = (char*) malloc(sizeof(char)*(i+1));


	for(i = 0; s[i] != '\0'; i++){

		c[i] = s[i];
	}
	c[i] = '\0';

	return c;

}

