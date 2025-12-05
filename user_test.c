#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int pid;
  int k, n;
  volatile int x = 0; 
  int z;

  // 1. Start Measurement
  start_measure();

  printf(1, "Starting Benchmark...\n");

  for(k = 0; k < 10; k++){ 
    pid = fork();
    if(pid < 0){
      exit();
    }
    
    if(pid == 0){ // Child
      // Print info for the 5th child to verify
      if(k == 5) print_info();
      
      // SAFE INTEGER LOOP
      // 100 million fits in 32-bit int. Run this 5 times if needed.
      for(z = 0; z < 100000000; z++){
          x = x + 1; 
      }
      exit();
    }
  }

  // Parent waits
  for(n = 0; n < 10; n++){
    wait();
  }
  
  // 3. End Measurement
  end_measure();
  exit();
}