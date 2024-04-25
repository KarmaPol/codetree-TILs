#include <iostream>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int n;

int map[505][505];
int dp[505][505];

bool inRange(int y, int x) {
    return y >= 0 && y <= n-1 && x >= 0 && x <= n-1;
}

int topdown(int y, int x) {
    if(dp[y][x] != -1) return dp[y][x];

    int aroundmax = 0;
    for(int i = 0; i < 4; i++) {
        int nexty = y + dy[i];
        int nextx = x + dx[i];

        if(!inRange(nexty, nextx)) continue;
        if(map[nexty][nextx] <= map[y][x]) continue;

        int temp = topdown(nexty, nextx);
        aroundmax = max(aroundmax, temp);
    }

    dp[y][x] = aroundmax + 1;
    return dp[y][x];
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            topdown(i, j);
        }
    }

    int ans = -2e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}