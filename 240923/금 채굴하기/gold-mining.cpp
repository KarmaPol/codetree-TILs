#include <iostream>
using namespace std;

int n, m;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int map[25][25];
int visited[25][25];

bool isPossible(int k, int y, int x) {
    if(y + k > n-1 || y - k < 0 || x + k > n-1 || x - k < 0) return false;

    return true;
}

int dfs(int stage, int y, int x, int k) {
    if(k < stage) {
        return 0;
    }
    visited[y][x] = 1;

    int totalGold = 0;
    totalGold += map[y][x];

    for(int i = 0; i < 4; i++) {
        int nextY = y + dy[i], nextX = x + dx[i];
        if(visited[nextY][nextX]) continue;
        
        totalGold += dfs(stage + 1, nextY, nextX, k);
    }

    return totalGold;
}

void initVisited() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

int minePrice(int k) {
    return k*k + (k+1)*(k+1);
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int maxGoldCount = 0;
    for(int k = 0; k <= n/2; k++) {
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < n; x++) {
                if(!isPossible(k, y, x)) continue;
                initVisited();
                visited[y][x] = 1;
                int gold = dfs(0, y, x, k);
                
                if(gold * m >= minePrice(k)) {
                    maxGoldCount = max(maxGoldCount, gold);
                }
            }
        }
    }

    cout << maxGoldCount;

    return 0;
}