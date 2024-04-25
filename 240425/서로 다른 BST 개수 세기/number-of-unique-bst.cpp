#include <iostream>
#include <vector>

using namespace std;

int memo[25];

int topDown(int n) {
    if(memo[n] != 0) return memo[n];

    int prev = (n-3) * topDown(n-1);
    if(prev < 0) prev = 0;
    memo[n] = prev + (n*(n+1)/2 -1);
    return memo[n];
}

int main() {

    int n;
    cin >> n;

    memo[1] = 1;

    cout << topDown(n);

    return 0;
}