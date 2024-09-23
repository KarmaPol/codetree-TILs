#include <iostream>
using namespace std;

int n, m;

int map[10][10];

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int maxTotal = -2e9;
    for(int range = 0; range < n-1; range++) {
        int maxSum1 = -2e9, maxSum2 = -2e9;
        for(int w1 = 0; w1 <= range; w1++) {
            for(int w2 = w1; w2 <= range; w2++) {
                for(int h1 = 0; h1 < m; h1++) {
                    for(int h2 = h1; h2 < m; h2++) {
                        int sum = 0;
                        for(int h = h1; h <= h2; h++) {
                            for(int w = w1; w <= w2; w++) {
                                sum += map[w][h];
                            }
                        }
                        maxSum1 = max(maxSum1, sum);
                    }
                }
            }
        }
        for(int w1 = range+1; w1 < n; w1++) {
            for(int w2 = w1; w2 < n; w2++) {
                for(int h1 = 0; h1 < m; h1++) {
                    for(int h2 = h1; h2 < m; h2++) {
                        int sum = 0;
                        for(int h = h1; h <= h2; h++) {
                            for(int w = w1; w <= w2; w++) {
                                sum += map[w][h];
                            }
                        }
                        maxSum2 = max(maxSum2, sum);
                    }
                }
            }
        }
        // cout << maxSum1 << " " << maxSum2 << '\n';
        maxTotal = max(maxTotal, maxSum1 + maxSum2);
    }

    for(int range = 0; range < m-1; range++) {
        int maxSum1 = -2e9, maxSum2 = -2e9;
        for(int w1 = 0; w1 <= range; w1++) {
            for(int w2 = w1; w2 <= range; w2++) {
                for(int h1 = 0; h1 < n; h1++) {
                    for(int h2 = h1; h2 < n; h2++) {
                        int sum = 0;
                        for(int h = h1; h <= h2; h++) {
                            for(int w = w1; w <= w2; w++) {
                                sum += map[h][w];
                            }
                        }
                        maxSum1 = max(maxSum1, sum);
                    }
                }
            }
        }
        for(int w1 = range+1; w1 < m; w1++) {
            for(int w2 = w1; w2 < m; w2++) {
                for(int h1 = 0; h1 < n; h1++) {
                    for(int h2 = h1; h2 < n; h2++) {
                        int sum = 0;
                        for(int h = h1; h <= h2; h++) {
                            for(int w = w1; w <= w2; w++) {
                                sum += map[h][w];
                            }
                        }
                        maxSum2 = max(maxSum2, sum);
                    }
                }
            }
        }
        // cout << maxSum1 << " " << maxSum2 << '\n';
        maxTotal = max(maxTotal, maxSum1 + maxSum2);
    }

    cout << maxTotal << '\n';

    return 0;
}