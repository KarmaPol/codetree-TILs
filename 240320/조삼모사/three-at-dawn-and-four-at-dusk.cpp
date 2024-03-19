#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> temp;
vector<vector<int>> cmbs;
int n;
int map[30][30];

void getcombinations(int idx) {
    if(temp.size() == n/2) {
        cmbs.push_back(temp);
        return;
    }

    for(int i = idx; i < n; i++) {
        temp.push_back(i);
        getcombinations(i+1);
        temp.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    getcombinations(0);

    int mindiff = 2e9;
    for(auto cmb : cmbs) {
        int diff = 0;
        vector<int> nightjobs;
        for(int i =0 ; i < n; i++) {
            int ismorning = false;
            for(auto m : cmb) {
                if(i == m) {
                    ismorning = true;
                    break;
                }
            }
            if(!ismorning) {
                nightjobs.push_back(i);
            }
        }
        
        for(int i = 0; i < cmb.size(); i++) {
            for(int j = 0; j < cmb.size(); j++) {
                diff += map[cmb[i]][cmb[j]];
            }
        }

        for(int i = 0; i < nightjobs.size(); i++) {
            for(int j = 0; j < nightjobs.size(); j++) {
                diff -= map[nightjobs[i]][nightjobs[j]];
            }
        }
        mindiff = min(mindiff, abs(diff));
    }

    cout << mindiff;

    return 0;
}