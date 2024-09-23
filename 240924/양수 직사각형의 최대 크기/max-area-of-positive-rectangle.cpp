#include <iostream>
#include <cmath>
using namespace std;

int n, m;

int map[25][25];

bool isAllPositive(int firstY, int firstX, int secondY, int secondX) {
    int lessY = min(firstY, secondY);
    int greaterY = max(firstY, secondY);

    int lessX = min(firstX, secondX);
    int greaterX = max(firstX, secondX);

    for(int i = lessY; i <= greaterY; i++) {
        for(int j = lessX; j <= greaterX; j++) {
            if(map[i][j] < 1) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    int maxSize = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int firstY = i, firstX = j;

            for(int p = 0; p < n; p++) {
                for(int q = 0; q < m; q++) {
                    int secondY = p, secondX = q;

                    if(firstY >= secondY || firstX >= secondX) continue;

                    if(!isAllPositive(firstY, firstX, secondY, secondX)) continue;
                    // cout << firstY << " " << firstX << " " << secondY << " " << secondX << '\n';
                    maxSize = max(maxSize, (secondY-firstY+1)*(secondX-firstX+1));
                }
            }
        }
    }

    cout << maxSize;

    return 0;
}