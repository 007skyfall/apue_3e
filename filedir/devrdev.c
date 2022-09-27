#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

#include "apue.h"

int main(int argc, const char *argv[])
{
	int i = 0;
	struct stat buf = {0};

	if(argc < 2)
	{
		fprintf(stderr,"Usage %s <file>\n", argv[0]);
		return -1;
	}
	
	for (i = 1; i < argc; i++)
	{
		printf("%s: ", argv[i]);
		if (stat(argv[i], &buf) < 0)
		{
			err_ret("stat error");
			continue;
		}

		printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));

		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		{
			printf(" (%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "character" : "block",
				   major(buf.st_rdev), minor(buf.st_rdev));
		}

		printf("\n");
	}

	exit(0);
}
