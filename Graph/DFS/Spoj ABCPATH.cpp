#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int maxlen = 0;

vector<pair<int, int>> movements = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

bool isvalid(vector<vector<char>> &grid, int x, int y) {
    return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
}

void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j, int count = 1) {
    visited[i][j] = 1;
    maxlen = max(maxlen, count);
    for (auto movement : movements) {
        int new_x = i + movement.first;
        int new_y = j + movement.second;
        if (!isvalid(grid, new_x, new_y)) continue;
        if (visited[new_x][new_y]) continue;
        if ((grid[new_x][new_y] - grid[i][j]) == 1) {
            dfs(grid, visited, new_x, new_y, count + 1);
        }
    }
}

void initial(vector<vector<char>> &grid, vector<vector<int>> &visited) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'A' && !visited[i][j]) {
                dfs(grid, visited, i, j);
            }
        }
    }
}

int main() {
   
        int n, m,k=0;
        cin >> n >> m;
        
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        initial(grid, visited);
        cout << "Case " << ++k << ": " << maxlen << '\n';
        maxlen = 0;
    return 0;
}
