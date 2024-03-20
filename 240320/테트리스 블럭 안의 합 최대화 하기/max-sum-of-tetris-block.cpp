#include <iostream>
#include <vector>

using namespace std;

int map[205][205];

vector<vector<pair<int,int>>> tetris = {{{0,0},{0,1},{0,2},{0,3}}, 
{{0,0},{1,0},{2,0},{2,1}},
{{0,0},{0,1},{-1,1},{-2,1}},
{{0,0},{1,0},{0,1},{1,1}},
{{0,0},{1,0},{1,1},{2,1}},
{{0,0},{1,0},{1,-1},{2,-1}},
{{0,0},{1,0},{1,1},{2,0}}};

int main() {
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int maxtot = -2e9;
    for(int starty = 0; starty < n; starty++){
        for(int startx = 0; startx < m; startx++) {
            for(int i = 0; i < 7; i++) {
                auto current = tetris[i];
                // rotate
                for(int j = 0; j < 4; j++) {
                    int tot = 0;
                    for(int k = 0; k < current.size(); k++) {
                        auto temp = current[k];
                        current[k].first = temp.second;
                        current[k].second = -1*temp.first;

                        int nexty = starty+current[k].first;
                        int nextx = startx+current[k].second;

                        if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) {
                            tot = -1;
                            continue;
                        }
                        if(tot != -1) {
                            tot += map[nexty][nextx];
                        }
                    }
                    if(tot != -1) {
                        maxtot = max(maxtot, tot);
                    }
                }
            }
        }
    }

    cout << maxtot;

    return 0;
}