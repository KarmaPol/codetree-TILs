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
    while(k > 0 && coinIndex > 0) {
        if(coins[coinIndex] > k) continue;

        coinCount += k/coins[coinIndex];
        k = k % coins[coinIndex];
        coinIndex--;
    }

    cout << coinCount;

    return 0;
}