#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  int file = open("file.txt", O_RDWR | O_CREAT, 0777);
  write(file,"Hello\nBaka\n",11);
  struct stat p;
  stat("file.txt",&p);
  printf("size: %ld\n", p.st_size);
  printf("mode: %d\n", p.st_mode);
  printf("time: %s\n", ctime(&p.st_atime)); // Set to correct format please
  printf("size in bytes: %ld\n", p.st_size);
  printf("size in kilobytes: %ld\n", p.st_size/1000);
  printf("size in megabytes: %ld\n", p.st_size/1000000);
  printf("size in gigabytes: %ld\n", p.st_size/1000000000);
  close(file);
  return 0;
}
