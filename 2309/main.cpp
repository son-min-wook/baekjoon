#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}
void sort(int*);
int main()
{
	int i = 0,j=0,sum=0,fake1=0,fake2=0;
	int dwaf[9],sorted[9];
	for (i = 0; i < 9; i++) {
		scanf("%d", &dwaf[i]);
		sum = sum + dwaf[i];
	}
	sort(dwaf);
	sum = sum - 100;
	for (i = 0; i<8; i++){
		for (j = i+1; j<9; j++)
		{
			if (dwaf[i] + dwaf[j] == sum) {
				fake1 = i, fake2 = j;
				break;
			}
		}
	}
	for (i = 0; i<9; i++){
		if(i != fake1 && i != fake2)
		   printf("%d\n", dwaf[i]);
	}

}
void sort(int* dwaf)
{
	int i, j;
	for (i = 0; i<9; i++)
	{
		for (j = i; j<9; j++)
		{
			if (dwaf[i]>dwaf[j])
				SWAP(dwaf[i], dwaf[j]);
		}
	}
}