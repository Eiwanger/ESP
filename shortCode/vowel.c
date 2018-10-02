#include <stdio.h>


int vowel(char letter)
{
	char* vowel ={" a, e, i, u, o, y, A, E, I, O, U, Y,"};
	char* cons = {" b, B, c, C, d, D, f, F, g, G, h, H, j, J, k, K, l, L, m, M, n, N, p, P, q, Q, r, R, s, S, t, T, v, V, w, W, x, X, z, Z,"};

	int i;
	for(i = 0; vowel[i] != '\0'; i++)
	{
		if(letter == vowel[i])
		{
		return 1;
		}
	}
	for(i = 0; cons[i] != '\0'; i++)
	{
		if(letter == cons[i])
		{
			return 0;
		}
	}

	return -1;
}


int main(){
char a ='A';
char b ='b';
char e ='e';
char z ='Z';
char x ='+';
char y ='Y';

printf("%d\n", vowel(a));
printf("%d\n", vowel(b));
printf("%d\n", vowel(e));
printf("%d\n", vowel(z));
printf("%d\n", vowel(x));
printf("%d\n", vowel(y));


return 0;
}
