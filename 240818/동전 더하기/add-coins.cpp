#include <iostream>
using namespace std;

int n, k;

int coins[15];

int main() {

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int coinCount = 0, coinIndex = n-1;
    
    for(int i = n-1; i >= 0; i--) {
        coinCount += k / coins[i];
        k %= coins[i];
    }

    cout << coinCount;

    return 0;
}