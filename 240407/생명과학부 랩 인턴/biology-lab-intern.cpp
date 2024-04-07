#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m, k;
vector< vector< pair< pair<int, int>, int> > > map;
vector< vector< pair< pair<int, int>, int> > > mcopy;

vector<pair<int, int>> virsuses;
int diry[4] = {-1, 1, 0, 0};
int dirx[4] = {0, 0, 1, -1};

int totalvirus = 0;

void printvirus() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << map[i][j].second;
        }
        cout << '\n';
    }
}

void catchvirus(int col) {
    for(int i = 0; i < n; i++) {
        if(map[i][col].second == 0) continue;

        totalvirus += map[i][col].second;
        map[i][col].second = 0;
        return;
    }
}

void resetcopy() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mcopy[i][j] = {{0, 0}, 0};
        }
    }
}

void movevirus() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j].second == 0) continue;

            auto currentvirus = map[i][j];
            int currentdiry = diry[currentvirus.first.second];
            int currentdirx = dirx[currentvirus.first.second];
            int currentspeed = currentvirus.first.first;

            int nexty = i + currentdiry*currentspeed;
            int nextx = j + currentdirx*currentspeed;

            while(nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) {
                if(nexty < 0) {
                    nexty *= -1;
                    currentvirus.first.second++;
                }
                if(nexty >= n) {
                    nexty = (n-1) - (nexty - (n-1));
                    currentvirus.first.second--;
                }
                if(nextx < 0) {
                    nextx *= -1;
                    currentvirus.first.second--;
                }
                if(nextx >= m) {
                    nextx = (m-1) - (nextx - (m-1));
                    currentvirus.first.second++;
                }
            }

            if(mcopy[nexty][nextx].second != 0) {
                auto prevvirus = mcopy[nexty][nextx];
                if(prevvirus.second < currentvirus.second) {
                    mcopy[nexty][nextx] = currentvirus;
                }
            } else {
                mcopy[nexty][nextx] = currentvirus;
            }
        }
    }

    map = mcopy;
    resetcopy();
}

int main() {

    cin >> n >> m >> k;
    map = vector< vector< pair< pair<int, int>, int> > > (n, vector<pair< pair<int, int>, int>> (m));
    mcopy = vector< vector< pair< pair<int, int>, int> > > (n, vector<pair< pair<int, int>, int>> (m));
    
    int x, y, s, d, b;
    for(int i = 0; i < k; i++) {
        cin >> x >> y >> s >> d >> b;
        map[x-1][y-1] = {{s, d-1}, b};
    }

    for(int col = 0; col < m; col++) {
        catchvirus(col);
        movevirus();
    }

    cout << totalvirus;

    return 0;
}