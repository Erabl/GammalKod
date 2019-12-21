#include <stdio.h>
int kolumner = 0;


int is_prime(int n){
  int stop = 0;

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
int print_number(int n)
  {
     printf("%10d", n);
     kolumner ++;
     if (kolumner == 6)
      {
        printf("\n");
        kolumner = 0;
      }
      // return 0;
  }

  int test(){
  for (int i = 0; i<20; i++){
  print_number(i);
  }
  }

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
  test();
}
