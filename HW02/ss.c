#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char buf[80]; //input buffer
	int ret,argi,bg = 0;
	char *argvec[5]; //array of pointers for argv

	while(1)
	{
		fflush(stdout);
		argi = 0;
		bg = 0;

		/* Each argument in argvec is cleared for the next process */
		for(int i = 0; i < 5; i++)
		{
			argvec[i] = NULL;
		}

		printf("$$ "); //prompt
		fflush(stdout);

		ret = read(0, buf, 80); //read 80 bytes
		
		argvec[argi] = buf; //add first argument to first index of argvec
		argi++; //move to next index

		/* string parsing */
		for(int i = 0; i < ret; i++)
		{
			/* make sure & is not taken as argument, set flag for background process */
			if((buf[i+1] == '\n') && (buf[i] == '&'))
			{
				buf[i] = '\0';
				bg = 1;
			}

			/* Replace spaces with escape sequence */
			if(buf[i] == ' ')
			{
				buf[i] = '\0';
				argvec[argi] = &buf[i+1];
				argi++;
			}
			
			/* when user enters command, string parsing ends and escape sequence is added */
			if(buf[i] == '\n')
			{
				buf[i] = '\0';
				break;
			}
		}
		
		argvec[argi] = NULL; //The last index must hold NULL for execv
		
		printf("Parent calling fork\n");
		fflush(stdout);

		ret = fork();

		if(ret == 0)//child
		{
			
			printf("Execv is called with these parameters: \n");
			for(int i = 0; i < argi; i++)
				printf("argvec[%d]: %s \n",i, argvec[i]);
			printf("\n");
			fflush(stdout);

			execv(argvec[0], argvec);
			printf("%s: No such file or directory \n", argvec[0]);
			fflush(stdout);
			return -1;
		}

		else //parent
		{
			/* if no & was added, wait for child process to complete */
			if(!bg)
			{
				wait(NULL);
			}

			/* & was added as input, execute in the background and wait one second */
			else
			{
				printf("Program executed in the background\n");
				fflush(stdout);
				sleep(1);
			}
		}
	}
}
