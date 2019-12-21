// README
// Author: Erik Blondell
// Generated: 2019-09-03
// Last updated: 2019-09-03
//
// Itterative String Revesal:
// Reverses the order inputted characters using the ADT stack
// based on the Java string. This is achieved using itteration.
//
// Usage:
// Excecuted through terminal.
// Takes an amount of user's choice of  6 characters and outputs
// them in reverse order.
// Stops after new line is read.


#include <stdio.h>
void search_a()
{
int nrElements=6;

char list [nrElements];  //skapa en tom array av angedd längd

for(int i= 0; i<nrElements; i++){    //fyll arrayn med grejor
    list[i]= getchar();
    //list[i] = nrElements;
}
for(int i= 0; i<nrElements; i++){
     putchar(list[nrElements-1-i]);   //printa arrayns rojerg
}
}
int main()
{
    search_a();
    return 0;
}
