#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;

    int count = 0;

    int fiveM = n/5; 
    if(n >= 5 && n % 2 == 1) {
        fiveM--;
    }
    count += fiveM; n -= fiveM * 5;
    count += n / 2; n -= (n/2) * 2;

    if(n != 0) {
        count = -1;
    }
    cout << count;

    return 0;
}