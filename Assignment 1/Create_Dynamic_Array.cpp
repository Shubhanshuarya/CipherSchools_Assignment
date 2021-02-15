#include<iostream>
using namespace std;

int main(){
    int i, n;
    cout << "enter total number of elements" << endl;
    cin >> n;
    int *a = new int(n);
    cout << "Enter " << n << " elements" << endl;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << "Entered Elements are: ";
    for(i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    // We have to delete it also
    delete(a);
    return 0;
}