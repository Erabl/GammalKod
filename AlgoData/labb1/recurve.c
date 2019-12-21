// README
// Author: Erik Blondell
// Generated: 2019-09-03
// Last updated: 2019-09-03
//
// Recursive String Revesal:
// Reverses the order inputted characters using the ADT stack
// based on the Java string. This is achieved with recursion.
//
// Usage:
// Excecuted through terminal.
// Takes an amount of user's choice of characters and outputs
// them in reverse order.
// Stops after new line is read.


#include<stdio.h>
// recurve takes in a char checks if it is a new line and calls on itslef delaying the putchar and then when the line has been found the program puts the chars
void recurve(){
  char t = getchar();
  if (t != '\n'){
    recurve();
    putchar(t);
  }
}
int main(){
  recurve(),
  putchar('\n');
}
