/* Example of lseek */

#include <unistd.h>
#include <fcntl.h>

struct record {
    int id;
    char name[80];
};

void main()
{
    int fd, size = sizeof(struct record), i;
    struct record info[4] = {{1,"John"}, {2,"Jack"}, {3,"Jane"}, {4,"Ben"}};

    fd = open("datafile", O_RDWR | O_CREAT | O_TRUNC, 0664); /* Open for read/write */

    //lseek(fd, 0, SEEK_END); /* Append */
	for(i=0; i<4; i++)
    	write(fd, &info[i], size); /* Write records */

    close(fd);
}
