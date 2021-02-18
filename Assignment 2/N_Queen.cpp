#define N 4
#include<iostream>
using namespace std;

bool safePlaceQueen(int mat[N][N], int row, int col){

    int i, j;

    // Left Side
    for(i = 0; i < col; i++){
        if(mat[row][i]){
            return false;
        }
    }

    // Upper Diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(mat[i][j]){
            return false;
        }
    }

    // lower diagonal
    for(i = row, j = col; j >= 0 && i < N; i++, j--){
        if(mat[i][j]){
            return false;
        }
    }

    // If all false then we will return true
    return true;

}

bool checkProblem(int mat[N][N], int col){

    if(col >= N){
        return true;
    }


    for(int i = 0; i < N; i++){
        if(safePlaceQueen(mat, i, col)){
            mat[i][col] = 1;
        }

        if(checkProblem(mat, col + 1)){
            return true;
        }

        // Let us suppose if our solution is not correct, then we will backtrack the path
        mat[i][col] = 0;
    }

    return false;

}

void printMat(int mat[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; i < N; j++){
            cout << " " << mat[i][j] << " ";
        }
    }
}

int main(){
    int mat[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
                    
    
    if(checkProblem(mat, 0) == true){
        printMat(mat);
    }else{
        cout << "Solution Doesn't Exist";
    }

    return 0;
}