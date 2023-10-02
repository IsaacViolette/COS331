#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char buf[80];
	char *ptr;
	int ret;
	char argvec;

	while(1)
	{
		printf("$$ ");
		fflush(stdout);
		ret = read(0, buf, 80);
		
		for(int i = 0; i < ret; i++)
		{
			if(buf[i] == ' ' || buf[i] == '\n')
				buf[i] = '\0';
		}

		printf("%s\n", buf);
		

	}
}
