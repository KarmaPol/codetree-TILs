#include <iostream>
#include <algorithm>
using namespace std;

int n;

string inputs[100005];

bool cmp(string a, string b) {
    if(a == ")" && b[0] == ')') {
        return a < b;
    }
    if(b == ")" && a[0] == ')') {
        return a > b;
    }
    return a < b;
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> inputs[i];
    }

    sort(inputs, inputs+n, cmp);

    string t;
    for(int i = 0; i < n; i++) {
        // cout << inputs[i] << '\n';
        t += inputs[i];
    }

    int leftCount = 0, answer = 0;

    if(t.size() > 10000) cout << t.size();

    for(int i = 0; i < t.size(); i++) {
        if(t[i] == '(') {
            leftCount++;
        }

        else if(t[i] == ')') {
            answer += leftCount;
        }
    }

    cout << answer;

    return 0;
}