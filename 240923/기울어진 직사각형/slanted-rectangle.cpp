#include <iostream>
using namespace std;

int n;

int map[105][105];

int getSquareSum(int firstY, int firstX, int secondY, int secondX, int thirdY, int thirdX, int fourthY, int fourthX) {
    int sum = 0;

    int y = firstY, x = firstX;
    while(y < secondY && x < secondX) {
        sum += map[y][x];

        y++; x++;
    }

    while(y > thirdY && x < thirdX) {
        sum += map[y][x];

        y--; x++;
    }

    while(y > fourthY && x > fourthX) {
        sum += map[y][x];

        y--; x--;
    }

    while(y < firstY && x > firstX) {
        sum += map[y][x];

        y++; x--;
    }

    return sum;
}

int main() {
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int maxSum = -2e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int firstY = i, firstX = j;
            for(int d1 = 1; d1 < n; d1++) {
                if(firstY + d1 > n-1 || firstX +d1 > n-1) continue;
                int secondY = firstY + d1, secondX = firstX +d1;
                for(int d2 = 1; d2 <= n-d1; d2++) {
                    if(secondY - d2 < 0 || secondX + d2 > n-1) continue;
                    int thirdY = secondY - d2, thirdX = secondX + d2;
                    int fourthY = thirdY - d1, fourthX = thirdX - d1;
                    if(fourthY < 0 || fourthX < 0) continue;
                    // cout << firstY << " " << firstX << " " << secondY << " " <<  secondX << " " << thirdY << " " << thirdX << " " << fourthY << " "<< fourthX << '\n';
                    // cout << getSquareSum(firstY, firstX, secondY, secondX, thirdY, thirdX, fourthY, fourthX) << '\n';
                    maxSum = max(maxSum, getSquareSum(firstY, firstX, secondY, secondX, thirdY, thirdX, fourthY, fourthX));
                }
            }
        }
    }

    cout << maxSum;

    return 0;
}