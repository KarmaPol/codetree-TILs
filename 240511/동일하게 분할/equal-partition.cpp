#include <iostream>

using namespace std;

int n;

int numbers[105];
bool dp[105][100005];

int main() {
    
    cin >> n;

    int tot = 0;

    for(int i = 1; i <= n; i++) {
        cin >> numbers[i];
        tot += numbers[i];
    }

    dp[0][0] = true;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= tot; j++) {
            if(j >= numbers[i]) {
                if(dp[i-1][j-numbers[i]]) {
                    dp[i][j] = true;
                }
            }
            
            if(dp[i-1][j]) dp[i][j] = true;
        }
    }

    string ans = "No";

    // for(int i = 0; i <= tot; i++) {
    //     cout << dp[n][i] << '\n';
    // }

    if(tot % 2 == 0 && dp[n][tot/2] == true) {
        ans = "Yes";
    }

    cout << ans;

    return 0;
}