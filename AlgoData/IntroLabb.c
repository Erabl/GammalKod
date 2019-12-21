#include <stdio.h>



void search_a()
{
  char c = getchar();
   while(c != EOF){
      if (c == 'a'){
        putchar('X');
      }
      else{
        putchar(c);
      }
      c=getchar();
 }
}
int main()
{
    search_a();
    return 0;
}
