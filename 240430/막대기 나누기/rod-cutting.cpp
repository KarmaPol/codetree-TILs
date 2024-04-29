#include <iostream>

using namespace std;

int n;
int sticks[105];
int dp[105];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> sticks[i];
    }

    for(int i = 1; i <= n; i++) {
        int currentstick = i;
        for(int j = 1; j <= n; j++) {
            if(currentstick > j) continue;
            dp[j] = max(dp[j], dp[j-currentstick] + sticks[currentstick]);
        }
    }

    cout << dp[n];

    return 0;
}