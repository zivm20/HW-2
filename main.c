#include <stdio.h>
#include "my_mat.h"
int main(){

  int arr[N*N];
  int mat[N][N];
  char functionType;
  int first_print = true;
  while(functionType != "D"){
    scanf("%c",&functionType);
    if(functionType == "A"){
      for(int i=0; i<N*N;i++){
        scanf("%d",&arr[i]);
      }
      function_A(arr,mat);
    }

    else if(functionType == "B" || functionType=="C"){
      if(firstPrint == true){
        firstPrint = false;
      }
      else{
        printf("\n");
      }
      int src;
      int dest;
      scanf("%d",&src);
      scanf("%d",&dest);
      if(functionType == "B"){
        function_B(mat[N][N]);
      }
      else{
        printf("%d",function_C);
      }
    }

  }
  //printf("\n\n\n");
  //printArr(mat);
  //printf("\n\n\n");

  //scanf("%d",&src);
  //scanf("%d",&dest);

  return 0;
}
