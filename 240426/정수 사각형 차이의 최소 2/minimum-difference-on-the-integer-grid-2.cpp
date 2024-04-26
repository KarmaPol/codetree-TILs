#include <iostream>
#include <tuple>

using namespace std;

int n;
int map[105][105];
tuple<int,int,int> dp[105][105];

int dy[2] = {0, 1};
int dx[2] = {1, 0};

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            dp[i][j] = make_tuple(map[i][j], map[i][j], 2e9);
        }
    }

    dp[0][0] = make_tuple(map[0][0], map[0][0], 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int currenty = i, currentx = j;
            int currentMax, currentMin, currentDiff;
            tie(currentMax, currentMin, currentDiff) = dp[currenty][currentx];

            for(int d = 0; d < 2; d++) {
                int nexty = currenty + dy[d];
                int nextx = currentx + dx[d];
                int nextMax, nextMin, nextDiff;
                tie(nextMax, nextMin, nextDiff) = dp[nexty][nextx];

                int tempMax = max(map[nexty][nextx], currentMax);
                int tempMin = min(map[nexty][nextx], currentMin);
                int tempDiff = tempMax - tempMin;
                if(tempDiff < nextDiff) {
                    dp[nexty][nextx] = make_tuple(tempMax,tempMin, tempDiff);
                }
                else if(tempDiff == nextDiff) {
                    if(nextMax > tempMax || nextMin < tempMin) {
                        dp[nexty][nextx] = make_tuple(tempMax,tempMin, tempDiff);
                    }
                }
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << get<0>(dp[i][j]) << ' ' << get<1>(dp[i][j]) << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << get<2>(dp[n-1][n-1]);

    return 0;
}