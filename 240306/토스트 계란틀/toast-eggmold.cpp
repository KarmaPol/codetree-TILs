#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
int map[55][55];
int visited[55][55];

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int answer = 0;

    int n, l, r;
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    while(1) {
        vector<pair<vector<pair<int,int>>, int>> eggmemories;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }

        while(1) {
            // 시작 지점 찾기
            int starty = -1, startx = -1;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(visited[i][j] == 0) {
                        starty = i; startx = j;
                        break;
                    }
                }
            }
            if(starty == -1 || startx == -1) break;

            // 시작지점에서 하나로 연결된 지점들 탐색
            visited[starty][startx] = 1;
            queue<pair<int, int>> q;
            vector<pair<int, int>> eggmemory;
            q.push({starty, startx});
            eggmemory.push_back({starty, startx});

            int totalegg = map[starty][startx];
            while(!q.empty()) {
                auto curr = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nexty = curr.first + dir[i][0];
                    int nextx = curr.second + dir[i][1];

                    if(visited[nexty][nextx] == 1) continue;
                    if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n) continue;
                    int diff = abs(map[curr.first][curr.second] - map[nexty][nextx]);
                    if(diff < l || diff > r) continue;

                    visited[nexty][nextx] = 1;
                    totalegg += map[nexty][nextx];
                    q.push({nexty, nextx});
                    eggmemory.push_back({nexty, nextx});
                }
            }
            eggmemories.push_back({eggmemory, totalegg});
        }

        if(eggmemories.size() == n*n) {
            break;
        }

        // 각 구역별로 egg 균등하게 분배
        // cout << '\n';
        for(auto eggmemory : eggmemories) {
            int tot = eggmemory.second;
            // cout << tot << '\n';
            for(auto egg : eggmemory.first) {
                map[egg.first][egg.second] = tot/eggmemory.first.size();
                // cout << map[egg.first][egg.second] << '\n';
            }
        }
        answer++;
    }

    cout << answer;

    return 0;
}