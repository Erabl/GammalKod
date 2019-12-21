#include <stdio.h>
//README

//AUTHOR: ERIK BLONDELL
//generated 2019-09-15
//based on selectionSort however it will only find negatives and swap them
//place the nagatives at the start of the array  and the positives at the endsre
//because the algorithm is based on selection sort we know that the memory complexity is O(1)
void Swap(int *xp, int *yp)
  {
      int temp = *xp;
      *xp = *yp;
      *yp = temp;
  }
void flytt(int list[], int n){   // uppg6. om  index  i-1 är positivt eller om i=n (där n är antalet element i arrayen) finns det inga negativa tal framför ett positivt tal
  for(int i = 0; i<n; i++){      // i arrayen annars kan det inte garanterat finnas för index i och frammåt
    printf("\n");
    for(int j = i+1; j<n; j++){
      if(list[j]< 0){
        if(i!=j){
          Swap(&list[i],&list[j]);
        }
      }
    }
  }
}
int main(){
//  int list[] = {1,-1,1,-1,1,-1,1,-1,1};
  int list[] = {1,3,4,2,-1,-3,-2,-4,5};
  flytt(list,9);
  for(int i= 0;i<9; i++){
     printf("%d ", list[i]);
  }
    printf("\n");

return 0;
}
