#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[30][30];
int seqMap[30][30];

int n, m;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

vector<int> monsters(1000);
vector<int> nextMonsters(1000);

void getSeqMap() {
    int diry[4] = {0, 1, 0, -1};
    int dirx[4] = {-1, 0, 1, 0};

    int start_y = n/2, start_x = n/2;
    seqMap[start_y][start_x] = -1;

    int dir = 0, count = 0, seq = 0;
    int blockCount = 0, blocks = 1;

    while(true) {
        start_y = start_y + diry[dir];
        start_x = start_x + dirx[dir];

        if(start_x < 0 || start_y < 0 || start_x >= n || start_y >= n) break;

        seqMap[start_y][start_x] = seq;
        blockCount++; seq++;
        if(blockCount == blocks) {
            blockCount = 0;
            count++;
            dir++;
            dir %= 4;
        }
    
        if(count == 2) {
            blocks++;
            count %= 2;
        }
    }
}

void getMonsters() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] != 0) {
                monsters[seqMap[i][j]] = map[i][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    getSeqMap(); getMonsters();
    int playerY = n/2, playerX = n/2;

    while(m--) {
        int d, p;
        cin >> d >> p;

        for(int i = 0; i < nextMonsters.size(); i++) {
            nextMonsters[i] = 0;
        }
        
        for(int i = 1; i <= p; i++) {
            int attackY = playerY + i*dy[d];
            int attackX = playerX + i*dx[d];
            
            if(monsters[seqMap[attackY][attackX]] == 0) continue;
            answer += monsters[seqMap[attackY][attackX]];
            monsters[seqMap[attackY][attackX]] = -1;
        }

        for(int i = 0, j = 0; i < monsters.size(); i++) {
            if(monsters[i] > 0) {
                nextMonsters[j] = monsters[i];
                j++;
            }
        }
        monsters = nextMonsters;

        int count = 0;
        while(true) {
            count = 0;
            int combo = 0, comboStart = 0;
            for(int i = 0; i < monsters.size(); i++) {
                if(combo == monsters[i]) continue;

                if(i - comboStart >= 4) {
                    if(combo != -1) {
                        count++;
                        for(int j = comboStart; j < i; j++) {
                            answer += monsters[j];
                            monsters[j] = -1;
                        }
                    }
                }

                combo = monsters[i]; comboStart = i;
            }
            if(count == 0) break;

            for(int i = 0; i < nextMonsters.size(); i++) {
                nextMonsters[i] = 0;
            }
            
            for(int i = 0, j = 0; i < monsters.size(); i++) {
                if(monsters[i] > 0) {
                    nextMonsters[j] = monsters[i];
                    j++;
                }
            }
            monsters = nextMonsters;
        }

        for(int i = 0; i < nextMonsters.size(); i++) {
            nextMonsters[i] = 0;
        }

        int combo = 0, comboStart = 0;
        int idx = 0;

        for(int i = 0; i < monsters.size(); i++) {
            if(combo == monsters[i]) continue;

            if(combo > 0){
                nextMonsters[idx] = i - comboStart; idx++;
                nextMonsters[idx] = combo; idx++;
            }
            
            if(monsters[i] == 0) break;
            combo = monsters[i]; comboStart = i;
        }
        monsters = nextMonsters;
    }

    cout << answer;

    return 0;
}