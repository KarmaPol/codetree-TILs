#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[1005][1005];
int dp[1005][1005];

void Initialize() {
    dp[0][0] = num[0][0];

    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][0], num[i][0]);
    }

    for(int j = 1; j < n; j++) {
        dp[0][j] = min(dp[0][j-1], num[0][j]);
    }
}
 
int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> num[i][j];
        }
    }

    Initialize();

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = min(max(dp[i-1][j], dp[i][j-1]), num[i][j]);
        }
    }
    
    cout << dp[n-1][n-1];

    return 0;
}