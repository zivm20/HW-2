#include <stdio.h>
#include "my_mat.h"
void function_A(int arr[N*N],int mat[N][N]){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      mat[i][j] = arr[i*N+j];
    }
  }
}





void printArr(int mat[N][N]){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      printf("%d ",mat[i][j]) ;
    }
    printf("\n");
  }
}
