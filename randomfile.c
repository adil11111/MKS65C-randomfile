#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
  int randomData = open("/dev/urandom", O_RDONLY);
  if (randomData < 0)
  {
        printf("Error:%s\n", strerror(errno));
  }
  else
  {
      int *ary = malloc(10 * sizeof(int));
      int result = read(randomData,ary,10);
  }
  int n = rand();
  printf("Random Number:%d\n",n);
}
