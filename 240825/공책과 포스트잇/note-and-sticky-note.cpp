#include <iostream>
#include <algorithm>
using namespace std;

int n, k, l;
long long totalPost;
int notes[100005];

bool cmp(int a, int b) {
    return b < a;
}

bool isPossible(int h) {
    int count = 0;
    long long usedWords = 0;
    
    for(int i = 0; i < h; i++) {
        if(notes[i] < h) {
            usedWords += h - notes[i];
        }
    }

    return usedWords <= totalPost && notes[h-1] + k >= h;
}

int main() {
    cin >> n >> k >> l;

    totalPost = k*l;

    for(int i = 0; i < n; i++) {
        cin >> notes[i];
    }
    sort(notes, notes + n, cmp);
    
    int left = 1, right = 100000, mid;
    int answer = 0;

    while(left <= right) {
        mid = (left + right) / 2;

        if(isPossible(mid)) {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}