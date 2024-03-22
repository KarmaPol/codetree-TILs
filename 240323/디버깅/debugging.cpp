#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, h, m;

int answer = -1;

vector<vector<int>> map(35, vector<int> (15));
vector<pair<int,int>> memoryleakCandidates;
vector<pair<int,int>> addedMemoryLeak;

// n-1 * h 만큼의 예비 유실선에서 뽑는다
void addMemoryLeaks(int idx, int size) {
    if(answer != -1) {
        return;
    }

    if(addedMemoryLeak.size() == size) {
        for(auto ml : addedMemoryLeak) {
            map[ml.first][ml.second] = 1;
        }

        int success = 0;

        // 각 시작점으로부터 사다리 게임
        for(int i = 1; i <= m; i++) { // 고객
            int currentm = i;
            int currenth = 1;
            while(currenth <= h) {
                if(map[currenth][currentm] == 1){
                    currentm++;
                } // 우로 이동
                else if(map[currenth][currentm-1] == 1) {
                    currentm--;
                } // 좌로 이동

                currenth++;
            }

            if(i == currentm) {
                success++;
            }
        }
        if(success == m) {
            answer = addedMemoryLeak.size();
        }

        for(auto ml : addedMemoryLeak) {
            map[ml.first][ml.second] = 0;
        }
        return;
    }

    for(int i = idx; i < memoryleakCandidates.size(); i++) {
        int currenth = memoryleakCandidates[i].first;
        int currentm = memoryleakCandidates[i].second;
        if(map[currenth][currentm] == 1) continue;

        addedMemoryLeak.push_back({currenth, currentm});
        addMemoryLeaks(i + 1, size);
        addedMemoryLeak.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;

    while(n--) {
        int temph, tempm;
        cin >> temph >> tempm;
        map[temph][tempm] = 1;
    }

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j < m; j++) {
            if(map[i][j] == 1) continue;
            memoryleakCandidates.push_back({i, j});
        }
    }

    for(int i = 0; i < 4; i++) {
        addMemoryLeaks(0, i);
    }

    cout << answer;

    return 0;
}