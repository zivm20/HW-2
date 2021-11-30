#include <stdio.h>
#include "my_mat.h"
void function_A(int arr[N*N],int mat[N][N]){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      mat[i][j] = arr[i*N+j];
    }
  }
}

void function_B(int mat[N][N], int src, int dest){
  if(function_C(mat,src,dest) != -1){
    printf("True");
  }
  else{
    printf("False");
  }

}



int function_C(int mat[N][N], int src, int dest){
  if(src==dest){
    return -1;
  }
  int DPMatrix[N][N][N] = {0};
  //since our matix represents an undirected graph, then for all elements e(i,j) for indexs i,j
  //e(i,j) = e(j,i)
  //this is why we can only iterate over half of the matrix
  for(int node = 0; node < N; node++){

    //init half of the column node and half of the row node
    for(int i = 0; i<node; i++){
      if(node>0){
        DPMatrix[node][i][node] = DPMatrix[node-1][i][node];
      }
      else{
        DPMatrix[node][i][node] = mat[i][node];
      }
    }
    for(int j = node+1; j<N; j++){
      if(node>0){
        DPMatrix[node][node][j] = DPMatrix[node-1][node][j];
      }
      else{
        DPMatrix[node][node][j] = mat[node][j];
      }
    }


    for(int i = 0; i<N; i++){
      //no need to iterate over column node again
      if(i!=node){
        for(int j = i+1; j<N; j++){

          if(j!=node){
            //for each route e(i,j) we split into routes e(i,node) + e(node,j)
            //since we are only iterating over e(i,j) for all j>i and since e(i,j)=e(j,i)
            //we would like to find:
            //e(min(i,node), max(i,node)) + e(min(j,node), max(j,node))
            int half1;
            int half2;
            if(node > j){
              half1 =  DPMatrix[node][j][node];
            }
            else{
              half1 = DPMatrix[node][node][j];
            }
            if(i > node){
              half2 = DPMatrix[node][node][i];
            }
            else{
              half2 = DPMatrix[node][i][node];
            }
            //We must check if we have actually found a faster route by getting the fastest route
            //from our last matrix
            int lastBestRoute;
            if(node>0){
              lastBestRoute = DPMatrix[node-1][i][j];
            }
            else{
              lastBestRoute = mat[i][j];
            }
            //we will now store the faster route between the route that we found in the last matrix
            //and the combination of the 2 routes we got in this matrix
            int min_length;
            if(half1 == 0 || half2 == 0){
              min_length = lastBestRoute;
            }
            else if(lastBestRoute == 0){
              min_length = half1 + half2;
            }
            else{
              min_length = (half1+half2 < lastBestRoute) ? (half1+half2) : (lastBestRoute);
            }
            DPMatrix[node][i][j] = min_length;
          }
        }

      }
    }

  }
  int output = (src<dest) ? DPMatrix[N-1][src][dest] : DPMatrix[N-1][dest][src];
  if(output==0){
    return -1;
  }
  return output;
}


void printArr(int mat[N][N]){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      printf("%d ",mat[i][j]);
    }
    printf("\n");
  }
}
