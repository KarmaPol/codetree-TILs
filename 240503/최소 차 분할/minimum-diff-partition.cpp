#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int arr[105];

bool dp[105][1000005];

int main() {
    cin >> n;
    for(int i = 1; i <= n ; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++) {
        m += arr[i];
    }

    dp[0][0] = true;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(arr[i] <= j && dp[i-1][j - arr[i]]) {
                dp[i][j] = true;
            }

            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }

    int ans = 2e9;
    for(int i =1; i <= m; i++){
        if(dp[n][i]) {
            ans = min(ans, abs(i - (m-i)));
        }
    }
    
    cout << ans;

    return 0;
}