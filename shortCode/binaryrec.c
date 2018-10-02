#include <stdio.h>

void binary(int a)
{
	if(a <= 1){
		printf("%d",a);
	}
	else
	{

		binary(a/2);
		printf("%d",a%2);
	}
}




int main(){
	int end = 101; 

	for(int i = 0; i < end; i++ ){
		binary(i);
		printf("\n");
	}
	return 0;
}
