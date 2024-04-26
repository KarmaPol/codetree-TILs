#include <iostream>

using namespace std;

int n, m;

int arr[105];
int dp[10005];

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i <= m; i++) {
        dp[i] = -1;
    }

    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        int currnum = arr[i];
        for(int j = m; j >= 0; j--) {
            if(currnum > j) continue;
            if(dp[j-currnum] == -1) continue;
            dp[j] = max(dp[j], dp[j- currnum] + 1);
        }
    }

    string ans = "Yes";
    if(dp[m] == -1)
        ans = "No";
    
    cout << ans;

    return 0;
}