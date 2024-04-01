#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> tables(4, vector<int>(8)); // 12시 - 인덱스 0, 3시 - 2, 6시 - 4, 9시 - 6

void turnclock(int n) {
    int temp = tables[n][7];
    tables[n].pop_back();
    tables[n].insert(tables[n].begin(), temp);
}

void turnnonclock(int n) {
    int temp = tables[n][0];
    tables[n].erase(tables[n].begin());
    tables[n].push_back(temp);
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    for(int i = 0; i < 4; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < 8; j++) {
            tables[i][j] = temp[j] - '0';
        }
    }

    int t;
    cin >> t;

    while(t--) {
        int table, dir;
        cin >> table >> dir;
        
        vector<int> isTurn(4);
        isTurn[table-1] = dir;

        int prev = tables[table-1][2];
        int prevdir = dir;
        for(int i = table; i < 4; i++) { // 오른쪽 테이블
            prevdir *= -1;
            if(prev != tables[i][6]) {
                isTurn[i] = prevdir;
            }
            else {
                break;
            }
            prev = tables[i][2];
        }

        prev = tables[table-1][6];
        prevdir = dir;
        for(int i = table-2; i > -1; i--) { // 왼쪽 테이블
            if(prev != tables[i][2]) {
                prevdir *= -1;
                isTurn[i] = prevdir;
            }
            else {
                break;
            }
            prev = tables[i][6];
        }

        for(int i = 0; i < 4; i ++) {
            if(isTurn[i] == 1) { // 시계
                turnclock(i);
            }
            else if(isTurn[i] == -1) { // 반시계
                turnnonclock(i);
            }
        }
    }

    cout << tables[0][0] + 2*tables[1][0] + 4*tables[2][0] + 8*tables[3][0];

    return 0;
}