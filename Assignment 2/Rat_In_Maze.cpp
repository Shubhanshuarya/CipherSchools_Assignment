#include<iostream>
#define N 5
using namespace std;

void printSolution(int mat[N][N]){
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++){
          cout << " " << mat[i][j] << " ";
      }
      cout << "\n";
    }
}

bool isOkaytoPlace(int mat[N][N], int i, int j){
    if(i >= 0 && i < N && j >= 0 && j < N && mat[i][j] == 1){
        return true;
    }else{
        return false;
    }
}

bool isSafeToPlace(int mat[N][N], int i, int j){

    if(i == N-1 && j == N-1){
        mat[i][j] = 1;
        return true;
    }

    if(isOkaytoPlace(mat, i, j) == true){
        mat[i][j] = 1;
        if(isSafeToPlace(mat, i+1, j) == true){
            return true;
        }
        if(isSafeToPlace(mat, i, j+1) == true){
            return true;
        }
        mat[i][j] = 0;
        return false;
    }
    return false;
}


int main(){

    int mat[N][N]  =  {
                            {1, 0, 0, 0, 0},
                            {1, 1, 0, 1, 0},
                            {0, 1, 1, 1, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 1, 1, 1}
                        };
    
    if(isSafeToPlace(mat, 0, 0) == true){
        printSolution(mat);
    }else{
        cout << "There is no Path";
    }
    return 0;
}