/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*PROTOTYPES*/
void *count();

/*GLOBAL VARIABLES*/
int tot_ran_dig[] = {0,0,0,0,0,0,0,0,0,0};

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("Must enter number of threads\n");
		exit(0);
	}

	int num_threads = atoi(argv[1]);

	if(num_threads < 1)
	{
		printf("Must enter a number greater than 0\n");
		exit(0);
	}
	
	int ran_arr[1024][1024];
	pthread_t tid[num_threads];
	
	long seed = 8;
	srand((unsigned) seed); //required random number seed for homework
	
	/* Fill 2x2 Array with random numbers*/
	for(int i = 0; i < 1024; i++)
	{
		for(int j = 0; j < 1024; j++)
		{
			ran_arr[i][j] = (rand() % 10);
		}
	}

	int thread_parameters[num_threads][2];

	/* Create threads based on user input*/
	for(int i = 0; i < num_threads; i++)
	{
		thread_parameters[i][0] = i;
		thread_parameters[i][1] = num_threads;
		pthread_create(&tid[i], NULL, count,(void *) thread_parameters[i]);
	}
	
	/* Wait for thread termination */
	for(int i = 0; i < num_threads; i++)
	{
		pthread_join(tid[i], NULL);
	}

	/*	
	printf("Total Number of each digit\n");
	for(int i = 0; i < 10; i++)
	{
		printf("%d: %d",i, tot_ran_dig[i]);
	}
	*/

}

void *count(void *arg)
{
	int* parameters = (int*)arg;
	printf("Hello World! %d %d\n", parameters[0], parameters[1]);
}
