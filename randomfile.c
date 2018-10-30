#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int randNum(){
  int randomData = open("/dev/urandom", O_RDONLY);
  int *num = malloc(sizeof(int));
  if (randomData < 0)
  {
        printf("Error:%s\n", strerror(errno));
  }
  else
  {
      read(randomData,num,1);
  }
  return *num;
}

int main(){
  int ary[10];
  printf("Generating Random Numbers:\n");
  for (int i = 0; i <10; i++){
    int num = randNum();
    ary[i]=num;
    printf("    Array[i] = %d\n",num);
  }

  printf("\n\n");
  printf("Writing numbers to file...\n\n");

  int fd = open("nums.txt",O_WRONLY | O_CREAT, 0640);
  write(fd,ary,10*sizeof(int));
  close(fd);

  printf("Reading numbers from file...\n\n");
  int newAry[10];// = malloc(10*sizeof(int));
  fd = open("nums.txt",O_RDONLY);
  read(fd,newAry,10*sizeof(int));
  close(fd);

  printf("Verification that written values were the same:\n");
  for (int i = 0; i <10; i++){
    printf("    NewArray[i] = %d\n",newAry[i]);
  }
  //free(newAry);
  return 0;
}
