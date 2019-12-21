#include <stdio.h>
#include <ctype.h>
//README

//AUTHOR: ERIK BLONDELL
//generated 2019-09-22
//program using the isAlpha() function to accept a string and find any non alphabetic character this string contains
//replacing any and all non alphabetic characters with a blank
void findAlpha(){
  char c = getchar();
   while(c != EOF){
      if (isalpha(c)||(c == '\n')||(c==' ')){
        putchar(c);
      }
      else{
        putchar(' ');
      }
      c=getchar();
}
}
int main(){
findAlpha();
return 0;
}
