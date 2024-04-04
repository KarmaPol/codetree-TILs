#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int,int>> monsters;
int map[25][25];
int visited[25][25];

int diry[4] = {-1, 0, 1, 0};
int dirx[4] = {0, -1, 0, 1};

pair<int,int> current;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(map[a.first][a.second] == map[b.first][b.second]) {
        int dista = abs(current.first - a.first) + abs(current.second - a.second);
        int distb = abs(current.first - b.first) + abs(current.second - b.second);
        if(dista == distb) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
        return dista > distb;
    }
    return map[a.first][a.second] > map[b.first][b.second];
}

void resetvisited() {
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 25; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;

    cin >> n;

    queue<pair<int,int>> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                q.push({i,j});
                visited[i][j] = 1;
                current = {i,j};
            }
            else if(map[i][j] > 0) {
                monsters.push_back({i,j});
            }
        }
    }

    int answer = 0;
    int level = 2, hunt = 2;

    while(monsters.size() != 0) {
        sort(monsters.begin(), monsters.end(), cmp);
        pair<int,int> dest = monsters[monsters.size()-1];
        monsters.pop_back();
        
        if(map[dest.first][dest.second] > level) break;

        while(!q.empty()) {
            current = q.front(); q.pop();

            if(current.first == dest.first && current.second == dest.second) {
                answer += visited[current.first][current.second] - 1;
                hunt--;
                if(hunt == 0) {
                    level++;
                    hunt = level;
                }
                resetvisited();
                visited[current.first][current.second] = 1;
                while(!q.empty()) {
                    q.pop();
                }
                q.push(current);
                break;
            }

            for(int i = 0; i < 4; i++) {
                int nexty = current.first + diry[i];
                int nextx = current.second + dirx[i];

                if(nexty >= n || nextx >= n || nextx < 0 || nexty < 0) continue;
                if(map[nexty][nextx] != 0) {
                    if(nexty != dest.first || nextx != dest.second) continue;
                }
                if(visited[nexty][nextx] > 0) continue;

                visited[nexty][nextx] = visited[current.first][current.second] + 1;
                q.push({nexty, nextx});
            }
        }
    }

    cout << answer;

    return 0;
}