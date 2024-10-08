#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cardB[50005];
int isPicked[100005];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int card;
        cin >> card;
        cardB[i] = card;
        isPicked[card] = 1;
    }

    sort(cardB, cardB + n);

    int bidx = 0, answer = 0;
    for(int i = 1; i <= 2*n; i++) {
        if(isPicked[i]) continue;

        if(i > cardB[bidx]) {
            bidx++; answer++;
            if(bidx >= n) break;
        }
    }

    cout << answer;

    return 0;
}