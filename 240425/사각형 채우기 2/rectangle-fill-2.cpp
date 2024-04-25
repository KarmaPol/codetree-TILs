#include <iostream>

using namespace std;

int memo[1005];

int main() {

    int n;
    cin >> n;

    memo[1] = 1;
    memo[2] = 3;

    for(int i = 3; i <= n; i++) {
        memo[i] = (memo[i-1] + memo[i-2]*2)%10007;
    }
    
    cout << memo[n];

    return 0;
}