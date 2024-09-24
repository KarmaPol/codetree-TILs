#include <iostream>
using namespace std;

int n, m, q;

int map[105][105];
int nextMap[105][105];

void moveMapLeft(int row) { // wind left
    int temp = map[row][m-1];
    for(int i = m-1; i > 0; i--) {
        map[row][i] = map[row][i-1];
    }
    map[row][0] = temp;
}

void moveMapRight(int row) { // wind right
    int temp = map[row][0];
    for(int i = 0; i < m-1; i++) {
        map[row][i] = map[row][i+1];
    }
    map[row][m-1] = temp;
}

int main() {
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        int row; string wind;
        cin >> row >> wind;

        if(wind == "L") {
            moveMapLeft(row-1);
            wind = "R";
        }
        else {
            moveMapRight(row-1);
            wind = "L";
        }

        int upperRow = row - 1; string upperWind = wind;
        int lowerRow = row + 1; string lowerWind = wind;

        while(upperRow >= 1) {
            bool isWindy = false;
            for(int j = 0; j < m; j++) {
                if(map[upperRow-1+1][j] == map[upperRow-1][j]) {
                    isWindy = true;
                    break;
                }
            }
            if(!isWindy) break;

            if(upperWind == "L") {
                moveMapLeft(upperRow-1);
                upperWind = "R";
            }
            else {
                moveMapRight(upperRow-1);
                upperWind = "L";
            }
            upperRow--;
        }

        while(lowerRow <= n) {
            bool isWindy = false;
            for(int j = 0; j < m; j++) {
                if(map[lowerRow-1 - 1][j] == map[lowerRow-1][j]) {
                    isWindy = true;
                    break;
                }
            }
            if(!isWindy) break;

            if(lowerWind == "L") {
                moveMapLeft(lowerRow-1);
                lowerWind = "R";
            }
            else {
                moveMapRight(lowerRow-1);
                lowerWind = "L";
            }
            lowerRow++;
        }
    }

    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}