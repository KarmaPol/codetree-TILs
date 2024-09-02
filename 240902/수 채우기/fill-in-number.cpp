#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;

    int count = 0;

    int fiveM = n/5; 
    count += fiveM; n -= fiveM * 5;
    if(count > 0 && n % 2 == 1) {
        n += 5;
        count--;
    }
    count += n / 2; n -= (n/2) * 2;

    if(n != 0) {
        count = -1;
    }
    cout << count;

    return 0;
}