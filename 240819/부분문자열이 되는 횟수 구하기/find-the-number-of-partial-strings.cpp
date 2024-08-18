#include <iostream>
#include <vector>
using namespace std;

string a, b;

bool isPossible(int index, vector<string> aSeries) {
    string currentA = aSeries[index];
    int bIndex = 0;
    for(int i = 0; i < currentA.size(); i++) {
        while(currentA[i] == ' ' && i < currentA.size()) {
            i++;
        }
        char currentCharA = currentA[i];
        char currentCharB = b[bIndex];

        if(currentCharA == currentCharB) {
            bIndex++;
        }

        if(bIndex >= b.size()) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> a >> b;
    
    vector<string> aSeries;
    aSeries.push_back(a);
    for(int i = 1; i <= a.size(); i++) {
        int deleteIndex;
        cin >> deleteIndex;

        string copyA = aSeries[i-1];
        copyA[deleteIndex-1] = ' ';
        aSeries.push_back(copyA);
    }

    int left = 0, right = a.size(), mid;
    int answer = -2e9;

    while(left <= right) {
        mid = (left + right)/2;

        if(isPossible(mid, aSeries)) {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer + 1;

    return 0;
}