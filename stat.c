#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

char * permissify(int octal, char dest[]){  
  char * p = dest;
  char letters[9] = "rwxrwxrwx";
  int i = 0;
  while(octal){
    if(octal % 2){
      dest[8 - i] = letters[8 - i];
    }
    else{
      dest[8 - i] = '-';
    }
    i++;
    octal /= 2;   
  }
  return p;
}



int main(){
  int file = open("file.txt", O_RDWR | O_CREAT, 0777);
  write(file,"Hello\nBaka\n",11);
  struct stat p;
  stat("file.txt",&p);
  printf("size: %ld\n", p.st_size);
  printf("mode: %d\n", p.st_mode);
  printf("permissions in octal: %o\n", (int)(p.st_mode)%512);
  char s[9];
  printf("permissions: %s\n", permissify((p.st_mode)%512, s));
  printf("time: %s", ctime(&p.st_atime)); 
  printf("size in bytes: %ld\n", p.st_size);
  printf("size in kilobytes: %lf\n", (float)p.st_size/1000);
  printf("size in megabytes: %lf\n", (float)p.st_size/1000000);
  printf("size in gigabytes: %lf\n", (float)p.st_size/1000000000);
  close(file);
  return 0;
}
