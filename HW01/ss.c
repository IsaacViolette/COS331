#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char *buf[argc];
	
	for(int i = 0; i < argc; i++)
	{
		buf[i] = argv[i];
	}	

	printf("I was called with these parameters: ");
	for(int i = 0; i < argc; i++)
		printf("%s ", buf[i]);
	printf("\n");
}
