#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char buf[80];
	int ret,argi = 0;
	char *argvec[5];

	while(1)
	{
		printf("$$ ");
		fflush(stdout);
		ret = read(0, buf, 80);
		
		for(int i = 0; i < ret; i++)
		{
			if(buf[i] == ' ' || buf[i] == '\n')
			{
				//maybe add error check if argi is greater than 4
				buf[i] = '\0';
				argvec[argi] = &buf[i+1];
				argi++;
			}
		}
		argvec[argi] = NULL;
		
		ret = fork();

		if(ret == 0)//child
		{
			execv(argvec[0], argvec);
			perror("Execv Error");
			return -1;
		}

		else
		{
			wait(NULL);
		}
	}
}
