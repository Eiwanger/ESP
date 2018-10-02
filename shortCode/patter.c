#include <stdio.h>



int find_string(char *s, char*a)
{
	// s ist der String
	// a ist das muster
	int pos = 0;
	int i = 0;
	int firstPos;
	while(s[pos] != '\0' && a[i] != '\0')
	{
		if(s[pos] == a[i])
		{ 
			firstPos = pos;
			i++;
			if(s[pos] != '\0'  && a[i] == '\0'){ return firstPos;}
			pos++;
			
			while(s[pos] != '\0' && a[i] != '\0')
			{
				if(s[pos] == a[i])
				{
					i++;	
					if(s[pos] != '\0'  && a[i] == '\0')
					{
						return firstPos;
					}else{


						pos++;
					}
				}else
				{
					break;
				}
			}
			i = 0;
		}else{
			pos++;
		}
	}
	return -1;
}




int main()
{
	char s1[] = "Schnapp";
	char a1[] = "ap";               //4
	char s2[] = "paar Wörter";
	char a2[] = "ar W";		//2
	char s3[] = "oh Schitt man";
	char a3[] = "tt";		//7
	char s4[] = "jaaaa";
	char a4[] = "aaa";		//1
	char s5[] = "Hallo Stef";		
	char a5[] = "st";		// geht nicht
	char s6[] = "bin beschäftig";
	char a6[] = "sch";		//6
	char s7[] = "lass mich verlieren";
	char a7[] = "+ver";		//9
	char s8[] = "ja meine Fresse";
	char a8[] = "Fresse";		//9
	char s9[] = "isISisissesso"; 
	char a9[] = "iss";		//6
	char s10[] = "+-?+012";
	char a10[] = "+0";		//3
	char s11[] = "tes\\$%a21Testest";
  	char a11[] = "test";		//12
	char s12[] = "tes\\\\$%a21Testest";
  	char a12[] = "\\";		//3
	char s13[] = "tes\\$%a21Testest";
  	char a13[] = "tes";		//0
	char s14[] = "aAbBcCdDeEfFgGhH";
  	char a14[] = "d";		//6





	printf("1: %d\n", find_string(s1,a1));
	printf("2: %d\n", find_string(s2,a2));
	printf("3: %d\n", find_string(s3,a3));
	printf("4: %d\n", find_string(s4,a4));
	printf("5: %d\n", find_string(s5,a5));
	printf("6: %d\n", find_string(s6,a6));
	printf("7: %d\n", find_string(s7,a7));
	printf("8: %d\n", find_string(s8,a8));
	printf("9: %d\n", find_string(s9,a9));
	printf("10: %d\n", find_string(s10,a10));
	printf("11: %d\n", find_string(s11,a11));
	printf("12: %d\n", find_string(s12,a12));
	printf("13: %d\n", find_string(s13,a13));
	printf("14: %d\n", find_string(s14,a14));



	return 0;
}
