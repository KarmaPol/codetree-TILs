#include <iostream>

using namespace std;

int n, m;

int arr[105];
int dp[105];

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        int currnum = arr[i];
        for(int j = m; j >= 0; j--) {
            if(currnum > j) continue;

            dp[j] = max(dp[j], dp[j- currnum] + 1);
        }
    }

    string ans = "Yes";
    if(dp[m] == 0)
        ans = "No";
    
    cout << ans;

    return 0;
}