#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > dusts;
vector<vector<int> > nextdusts;

int diry[4] = {-1, 0, 1, 0};
int dirx[4] = {0, -1, 0, 1};

int n, m, t;
pair<int,int> upstorm, downstorm;

void resetnextdusts() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            nextdusts[i][j] = 0;
        }
    }
}

void printdust() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << dusts[i][j] << ' ';
        }
        cout << '\n';
    }
}

void countdust() {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += dusts[i][j];
        }
    }
    cout << ans+2;
}

void spreaddust() {
    for(int curry = 0; curry < n; curry++) {
        for(int currx = 0; currx < m; currx++) {
            if(dusts[curry][currx] == -1) continue;
            int amount = dusts[curry][currx]/5;
            for(int dir = 0; dir < 4; dir++) {
                int nexty = diry[dir] + curry;
                int nextx = dirx[dir] + currx;

                if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
                if(dusts[nexty][nextx] == -1) continue;

                nextdusts[nexty][nextx] += amount;
                nextdusts[curry][currx] -= amount;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            nextdusts[i][j] += dusts[i][j];
        }
    }
    nextdusts[upstorm.first][0] = -1;
    nextdusts[downstorm.first][0] = -1;

    dusts = nextdusts;
}

void cleanupdust() {
    for(int i = 1; i < upstorm.first; i++) {
        nextdusts[i][0] = dusts[i-1][0];
    }
    for(int i = 2; i < m; i++) {
        nextdusts[upstorm.first][i] = dusts[upstorm.first][i-1];
    }
    for(int i = upstorm.first - 1; i >= 0; i--) {
        nextdusts[i][m-1] = dusts[i+1][m-1];
    }
    for(int i = m-2; i >= 0; i--) {
        nextdusts[0][i] = dusts[0][i+1]; 
    }
    nextdusts[upstorm.first][1] = 0;
    dusts = nextdusts;
}

void cleandowndust() {
    for(int i = 2; i < m; i++) {
        nextdusts[downstorm.first][i] = dusts[downstorm.first][i-1];
    }
    nextdusts[downstorm.first][1] = 0;
    for(int i = downstorm.first+1; i < n; i++) {
        nextdusts[i][m-1] = dusts[i-1][m-1];
    }
    for(int i = m-2; i >= 0; i--) {
        nextdusts[n-1][i] = dusts[n-1][i+1];
    }
    for(int i = n-2; i > downstorm.first; i--) {
        nextdusts[i][0] = dusts[i+1][0];
    }
    dusts = nextdusts;
}

int main() {
    cin >> n >> m >> t;

    nextdusts = vector<vector<int >> (n, vector<int> (m));
    dusts = vector<vector<int >> (n, vector<int> (m));

    // 초기 상태 입력
    int stormcount = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> dusts[i][j];
            if(dusts[i][j] == -1 && stormcount == 0) {
                upstorm = {i, j}; stormcount++;
            }
            else if(dusts[i][j] == -1 && stormcount == 1) {
                downstorm = {i, j};
            }
        }
    }

    while(t--){
    // 먼지 확산
        spreaddust();
    // 돌풍 청소
        cleanupdust();
        cleandowndust();

        resetnextdusts();
    }
    countdust();

    return 0;
}