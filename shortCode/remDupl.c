#include <stdio.h>


int remove_duplicate_array(int *a, int size)
{


	for(int i = 0; i < size; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			if(a[i] == a[j])
			{

				for(int k = j+1; k < size; k++)
				{
					a[k-1] = a[k];
				}
				j--;
				size--;

			}

		}
	}

	return size;
}


int main()
{
	int z[]={1,1,1,1,1,2,3,4,4,4,4};
	int y[]={1,1,1,1,1,1,1,1};
	int l=remove_duplicate_array(z,11);
	int k=remove_duplicate_array(y,8);

	printf("%d\n",l);
	for(int i=0; i<l; i++){
		printf("%d ",z[i]);
	}


	printf("\n");


	printf("%d\n",k);
	for(int i=0; i<k; i++){
		printf("%d ",y[i]);
	}
	printf("\n");

	return 0;
}
