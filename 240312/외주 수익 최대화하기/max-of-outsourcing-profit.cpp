#include <iostream>

using namespace std;

int memo[20];
int jobend[20];
int jobpay[20];

int main() {
    
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> jobend[i] >> jobpay[i];
        jobend[i] += i-1;
    }

    for(int i = 1; i <= n; i++) {
        // 현재 작업 채택시 범위 벗어가는지 체크
        if(jobend[i] > n) {
            continue;
        }

        for(int j = 0; j < n; j++) {
            if(jobend[j] < i) {
                memo[i] = max(memo[i], memo[j] + jobpay[i]);
            }
        }
    }

    int answer = 0;
    for(int i = 0; i <= n; i++) {
        answer = max(answer, memo[i]);
    }

    cout << answer;

    return 0;
}