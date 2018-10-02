#include <stdio.h>


int pal_check(unsigned int a)
{
	int z, reverse = 0;

	z = a;

	while (z != 0) {
		reverse = reverse * 10;
		reverse = reverse + z%10;
		z = z/10;
	}

	if (a == reverse)
		return 1;
	else
		return 0;

}

int main()
{
	unsigned int puffer[10] = {2002, 1001, 101, 110, 111, 22122, 15215, 15995, 000, 0};	

	for(int i = 0; i < 10; i++)
	{
		printf("Input: %d \n  Output: %d\n", puffer[i], pal_check(puffer[i]));
	}


	return 0;
}
