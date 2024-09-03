#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cardB[50005];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> cardB[i];
    }

    sort(cardB, cardB + n);

    int bidx = 0, answer = 0;
    for(int i = 1; i <= 2*n; i++) {
        if(i > cardB[bidx]) {
            bidx++; answer++;
        }
    }

    cout << answer;

    return 0;
}