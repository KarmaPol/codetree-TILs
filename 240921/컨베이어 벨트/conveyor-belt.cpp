#include <iostream>
using namespace std;

int n, t;
int numbers[2][205];

int main() {

    cin >> n >> t;

    for(int j = 0; j < n; j++) {
        cin >> numbers[0][j];
    }
    for(int j = n-1; j >= 0; j--) {
        cin >> numbers[1][j];
    }

    for(int time = 0; time < t; time++) {
        int temp1 = numbers[0][n-1];
        for(int i = n-1; i > 0; i--) {
            numbers[0][i] = numbers[0][i-1];
        }

        int temp2 = numbers[1][0];
        for(int i = 0; i < n-1; i++) {
            numbers[1][i] = numbers[1][i+1];
        }

        numbers[1][n-1] = temp1;
        numbers[0][0] = temp2;
    }

    for(int j = 0; j < n; j++) {
        cout << numbers[0][j] << ' ';
    }
    cout << '\n';
    for(int j = n-1; j >= 0; j--) {
        cout << numbers[1][j] << ' ';
    }
    cout << '\n';

    return 0;
}