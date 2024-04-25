#include <iostream>

using namespace std;

int memo[21];

int NumOfBST(int n) {
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += memo[i] * memo[n-1-i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    memo[0] = 1;
    memo[1] = 1;

    for(int i = 2; i <= n; i++) {
        memo[i] = NumOfBST(i);
    }
    cout << memo[n];

    return 0;
}