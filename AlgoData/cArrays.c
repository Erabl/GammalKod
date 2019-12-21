#include <stdio.h>



void search_a()
{
int nrElements;
scanf("%d",&nrElements);
int list [nrElements];
for(int i= 0; i<nrElements; i++){
  scanf("%d",&list[i]);
}
for(int i= 0; i<nrElements; i++){
printf("%d",list[nrElements-1-i]);
}
}

int main()
{
    search_a();
    return 0;
}
