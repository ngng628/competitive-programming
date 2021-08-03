# include <bits/stdc++.h>
using namespace std;

int N, M;

void PrintGrid(const vector<vector<bool>>& grid) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (grid[y][x]) { cout << "o "; } // 表
            else            { cout << "x "; } // 裏
        }
        cout << "\n";
    }
}

int main() {
    cin >> N >> M;
    vector<vector<bool>> grid(N, vector<bool>(M, true));
    
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                	// グリッドの範囲を超えなければ、9近傍を反転
                    int ty = y+dy;
                    int tx = x+dx;
                    if (0 <= ty && ty < N && 0 <= tx && tx < M) {
                        grid[y+dy][x+dx] = !grid[y+dy][x+dx];
                    }
                }
            }
        }
    }
    PrintGrid(grid);
    
    return 0;
}
