#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
  int file = open("file.txt", O_RDWR | O_CREAT, 0777);
  struct stat p;
  stat("file.txt",&p);
  close(file);
  return 0;
}
