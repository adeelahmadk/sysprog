/* Trivial file copy program using low-level I/O */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fd, size, count, i; /* Input and output handles */
  char *buffer;

  if (argc != 3)
  {
    printf("usage: %s blocksize blockcount\n", argv[0]);
    exit(1);
  }

  if ((fd = open("rawio.out", O_WRONLY | O_CREAT | O_TRUNC, 0600)) < 0) {
    perror("rawio.out");
    exit(2);
  }

  size = atoi(argv[1]);
  count = atoi(argv[2]);

  buffer = malloc(size);

  for (i = 0; i < count; ++i)
  {
    write(fd, buffer, size);
  }

  free(buffer);
  close(fd);
}
