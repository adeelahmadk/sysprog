#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

struct record {
  int id;
  char name[80];
};

int main()
{
  int fd, numrec;
  size_t size;
  struct record *records;

  fd = open("datafile1", O_RDWR);
  if (fd < 0) {
    perror("datafile1");
    exit(1);
  }

  size = lseek(fd, 0, SEEK_END);
  numrec = size / sizeof(struct record);
  printf("Reading %d bytes / %d records from file.\n", (int)size, numrec);
  lseek(fd, 0, SEEK_SET);

  records = (struct record *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (records == MAP_FAILED) {
      perror("mmap");
      exit(2);
  }

  printf("Updating current value of record[1] id: %d\n", records[1].id);
  records[1].id = 2;

  if (msync(records, size, MS_SYNC) == -1) {
      perror("msync");
      exit(5);
  }

  munmap(records, size);
  close(fd);

  return 0;
}
