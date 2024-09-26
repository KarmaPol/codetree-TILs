#include <iostream>
using namespace std;

int n, m, q;
int r1, c1, r2, c2;

int map[105][105];

void moveClock() {
    int tempMap[105][105];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tempMap[i][j] = map[i][j];
        }
    }

    for(int i = c2; i > c1; i--) {
        tempMap[r1][i] = map[r1][i-1];
    }

    for(int i = r2; i > r1; i--) {
        tempMap[i][c2] = map[i-1][c2];
    }
    
    for(int i = c1; i < c2; i++) {
        tempMap[r2][i] = map[r2][i+1];
    }

    for(int i = r1; i < r2; i++) {
        tempMap[i][c1] = map[i+1][c1];
    }   

    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            map[i][j] = tempMap[i][j];
        }
    }
}

void trasformAvg() {
    int tempMap[105][105];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tempMap[i][j] = map[i][j];
        }
    }
    
    int dy[5] = {0, 0, 1, 0, -1};
    int dx[5] = {0, 1, 0, -1, 0};

    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            int sum = 0, count = 0;
            for(int d = 0; d < 5; d++) {
                int nextY = i + dy[d];
                int nextX = j + dx[d];

                if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
                    continue;
                }

                sum += map[nextY][nextX]; count++;
            }
            tempMap[i][j] = sum/count;
        }
    }

    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            map[i][j] = tempMap[i][j];
        }
    }
}

void printMap() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; r2--; c1--; c2--;
        moveClock();
        trasformAvg();
    }

    printMap();

    return 0;
}