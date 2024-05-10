#include <iostream>

using namespace std;

int n, m;
int exp[105];
int runtime[105];
int dp[105][10005];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> exp[i] >> runtime[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 10000; j++) {
            if(runtime[i] <= j){
                dp[i][j] = max(dp[i][j], dp[i-1][j - runtime[i]] + exp[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    int answer = -1;

    for(int i = 0; i <= 10000; i++) {
        if(dp[n][i] >= m) {
            answer = i;
            break;
        }
    }

    cout << answer;

    return 0;
}