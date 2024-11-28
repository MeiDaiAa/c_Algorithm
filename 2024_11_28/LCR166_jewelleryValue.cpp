#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

// class Solution {
// private:
//     vector<vector<int>>dp;
// public:
//     int jewelleryValue(vector<vector<int>>& frame) {
//         vector<int>temp(frame[0].size() + 1, -1);
//         dp.resize(frame.size() + 1, temp);
//         return bfs(frame, frame.size() - 1, frame[0].size() - 1);
//     }
//     int bfs(vector<vector<int>>& frame, int x, int y){
//         if(x < 0 || y < 0) return 0;
//         int &res = dp[x][y];
//         if(res != -1) return res;
//         res = max(bfs(frame, x - 1, y), bfs(frame, x, y - 1)) + frame[x][y];
//         return res;
//     }
// };
// class Solution{
// public:
//     int jewelleryValue(vector<vector<int>> &frame){
//         int m = frame.size(), n = frame[0].size();
//         //vector<vector<int>>dp(m, vector<int>(n, 0));
//         int dp[m][n];
//         memset(dp, 0, sizeof(dp));
//         function<int(int, int)> dfs = [&](int x, int y) -> int{
//             if(x < 0 || y < 0) return 0;
//             int &res = dp[x][y];
//             if(res) return res;
//             res = max(dfs(x - 1, y), dfs(x, y - 1)) + frame[x][y];
//             return res;
//         };
//         return dfs(m - 1, n - 1); 
//     }
// };

//1:1翻译成递归
// class Solution{
// public:
//     int jewelleryValue(vector<vector<int>> &grid){
//         // const int m = frame.size(), n = frame[0].size();
//         // vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
//         int m = grid.size(), n = grid[0].size(), f[m + 1][n + 1];
//         memset(f, 0, sizeof(f));

//         for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j){
//            f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]) + grid[i][j];
//         }
//         return f[m][n];
//     }
// };

//内存优化

class Solution {
public:
    int jewelleryValue(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        auto &f = grid[0];
        for (int j = 1; j < n; ++j)
            f[j] += f[j - 1];
        for (int i = 1; i < m; ++i) {
            f[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
                f[j] = max(f[j - 1], f[j]) + grid[i][j];
        }
        return f[n - 1];
    }
};