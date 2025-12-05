#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int pid;
  int k, n;
  int x, z;

  printf(1, "Starting E-core Scheduling Test...\n");

  for(k = 0; k < 2; k++){
    pid = fork();
    if(pid < 0){
      printf(1, "fork failed\n");
      exit();
    }
    
    if(pid == 0){  
      for(z = 0; z < 100000000; z+=1){
          x = x + 3.14 * 89.64; 
      }
      exit(); 
    }
  }

  for(n = 0; n < 2; n++){
    wait();
  }
  
  printf(1, "Test finished.\n");
  exit();
}