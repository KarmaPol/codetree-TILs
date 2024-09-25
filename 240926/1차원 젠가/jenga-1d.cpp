#include <iostream>
using namespace std;

int n;

int blocks[105];
int temp_blocks[105];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    int s, e;
    cin >> s >> e;
    s--; e--;

    int t = 0;
    for(int i = 0; i < n; i++) {
        if(i >= s && i <= e) {
            continue;
        }
        temp_blocks[t] = blocks[i];
        t++;
    }

    for(int i = 0; i < t; i++) {
        blocks[i] = temp_blocks[i];
    }

    for(int i = 0; i < n; i++) {
        temp_blocks[i] = 0;
    }

    cin >> s >> e;
    s--; e--;
    n = t;
    t = 0;
    for(int i = 0; i < n; i++) {
        if(i >= s && i <= e) {
            continue;
        }
        temp_blocks[t] = blocks[i];
        t++;
    }

    for(int i = 0; i < t; i++) {
        blocks[i] = temp_blocks[i];
        temp_blocks[i] = 0;
    }

    cout << t << '\n';

    for(int i = 0; i < t; i++) {
        cout << blocks[i] << '\n';
    }

    return 0;
}