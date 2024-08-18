#include <iostream>
#include <vector>
using namespace std;

string a, b;
bool skip[200005];
int del[200005];

bool isPossible(int index) {
    int bIndex = 0;

    for(int i = 1; i <= index; i++) {
        skip[del[i] - 1] = true;
    }

    for(int i = 0; i < a.size(); i++) {
        if(skip[i]) continue;
        char currentCharA = a[i];
        char currentCharB = b[bIndex];

        if(bIndex < b.size() && currentCharA == currentCharB) {
            bIndex++;
        }
    }

    return bIndex == b.size();
}

int main() {
    cin >> a;
    cin >> b;
    
    for(int i = 1; i <= a.size(); i++) {
        cin >> del[i];
    }

    int left = 0, right = a.size(), mid;
    int answer = -1;

    while(left <= right) {
        mid = (left + right)/2;

        if(isPossible(mid)) {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

        for(int i = 1; i <= mid; i++) {
            skip[del[i] - 1] = false;
        }
    }

    cout << answer + 1;

    return 0;
}
// string을 지워서 직접 저장하면 메모리 초과 -> skip 배열을 만들어서 순차적으로 조회가능하게 넣어주면 됨