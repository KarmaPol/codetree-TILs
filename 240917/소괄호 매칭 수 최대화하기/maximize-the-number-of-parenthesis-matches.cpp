#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> brackets[100005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second > b.first * a.second;
}

int main() {
    cin >> n;

    long long answer = 0;

    for(int i = 0; i < n; i++) {
        string bracket;
        cin >> bracket;

        int openCount = 0, closeCount = 0;
        for(int i = 0; i < bracket.size(); i++) {
            if(bracket[i] == '(') {
                openCount++;
            }
            else {
                closeCount++;

                answer += openCount;
            }
        }
        brackets[i] = {openCount, closeCount};
    }

    sort(brackets, brackets + n, cmp);

    int open_sum = 0;
    for(int i = 0; i < n; i++) {
        answer += (long long) open_sum * brackets[i].second;

        open_sum += brackets[i].first;
    }

    cout << answer;

    return 0;
}