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
		argi = 0;
		for(int i = 0; i < 5; i++)
		{
			argvec[i] = NULL;
		}

		printf("$$ ");
		fflush(stdout);

		ret = read(0, buf, 80);
		
		argvec[argi] = buf;
		argi++;

		for(int i = 0; i < ret; i++)
		{
			/*
			if(argi > 4)
			{
				printf("Too many parameters");
			}
			*/
			if(buf[i] == ' ')
			{
				buf[i] = '\0';
				argvec[argi] = &buf[i+1];
				argi++;
			}
			if(buf[i] == '\n')
			{
				buf[i] = '\0';
				break;
			}
		}
		argvec[argi] = NULL;
		
		ret = fork();

		if(ret == 0)//child
		{
			execv(argvec[0], argvec);
			printf("%s: No such file or directory \n", argvec[0]);
			return -1;
		}

		else //parent
		{
			wait(NULL);
		}
	}
}
