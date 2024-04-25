#include <iostream>
#include <vector>

using namespace std;

int memo[25];

int topDown(int n) {
    if(memo[n] != 0) return memo[n];

    memo[n] = (n-2) * topDown(n-1) + n;
    return memo[n];
}

int main() {

    int n;
    cin >> n;

    memo[1] = 1;

    cout << topDown(n);

    return 0;
}