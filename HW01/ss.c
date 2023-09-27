#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char *buf[argc]; //array for child process
	int ret;

	/* Error checking for command line arguments, assinment asked for a maximum of 5 */
	if(argc > 5)
	{
		printf("Too many command line arguments\n");
		return -1;
	}
	
	/* Making new array for the child process, removing first argument from argv */	
	for(int i = 0; i < argc - 1; i++)
	{
		buf[i] = argv[i+1];
	}	

	/*NULL needed in last index for execv command */
	buf[argc-1] = NULL;
	
	/* Print all passed command line arguments */
	printf("I was called with these parameters: ");
	for(int i = 0; i < argc; i++)
		printf("%s ", argv[i]);
	printf("\n");

	/* Create child process */
	ret = fork();

	/* Child process calls execv to run passed program */
	if(ret == 0)
	{
		printf("Child: after fork\n");
		printf("I am calling execv with parameters :");
		for(int i = 0; i < argc-1; i++)
			printf("%s ", buf[i]);
		printf("\n");

		execv(buf[0],buf);
		perror("Execv Error");
		return -1;
	}
	
	/* After completion of the child process, parent process continues */
	else
	{
		printf("Waiting on child process with pid = %d to complete\n", ret);
		wait(NULL);
		printf("Bye from parent\n");
	}

}
