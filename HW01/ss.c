#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char *buf[argc];
	int ret;

	if(argc > 5)
	{
		printf("Too many command line arguments\n");
		return 0;
	}
		
	for(int i = 0; i < argc - 1; i++)
	{
		buf[i] = argv[i+1];
	}	

	buf[argc-1] = NULL;

	printf("I was called with these parameters: ");
	for(int i = 0; i < argc; i++)
		printf("%s ", argv[i]);
	printf("\n");

	ret = fork();

	if(ret == 0) //child process
	{
		printf("Child: after fork\n");
		printf("I am calling execv with parameters :");
		for(int i = 0; i < argc-1; i++)
			printf("%s ", buf[i]);
		printf("\n");

		execv(buf[0],buf);
	}

	else //parent process
	{
		printf("Waiting on child process with pid = %d to complete\n", ret);
		wait(NULL);
		printf("Bye from parent\n");
	}

}
