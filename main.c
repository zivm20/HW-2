#include <stdio.h>
#include "my_mat.h"
int main(){
  
  int arr[N*N];
  for(int i=0; i<N*N;i++){
    scanf("%d",&arr[i]);
  }
  int mat[N][N];

  function_A(arr,mat);
  printArr(mat);


  return 0;
}
