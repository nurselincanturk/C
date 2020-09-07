#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

int main()
{
			
	
	

int hazne[10];
	

	for (int k = 0; k < 10; k++)
	{
		hazne[k] = 0;
		
	}
	
	int jeton;
	//char  a;
	
	printf("jeton sayisi:");
	scanf("%d", &jeton);
	
	
	for (int i = 1; i <= jeton; i++)
		{
		/*srand(time(NULL));*/
		int r = 1+rand() % 11;

		    getch();
			printf("\n%d. jetonu atmak icin herhangi bir tusa basiniz. ",i);
			
			printf("--->>>>  %d. hazneye dustu.. ",r);
			hazne[r - 1] += 1;
			
		}
	printf("\n");
	printf("\n");
	for (int j = 0; j < 10; j++)
	{
		
		printf("%d. haznede %d kadar\n", j + 1, hazne[j]);
	}printf("\n");

for (int i = 9; i>0; i--)
{
	printf("\n%d | ", i);
	for (int a = 0; a<10; a++)
	{
		if (hazne[a] >= i)
			printf(" 0  |");
		else
			printf("    |");

	}

}
printf("\n--+-----+----+----+----+----+----+----+----+----+----+\n     1    2    3    4    5    6    7    8    9    10 |\n\n");


}
