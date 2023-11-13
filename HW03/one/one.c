#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("Must enter number of threads\n");
		exit(0);
	}
	if(atoi(argv[1]) < 1)
	{
		printf("Must enter a number greater than 0\n");
		exit(0);
	}
	
	int ran_arr[1024][1024];
	int tot_ran_dig[] = {0,0,0,0,0,0,0,0,0,0};
	int num_threads = atoi(argv[1]);

	srand(8);

	for(int i = 0; i < 1024; i++)
	{
		for(int j = 0; j < 1024; j++)
		{
			ran_arr[i][j] = (rand() % 10);
		}
	}


}
