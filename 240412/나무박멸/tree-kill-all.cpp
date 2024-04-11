#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m, k, c;

int treeMap[25][25];
int nextTreeMap[25][25];
int drugMap[25][25];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int answer = 0;

bool inRange(int y, int x) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void growTree() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(treeMap[i][j] <= 0) continue;
            int count = 0;
            for(int k = 0; k < 4; k++) {
                int nexty = i + dy[k];
                int nextx = j + dx[k];
                if(!inRange(nexty, nextx)) continue;
                if(treeMap[nexty][nextx] <= 0) continue;
                count++;
            }
            treeMap[i][j] += count;
        }
    }
}

void makeChildTree() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(treeMap[i][j] <= 0) continue;
            int count = 0;
            for(int k = 0; k < 4; k++) {
                int nexty = i + dy[k];
                int nextx = j + dx[k];
                if(!inRange(nexty, nextx)) continue;
                if(drugMap[nexty][nextx] != 0) continue;
                
                if(treeMap[nexty][nextx] == 0) count++;
            }

            if(count == 0) continue;
            int childTree = treeMap[i][j]/count;

            for(int k = 0; k < 4; k++) {
                int nexty = i + dy[k];
                int nextx = j + dx[k];
                if(!inRange(nexty, nextx)) continue;
                if(drugMap[nexty][nextx] != 0) continue;
                
                if(treeMap[nexty][nextx] == 0) {
                    nextTreeMap[nexty][nextx] += childTree;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            treeMap[i][j] += nextTreeMap[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            nextTreeMap[i][j] = 0;
        }
    }
}

void killTrees() {
    int kdy[4] = {-1, 1, -1, 1};
    int kdx[4] = {-1, 1, 1, -1};

    int killMap[25][25];

    // Best 제초제 위치 찾기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(treeMap[i][j] <= 0) continue;
            killMap[i][j] += treeMap[i][j];

            for(int d = 0; d < 4; d++) {
                for(int range = 1; range <= k; range++) {
                    int nexty = i + kdy[d]*range;
                    int nextx = j + kdx[d]*range;
                    
                    if(!inRange(nexty, nextx)) break;
                    if(treeMap[nexty][nextx] <= 0) break;
                    killMap[i][j] += treeMap[nexty][nextx];
                }
            }
        }
    }

    tuple<int, int, int> best_pos = make_tuple(1, -1, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tuple<int, int, int> pos = make_tuple(-killMap[i][j], i, j);
            best_pos = min(best_pos, pos);
        }
    }
    if(best_pos == make_tuple(1, -1, -1)) return; // 제초제 뿌릴 곳이 없으면 그대로 종료

    int kills, curry, currx;
    tie(kills, curry, currx) = best_pos;
    for(int d = 0; d < 4; d++) {
        answer += treeMap[curry][currx];
        treeMap[curry][currx] = 0;
        for(int range = 1; range <= k; range++) {
            int nexty = curry + kdy[d]*range;
            int nextx = currx + kdx[d]*range;
            
            if(!inRange(nexty, nextx)) break;
            drugMap[nexty][nextx] = c+1;
            if(treeMap[nexty][nextx] <= 0) {
                break;
            } else {
                answer += treeMap[nexty][nextx];
                treeMap[nexty][nextx] = 0;
            }
        }
    }
}

void reduceDrugs() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(drugMap[i][j] == 0) continue;
            drugMap[i][j]--;
        }
    }
}

void printTrees() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << treeMap[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m >> k >> c;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> treeMap[i][j];
        }
    }

    while(m--) {
        growTree();
        makeChildTree();
        killTrees();
        reduceDrugs();
    }

    cout << answer;

    return 0;
}