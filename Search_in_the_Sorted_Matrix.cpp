// Search in a row wise and column wise sorted matrix
#include<iostream>
using namespace std;

// Search the element x in mat[][], if the element is found, then prints its position and returns 
// true, otherwise prints "Not Found" and return retunr false
int search(int mat[4][4], int n, int x){

    //if size of matrix becomes zero then return -1
    if(n == 0){
        return -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == x){
                cout << "Element found at (" << i  << ", " << j << ")";
                return 1;
            }
        }
    }

    cout << "Element not found";
    return 0;

}

int main(){
    int mat[4][4] = { { 10, 20, 30, 40 },
                        { 15, 25, 35, 45 },
                        { 27, 29, 37, 48 },
                        { 32, 33, 39, 50 } };
                    
    search(mat, 4, 29);
    return 0;
}