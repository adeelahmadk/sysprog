/* Populate a file with records */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

struct record {
	int id;
	char name[80];
};

int main()
{
	int fd, size = sizeof(struct record), i;
	struct record info[4] = {{1,"John"}, {2,"Jack"}, {3,"Jane"}, {4,"Ben"}};

	if((fd = open("datafile", O_RDWR | O_CREAT | O_TRUNC, 0664)) < 0) {/* Open for read/write */
		perror("datafile");
		exit(2);
	}

	for(i=0; i<4; i++)
		write(fd, &info[i], size); /* Write records */

	close(fd);
	return 0;
}
