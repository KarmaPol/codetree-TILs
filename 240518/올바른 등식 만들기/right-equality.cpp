#include <iostream>

using namespace std;

int n, m;

int OFFSET = 30;
int numbers[105];
long long dp[60][105];

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> numbers[i];
    }

    dp[30][0] = 1;

    for(int j = 1; j <= n; j++) {
        for(int i = -20; i <= 20; i++) {
            if(dp[i+OFFSET - numbers[j]][j-1]){
                dp[i+OFFSET][j] += dp[i+OFFSET - numbers[j]][j-1];
            }
            if(dp[i+OFFSET + numbers[j]][j-1]){
                dp[i+OFFSET][j] += dp[i+OFFSET + numbers[j]][j-1];
            }
        }
    }
    // for(int j = 0; j <= n; j++) {
    //     for(int i = 10; i <= 50; i++) {
    //         cout << i-OFFSET << ": " << dp[i][j] << '\n'; 
    //     }
    //     cout << '\n';
    // }
    
    cout << dp[m+OFFSET][n];

    return 0;
}