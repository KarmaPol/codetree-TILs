#include <iostream>

using namespace std;

int n;

int map[1005];
int dp[1005];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> map[i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(i > map[j] + j) continue;
            dp[i] = max(dp[j] + 1, dp[i]);
        }
    }

    cout << dp[n-1];

    return 0;
}