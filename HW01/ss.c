#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char *buf[argc];
	int ret;

	if(argc > 5)
	{
		printf("Too many command line arguments \n");
		return 0;
	}
		
	for(int i = 0; i < argc; i++)
	{
		buf[i] = argv[i];
	}	

	printf("I was called with these parameters: ");
	for(int i = 0; i < argc; i++)
		printf("%s ", buf[i]);
	printf("\n");

	ret = fork();

	if(ret == 0)
	{
		printf("Child: after fork\n");
		printf("I am calling execv with parameters:");
		for(int i = 0; i < argc-1; i++)
			printf("%s ", buf[i+1]);
		printf("\n");
	}

}
