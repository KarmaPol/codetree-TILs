#include <iostream>
#include <vector>

using namespace std;

vector<int> playerBoard[25][25];
vector<int> nextPlayerBoard[25][25];
int contractDayBoard[25][25];
int contractPlayerBoard[25][25];
int playerDirections[500];
int playerPrioritys[500][4][4];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int n, m, k;

bool isMoveAvailable(int dir, int y, int x, int p) {
    int nexty = y + dy[dir];
    int nextx = x + dx[dir];

    // 바깥 칸인지 검증
    if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n) return false;
    // 이미 계약되었는지 검증
    if(contractDayBoard[nexty][nextx] != 0) return false;

    return true;
}

bool isMoveContracted(int dir, int y, int x, int p) {
    int nexty = y + dy[dir];
    int nextx = x + dx[dir];

    if(contractDayBoard[nexty][nextx] != 0 && contractPlayerBoard[nexty][nextx] == p) return true; // 내가 이미 계약한 칸으로 이동

    return false;
}

void movePlayer(int cy, int cx, int dir, int p) {
    int nexty = cy + dy[dir];
    int nextx = cx + dx[dir];
    nextPlayerBoard[nexty][nextx].push_back(p);
}

void contract(int y, int x, int p) {
    if(contractPlayerBoard[y][x] != p && contractDayBoard[y][x] != 0) return;

    contractDayBoard[y][x] = k;
    contractPlayerBoard[y][x] = p;
}

void killCompetitors() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(playerBoard[i][j].size() == 0) continue;

            int lowestPlayer = 2e9;
            for(int k = 0; k < playerBoard[i][j].size(); k++) {
                lowestPlayer = min(playerBoard[i][j][k], lowestPlayer);
            }
            playerBoard[i][j].erase(playerBoard[i][j].begin(), playerBoard[i][j].end());
            if(lowestPlayer != 2e9) {
                playerBoard[i][j].push_back(lowestPlayer);
            }
        }
    }
}

void printPlayerNumber() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << playerBoard[i][j].size();
        }
        cout << '\n';
    }
    cout << '\n';
}

void printContractBoard() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << contractDayBoard[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isEnd() {
    int tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< n; j++) {
            tot += playerBoard[i][j].size();
        }
    }
    return tot == 1;
}

int main() {
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if(temp == 0) continue;
            playerBoard[i][j].push_back(temp-1);
            contractDayBoard[i][j] = k;
            contractPlayerBoard[i][j] = temp-1;
        }
    }

    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        playerDirections[i] = temp-1;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                int temp;
                cin >> temp;
                playerPrioritys[i][j][k] = temp-1;
            }
        }
    }

    int turn = 1;
    while(turn < 1000) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int p = 0; p < playerBoard[i][j].size(); p++) {
                    int currentPlayerNum = playerBoard[i][j][p];
                    int currentDirection = playerDirections[currentPlayerNum];

                    int nextDirection = -1;
                    for(int k = 0; k < 4; k++) { // 빈 땅으로 이동가능한지 탐색
                        if(isMoveAvailable(playerPrioritys[currentPlayerNum][currentDirection][k], i, j, currentPlayerNum)){
                            nextDirection = playerPrioritys[currentPlayerNum][currentDirection][k];
                            break;
                        }
                    }

                    for(int k = 0; nextDirection == -1 && k < 4; k++) { // 이미 내가 계약한 땅으로 이동가능한지 탐색
                        if(isMoveContracted(playerPrioritys[currentPlayerNum][currentDirection][k], i, j, currentPlayerNum)){
                            nextDirection = playerPrioritys[currentPlayerNum][currentDirection][k];
                            break;
                        }
                    }

                    playerBoard[i][j][p] = 2e9;
                    movePlayer(i, j, nextDirection, currentPlayerNum);
                    playerDirections[currentPlayerNum] = nextDirection;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                playerBoard[i][j] = nextPlayerBoard[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                nextPlayerBoard[i][j].clear();
            }
        }
                        
        // 모든 플레이어 이동 후 경쟁
        killCompetitors();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(contractDayBoard[i][j] > 0) {
                    contractDayBoard[i][j]--;
                } 
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int p = 0; p < playerBoard[i][j].size(); p++) {
                    contract(i, j, playerBoard[i][j][p]);
                }
            }
        }
        // printContractBoard();

        if(isEnd()) break;
        turn++;
    }

    if(turn >= 1000) turn = -1;

    cout << turn;

    return 0;
}