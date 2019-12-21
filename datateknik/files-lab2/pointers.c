


#include <stdio.h>
#include <stdlib.h>
int count = 0;
char* text1 = "This is a string.";
int list1[20];
char* text2 = "Yet another thing.";
int list2[20];

void copycodes1(char*text1,int list1[],int *count){
     int  rak=0;
     int i =0;
      //printf("test5 ");
   while(*(text1+rak) != 0){
  //    for (int i= 0; i<20;i++){
      //  printf("testII ");
    list1[i] =  *(text1 + rak);
     i++;
    *count= *count +1;
    rak++;
  }
}

  int work(){

  copycodes1(text1,list1,&count);
  copycodes1(text2,list2,&count);
//text1,list1,count
  return 0;
  }


void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n",
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));

}

int main(void){
    //  printf("test");
  work();
    //  printf("test2");

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
      //printf("test3");
}
