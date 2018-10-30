#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
  int file = open("file.txt", O_RDWR | O_CREAT, 0777);
  struct stat *p = (struct stat *)malloc(10);
  stat();
  close(file);
  return 0;
}
