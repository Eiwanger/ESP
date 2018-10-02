#include <stdio.h>

void swapstr(char *s)
{
	int i = 0;
	int count = 0;
	char tmp;

	while(s[count] != '\0')
	{
		count++;
	}

	int j = count-1;
	for(i=0; i < count/2; i++)
	{
		tmp = s[j];
		*(s+j) = s[i];
		s[i] = tmp;
		j--;
	}
}

int main()
{

	char s[] = "Hallo Welt";
	swapstr(s);
	printf("%s\n", s);
	return 0;
}
