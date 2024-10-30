#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumMoves(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &mem) {
    if (mem[r][c] != -1)
        return mem[r][c];
        
    int max_moves = 0;

    if (r - 1 >= 0 && c + 1 < grid[0].size() && grid[r - 1][c + 1] > grid[r][c]) {
        max_moves = 1 + maximumMoves(r - 1, c + 1, grid, mem);
    }

    if (c + 1 < grid[0].size() && grid[r][c + 1] > grid[r][c]) {
        max_moves = max(max_moves, 1 + maximumMoves(r, c + 1, grid, mem));
    }

    if (r + 1 < grid.size() && c + 1 < grid[0].size() && grid[r + 1][c + 1] > grid[r][c]) {
        max_moves = max(max_moves, 1 + maximumMoves(r + 1, c + 1, grid, mem));
    }

    return mem[r][c] = max_moves;
}

int maxMoves(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> mem(r, vector<int> (c, -1));
    int max_moves = 0;

    for (int i = 0 ; i < r ; i++) {
        max_moves = max(max_moves, maximumMoves(i, 0, grid, mem));
    }

    return max_moves;
}

int main() {
    vector<vector<int>> grid = {
        {2,4,3,5},
        {5,4,9,3},
        {3,4,2,11},
        {10,9,13,15}
    };
    int result = maxMoves(grid);
    cout << "Maximum number of moves: " << result << endl;

    return 0;
}