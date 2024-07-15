#include <iostream>
using namespace std;

long long s;

int main() {
    cin >> s;
    long long n = 0;

    long long left = 1, right = s, mid = 0;
    while(left <= right) {
        mid = (left + right)/2;

        if(mid*(mid+1)/2 <= s) {
            n = max(n, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << n;

    return 0;
}