#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ran_arr[1024][1024];
	int tot_ran_dig[10];

	srand(8);

	for(int i = 0; i <= 1024; i++)
	{
		for(int j = 0; j <= 1024; j++)
		{
			ran_arr[i][j] = (rand() % 10);
		}
	}
}
