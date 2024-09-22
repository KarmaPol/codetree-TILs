#include <iostream>
using namespace std;

int n, m;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int map[25][25];

int getGold(int y, int x, int k) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(y - i) + abs(x - j) <= k)
                count += map[i][j];
        }
    }

    return count;
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
    for(int k = 0; k <= 2*n; k++) {
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < n; x++) {
                int gold = getGold(y, x, k);
                
                if(gold * m >= minePrice(k)) {
                    maxGoldCount = max(maxGoldCount, gold);
                }
            }
        }
    }

    cout << maxGoldCount;

    return 0;
}