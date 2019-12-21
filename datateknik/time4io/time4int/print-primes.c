/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int kolumner = 0;
int is_prime(int n){
  int stop = 0;
  if (n>=2){


for (int i = 2; i <= n/2; i++){
   if (n % i==0)
      {
        stop =1;
        break;
      }
    }
    if (stop==0)
       return 1;
    else
       return 0;
     }
     else
     return 0;

     }
     void print_number(int n)
       {
          printf("%10d", n);
          kolumner ++;
          if (kolumner == COLUMNS)
           {
             printf("\n");
             kolumner = 0;
           }
         }

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS

    for (int i=0; i<n;i++)
    {
      if (is_prime(i)==1){
        print_number(i);
      }

    }
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
////
