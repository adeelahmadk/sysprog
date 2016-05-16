#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

struct record {
  int id;
  char name[80];
};

int main()
{
  int fd;
  size_t size;
  struct record *records;

  fd = open("datafile1", O_RDWR);
  size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);
  records = (struct record *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  records[1].id = 111;

  // msync(records, size, MS_SYNC);
  if (msync(records, size, MS_SYNC) == -1) {
      perror("msync");
      exit(5);
  }
  close(fd);
}
