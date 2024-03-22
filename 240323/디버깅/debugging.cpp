#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, h, m;

vector<vector<int>> map(35, vector<int> (15));
vector<pair<int,int>> memoryleakCandidates;
vector<pair<int,int>> addedMemoryLeak;
vector<vector<pair<int,int>>> addedMemoryLeaks;

// n-1 * h 만큼의 예비 유실선에서 뽑는다
void addMemoryLeaks(int idx, int size) {
    if(addedMemoryLeak.size() == size) {
        addedMemoryLeaks.push_back(addedMemoryLeak);
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

    addMemoryLeaks(0, 0);
    addMemoryLeaks(0, 1);
    addMemoryLeaks(0, 2);

    int answer = -1;

    for(auto memoryleaks : addedMemoryLeaks) {
        vector<vector<int>> copymap = map;
        for(auto ml : memoryleaks) {
            copymap[ml.first][ml.second] = 1;
        }

        int success = 0;

        // 각 시작점으로부터 사다리 게임
        for(int i = 1; i <= m; i++) { // 고객
            int currentm = i;
            int currenth = 1;
            while(currenth <= h) {
                if(copymap[currenth][currentm] == 1){
                    currentm++;
                } // 우로 이동
                else if(copymap[currenth][currentm-1] == 1) {
                    currentm--;
                } // 좌로 이동

                currenth++;
            }

            if(i == currentm) {
                success++;
            }
        }
        if(success == m) {
            answer = memoryleaks.size();
            break;
        }
    }
    cout << answer;

    return 0;
}