#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define true 1
//#define false 0
#define COLUMNS 6
int kolumner = 0;

int is_prime(int n)
    {
  int stop = 0;

for (int i = 2; i <= n/2; i++)
     {
   if (n % i==0)
      {
        stop =1;
        break;
      }
    if (stop==0)
       return 1;
    else
       return 0;
     }
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
  int print_sieves(int n)
  {
int* lista= malloc(sizeof(int)*(n-1));
//int lista [n-1];
for (int a=0; a<(n-1);a++)
{
  lista[a]=1;
}
for (int j = 0; (j*j)<=(n); j++)
{
  if (is_prime(j+2)==1)
  {
    for (int p= 0;((j+2)*(j+2))+(j+2)*p<=n; p++)
    {
      lista[((j+2)*(j+2))+(j+2)*p -2] = 0;
    }
  }
}
for (int i=0; i<n; i++)
{
      if (lista[i]==1)
      {
         print_number(i+2);
}
}
free(lista);
}
int main(int argc, char *argv[])
//stacken är statisk
//heapen är en långsam cesspit
{
      if(argc == 2)
        print_sieves(atoi(argv[1]));
      else
        printf("Please state an interger number.\n");
      return 0;
}
