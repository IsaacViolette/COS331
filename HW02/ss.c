#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char buf[80];
	char *ptr;
	int ret;

	while(1)
	{
		printf("$$ ");
		fflush(stdout);
		ret = read(0, buf, 80);
		printf("%s", buf);
	}
}
