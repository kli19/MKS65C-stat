#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
  int file = open("file.txt", O_RDWR | O_CREAT, 0777);
  write(file,"Hello\nBaka\n",11);
  struct stat p;
  stat("file.txt",&p);
  printf("%ld\n", p.st_size);
  printf("%d\n", p.st_mode);
  printf("%ld\n", p.st_atime); // Set to correct format please
  printf("%ld\n", p.st_size);
  close(file);
  return 0;
}
