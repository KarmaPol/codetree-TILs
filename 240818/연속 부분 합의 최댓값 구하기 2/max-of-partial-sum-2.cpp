#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;

    int sum = 0, summax = -2e9;
    for(int i = 0; i < n; i++) {
        int number;
        cin >> number;

        sum += number;
        summax = max(summax, sum);

        if(sum < 0) {
            sum = 0;
        }
    }

    cout << summax;

    return 0;
}