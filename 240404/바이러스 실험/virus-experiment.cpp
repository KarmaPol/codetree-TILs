#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

vector<int> virus[15][15];
vector<int> next_virus[15][15];

int food[15][15];
int next_food[15][15];

int delta[15][15];

pair<int,int> dirs[8] = {{1,0}, {1,1}, {0,1}, {-1,1}, {1,0}, {-1,-1}, {0,-1}, {1,-1}};

bool inRange(int y, int x) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void breed(int y, int x) {
    for(int i = 0; i < 8; i++) {
        int ny = y + dirs[i].first, nx = x + dirs[i].second;
        if(inRange(ny, nx)) {
            next_virus[ny][nx].push_back(1);
        }
    }
}

void simulate() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            next_virus[i][j].clear();
            next_food[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sort(virus[i][j].begin(), virus[i][j].end());

            for(int k = 0; k < virus[i][j].size(); k++) {
                int age = virus[i][j][k];
                if(food[i][j] >= age) {
                    food[i][j] -= age;
                    next_virus[i][j].push_back(age+1);
                }

                else {
                    next_food[i][j] += age/2;
                }
            }

            next_food[i][j] += food[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < next_virus[i][j].size(); k++) {
                int age = next_virus[i][j][k];
                if(age % 5 == 0) {
                    breed(i, j);
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            next_food[i][j] += delta[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            virus[i][j] = next_virus[i][j];
            food[i][j] = next_food[i][j];
        }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> delta[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int r, c, age;
        cin >> r >> c >> age;
        virus[r-1][c-1].push_back(age);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            food[i][j] = 5;
        }
    }

    while(k--) {
        simulate();
    } 

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += virus[i][j].size();
        }
    }
    cout << ans;

    return 0;
}