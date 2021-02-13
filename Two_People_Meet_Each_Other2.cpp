#include<iostream>
using namespace std;

bool AreTheyMeet(int x1, int v1, int x2, int v2){
    // 1. x1 > x2 && v1 >= v2
    // It means first person is starting ahead of the second person, and his speed is also greater than the second person
    // so, they will never meet

    if(x1 > x2 && v1 >= v2){
        return false;
    }

    // 2. x2 > x1 && v2 >= v1
    // It means second person is starting ahead of the first person, and his speed is also greater than the first person
    // so, they will never meet

    if(x2 > x1 && v2 >= v1){
        return false;
    }

    // Assuming or Making sure that our x1 is greater than x2
    if(x1 < x2){
        swap(x1, x2);
        swap(v1, v2);
    }

    // Now, Calculating the Relative Speed and Difference of the given distance (x1 - x2)
    // After Calculating both of them, divide them
    return ((x1 - x2) % (v1 - v2) == 0); 
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