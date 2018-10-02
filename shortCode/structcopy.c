#include <stdio.h>


struct data{ 
	int a;
	float b;
	char s[10];
};

void struct_copy(struct data* a, struct data *b)
{
	b->a = a->a;
	b->b = a->b;
	int i;
	for(i =0; a->s[i] != '\0'; i++)
	{
		b->s[i] = a->s[i];
	}
	b->s[i] = '\0';
}



int main ()
{

	struct data a={200,3.2,{"JabaDaBaba"}};
	struct data b;
	struct_copy(&a,&b);
	printf("%d %.2f %s\n", b.a, b.b, b.s);



	return 0;
}
