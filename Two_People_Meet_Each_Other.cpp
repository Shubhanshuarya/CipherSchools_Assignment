#include<iostream>
using namespace std;

bool AreTheyMeet(int x1, int v1, int x2, int v2){
    // 1. If X1 > X2 && V1 >= V2 => return false
    // If the first person is starting ahead of the second person, and his speed is also greater than the second one
    // So, they will never meet.

    if(x1 > x2 && v1 >= v2){
        return false;
    }

    // 2. If x2 > x1 && v2 >= v1 => return false
    // If the second person is starting ahead of the first person, and his speed is also greater than the first one
    // so, they will never meet

    if(x2 > x1 && v2 >= v1){
        return false;
    }

    // We are assuming our x1 is always greater than x2
    // so, if it is less than x2, then we have to swap it's value

    if(x1 < x2){
        swap(x1, x2);
        swap(v1, v2);
    }

    while( x1 >= x2){
        if(x1 == x2){
            return true;
        }

        // first person jumps one time at each iteration
        x1 = x1 + v1;

        // second person jumps one time at each iteration
        x2 = x2 + v2;
    }

    return false;

}

int main(){
    int x1 =6, v1 = 6, x2 = 4, v2 = 8;
    if(AreTheyMeet(x1, v1, x2, v2)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}