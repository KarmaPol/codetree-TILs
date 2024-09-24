#include <iostream>
using namespace std;

int n, t;

int triangle[3][205];
int prevNum[3];

int main() {
    cin >> n >> t;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> triangle[i][j];
        }
    }

    for(int round = 0; round < t; round++) {
        for(int i = 0; i < 3; i++) {
            prevNum[i] = triangle[i][n-1];
            for(int j = n-1; j > 0; j--) {
                triangle[i][j] = triangle[i][j-1];
            }
        }

        for(int i = 0; i < 3; i++) {
            triangle[(i+1)%3][0] = prevNum[i];
        }
    }

    for(int i = 0; i < 3 ; i++) {
        for(int j = 0; j < n; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}