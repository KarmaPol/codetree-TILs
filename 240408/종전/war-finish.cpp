#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25];
int border[25][25];

int n;
int diry[4] = {-1, -1, 1, 1};
int dirx[4] = {1, -1, -1, 1};

int answer = 2e9;

void resetborder() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            border[i][j] = 0;
        }
    }
}

void getBorder(int y, int x, int a, int b) {
    int delta[4] = {a, b, a, b};
    int nexty = y;
    int nextx = x;

    for(int d = 0; d < 4; d++) {
        for(int i = 0; i < delta[d]; i++) {
            nexty += diry[d];
            nextx += dirx[d];
            border[nexty][nextx] = 1;
        }
    }
}

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool isAvailable(int y, int x, int a, int b) {
    return inRange(y-a, x+a) && inRange(y-a-b, x+a-b) && inRange(y-b, x-b);
}

void getmaxdiff(int y, int x, int a, int b) {
    vector<int> tot(5);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tot[0] += map[i][j];
        }
    }
    // 좌 상단, 위쪽 꼭지점 포함, 왼쪽 꼭지점 미포함
    for(int i = 0; i < y - b; i++) {
        for(int j = 0; j <= x+a-b; j++) {
            if(border[i][j]) break;
            tot[1] += map[i][j];
        }
    }
    // 우 상단, 오른쪽 꼭지점 옆은 포함, 위쪽 꼭지점 위는 미포함
    for(int i = 0; i <= y -a ; i++) {
        for(int j = n-1; j > x+a-b; j--) {
            if(border[i][j]) break;
            tot[2] += map[i][j];
        }
    }
    // 좌 하단, 왼쪽 꼭지점 포함, 아래쪽 꼭지점 미포함
    for(int i = y-b; i < n; i++) {
        for(int j = 0; j < x; j++) {
            if(border[i][j]) break;
            tot[3] += map[i][j];
        }
    }
    // 우 하단, 아래쪽 꼭지점 포함, 오른쪽 꼭지점 미포함
    for(int i = y-a+1; i < n ; i++) {
        for(int j = n-1; j >= x; j--) {
            if(border[i][j]) break;
            tot[4] += map[i][j];
        }
    }

    tot[0] -= tot[4] + tot[1] + tot[2] +tot[3];
    sort(tot.begin(), tot.end());
    answer = min(tot[4] - tot[0], answer);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int a = 1; a < n; a++) {
                for(int b = 1; b < n; b++) {
                    resetborder();
                    if(!isAvailable(i, j, a, b)) continue;
                    getBorder(i, j, a, b);
                    getmaxdiff(i, j, a, b);
                }
            }
        }
    }

    cout << answer;

    return 0;
}