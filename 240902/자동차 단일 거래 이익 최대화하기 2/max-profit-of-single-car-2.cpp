#include <iostream>
using namespace std;

int n;

int main() {

    long long left = 2e13, maxProfit = 0;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        long long current;
        cin >> current;
        maxProfit = max(maxProfit, current - left);

        left = min(left, current);
    }

    cout << maxProfit;

    return 0;
}