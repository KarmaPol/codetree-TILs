#include <iostream>
#include <algorithm>
using namespace std;

int n;
string numbers[50005];

bool cmp(string a, string b) {
    char aFirst = a[0], bFirst = b[0];

    if(aFirst == bFirst) {
        return b + a < a + b;
    }

    return bFirst < aFirst;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n, cmp);

    string answer = "";
    for(int i = 0; i < n; i++) {
        answer += numbers[i];
    }

    cout << answer;

    return 0;
}