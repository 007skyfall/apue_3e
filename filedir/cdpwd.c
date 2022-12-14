#include "apue.h"

int main(int argc, const char *argv[])
{
	char *ptr = NULL;
	size_t size = 0;

	if (chdir("/usr") < 0)
	{
		err_sys("chdir failed");
	}

	ptr = path_alloc(&size); /* our own function */
	if (getcwd(ptr, size) == NULL)
	{
		err_sys("getcwd failed");
	}

	printf("cwd = %s\n", ptr);

	exit(0);
}
