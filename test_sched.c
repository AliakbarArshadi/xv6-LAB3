// // // #include "types.h"
// // // #include "stat.h"
// // // #include "user.h"

// // // int main(int argc, char *argv[])
// // // {
// // //   int pid;
// // //   int k, n;
// // //   long long int x, z;

// // //   printf(1, "Starting E-core Scheduling Test...\n");

// // //   for(k = 0; k < 7; k++){
// // //     pid = fork();
// // //     if(pid < 0){
// // //       printf(1, "fork failed\n");
// // //       exit();
// // //     }
    
// // //     if(pid == 0){  
// // //       for(z = 0; z < 1000000000000; z+=1){
// // //           x = x + 3.14 * 89.64; 
// // //       }
// // //       exit(); 
// // //     }
// // //   }

// // //   for(n = 0; n < 2; n++){
// // //     wait();
// // //   }
  
// // //   printf(1, "Test finished.\n");
// // //   exit();
// // // }
// // #include "types.h"
// // #include "stat.h"
// // #include "user.h"

// // int main(int argc, char *argv[])
// // {
// //   int pid;
// //   int k, n;
// //   int x, z;

// //   // 1. Start Measurement
// //   start_measure();

// //   printf(1, "Starting Benchmark...\n");

// //   for(k = 0; k < 10; k++){ // Create 10 processes
// //     pid = fork();
// //     if(pid < 0){
// //       exit();
// //     }
    
// //     if(pid == 0){ // Child
// //       // 2. Print Info for one of them (e.g., the 5th child)
// //       if(k == 5) print_info();
      
// //       // Heavy work
// //       for(z = 0; z < 10000000; z+=1){
// //           x = x + 3.14 * 89.64;
// //       }
// //       exit();
// //     }
// //   }

// //   // Parent waits
// //   for(n = 0; n < 10; n++){
// //     wait();
// //   }
  
// //   // 3. End Measurement
// //   end_measure();
  
// //   exit();
// // }
// #include "types.h"
// #include "stat.h"
// #include "user.h"

// int main(int argc, char *argv[])
// {
//   int pid;
//   int k, n;
//   volatile int x = 0; // 'volatile' ensures the compiler doesn't optimize the loop away
//   int z;

//   // 1. Start Measurement
//   start_measure();

//   printf(1, "Starting Benchmark...\n");

//   for(k = 0; k < 10; k++){ // Create 10 processes
//     pid = fork();
//     if(pid < 0){
//       exit();
//     }
    
//     if(pid == 0){ // Child
//       // Print info for the 5th child to verify
//       if(k == 5) print_info();
      
//       // Heavy work loop (Integer math only!)
//       // 500 million iterations fits in a standard 32-bit int
//       for(z = 0; z < 500000000; z++){
//           x = x + 1; // Simple integer addition
          
//           // Print rarely to check if we are still running
//           // Using 50 million ensures we don't spam the console too much
//           if(z % 50000000 == 0)
//              printf(1, "Child %d is running on CPU\n", getpid());
//       }
//       exit();
//     }
//   }

//   // Parent waits for all children
//   for(n = 0; n < 10; n++){
//     wait();
//   }
  
//   // 3. End Measurement
//   end_measure();
  
//   exit();
// }
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