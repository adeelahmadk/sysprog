/* Buffered File I/O example */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *buffer;	/* Pointer to allocate dynamic buffer memory */
  int  size, count, i;
  FILE *fd;	/* File descriptor */

  if (argc != 3) {
  	printf("usage: %s blocksize blockcount\n", argv[0]);
  	exit(1);
  }

  if((fd = fopen("bufio.out", "w")) == NULL) {
		perror("bufio.out");
		exit(2);
	}

  size  = atoi(argv[1]);
  count = atoi(argv[2]);

  buffer = malloc(size);

  for (i=0; i<count; i++) {
   fwrite(buffer, size, 1, fd);
  }

  free(buffer);
  close(fd);

  return 0;
}
