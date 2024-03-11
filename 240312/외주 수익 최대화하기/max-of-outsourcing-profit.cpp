#include <iostream>

using namespace std;

int memo[20];
int memoend[20];
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
        if(jobend[i] > n) {
            continue;
        }
        
        // 기본값 - 현재 작업은 채택하지 않음
        memo[i] = memo[i-1];
        memoend[i] = memoend[i-1];

        // 직전 작업이 이미 종료됨
        if(memoend[i-1] < i) {
            memo[i] = memo[i-1] + jobpay[i];
            memoend[i] = jobend[i];
        }

        // 직전 작업이 종료되지 않음 -> 종료된 시점까지 돌아가기
        int prevjob = i-1;
        while(prevjob--) {
            if(memoend[prevjob] < i) break;
        }
        if(memo[prevjob] + jobpay[i] > memo[i]) {
            memo[i] = memo[prevjob] + jobpay[i];
            memoend[i] = jobend[i];
        }
    }

    cout << memo[n];

    return 0;
}