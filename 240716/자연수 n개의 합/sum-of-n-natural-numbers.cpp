#include <iostream>
using namespace std;

int s;

int main() {
    cin >> s;
    int n = 0;

    int left = 1, right = s, mid = 0;
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