#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
//         dp[0][0] = 1;
        
//         function<int(int , int)> dfs = [&](int x, int y) -> int{   
//             if(x < 0 || y < 0) return 0;
//             if(obstacleGrid[x][y] == 1) return 0;
//             if(dp[x][y]) return dp[x][y];
            
//             dp[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
//             return dp[x][y];
//         };

//         return dfs(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);
//     }
// };

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int>> f(m, vector<int>(n, 0));
//         for(int i = 0; i < m; i++){
//             if(obstacleGrid[i][0] == 1) break; 
//             f[i][0] = 1;
//         }
//         for(int i = 0; i < n; i++) {
//             if(obstacleGrid[0][i] == 1) break; 
//             f[0][i] = 1;
//         }

//         for(int i = 1; i < m; ++i) for(int j = 1; j < n; j++){
//             if(obstacleGrid[i][j] == 1){
//                 f[i][j] = 0;
//             }
//             else{
//                 f[i][j] = f[i - 1][j] + f[i][j - 1];
//             }
//         }
//         return f[m -1][n - 1];
//     }
// };


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int>f(n, 0);
        f[0] = (obstacleGrid[0][0] == 1);
        for(int i = 1; i < m; ++i) for(int j = 1; j < n; j++){
            if(obstacleGrid[m][n] == 1){
                f[j] = 0;
            }
            else{
                f[j] = f[j - 1];
            }
        }
        return f[n];
    }
};