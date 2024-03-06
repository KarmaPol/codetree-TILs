#include <iostream>
#include <vector>

using namespace std;

int numbers[15];
int operations[3];
int num;
int MIN_VALUE = 2e9;
int MAX_VALUE = -2e9;

int operate(int n, int k, int o) {
    if(o == 0) {
        return n+k;
    }
    else if(o == 1) {
        return n-k;
    }
    else {
        return n*k;
    }
}

void backtracking(int stage, int tot) {

    if(stage >= num) {
        if(tot < MIN_VALUE) {
            MIN_VALUE = tot;
        }
        if(tot > MAX_VALUE) {
            MAX_VALUE = tot;
        }
        return;
    }

    for(int i = 0; i < 3; i++) {
        if(operations[i] > 0) {
            operations[i]--;
            int result = operate(tot, numbers[stage], i);
            backtracking(stage+1, result);
            
            operations[i]++;
        }
    }   
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    num = n;
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for(int i = 0; i < 3; i++) {
        cin >> operations[i];
    }

    backtracking(1, numbers[0]);
    cout << MIN_VALUE << ' ' << MAX_VALUE;

    return 0;
}