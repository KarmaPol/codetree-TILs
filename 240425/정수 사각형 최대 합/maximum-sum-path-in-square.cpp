#include <iostream>

using namespace std;

int map[105][105];
int dp[105][105];

int n;

bool inRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int lefty = i; int leftx = j-1;
            int upy = i-1; int upx = j;
            int left = 0, up = 0;
            if(inRange(lefty, leftx)){
                left = dp[lefty][leftx];
            }
            if(inRange(upy, upx)){
                up = dp[upy][upx];
            }

            dp[i][j] = max(left, up) + map[i][j];
        }
    }

    int maxsum = 0;
    for(int i = 0; i < n; i++) {
        maxsum = max(maxsum, dp[n-1][i]);
    }

    cout << maxsum;

    return 0;
}