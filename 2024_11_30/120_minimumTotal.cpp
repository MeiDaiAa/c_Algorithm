#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//回溯
// class Solution {
//     const int MAX = 0x3f3f3f3f;
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();       
//         vector<vector<int>> memo(m, vector<int>(m, MAX));
//         memo[0][0] = triangle[0][0];

//         function<int(int, int)> dfs = [&](int x, int y) -> int{
//             if(x < 0 || y < 0 || y > x) return MAX;
//             if(memo[x][y] != MAX) return memo[x][y];
            
//             memo[x][y] = min(dfs(x - 1, y), dfs(x - 1, y - 1)) + triangle[x][y];
//             return memo[x][y];
//         };
//         int minPath = MAX;
//         for(int i = 0; i < m; ++i){
//             minPath = min(dfs(m - 1, i), minPath);
//         }
//         return minPath;
//     }
// };

//递推
// class Solution {
// const int MAX = 0x3f3f3f3f;
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();       
//         vector<vector<int>> f(m, vector<int>(m, MAX));
//         f[0][0] = triangle[0][0];

//         for(int i = 1; i < m; ++i) {
//             f[i][0] = triangle[i][0] + f[i - 1][0];
//             f[i][i] = triangle[i][i] + f[i - 1][i - 1]; 
//         }
//         for(int i = 1; i < m; ++i){
//             for(int j = 1; j < i; ++j){
//                 f[i][j] = triangle[i][j] + min(f[i - 1][j], f[i - 1][j - 1]);
//             }
//         }
//         return ranges::min(f[m - 1]);
//     }
// };

//内存优化
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();       
        vector<vector<int>> f(2, vector<int>(m));
        f[0][0] = triangle[0][0];

        for(int i = 1; i < m; ++i){
            //j == 0
            f[i % 2][0] = f[(i - 1) % 2][0] + triangle[i][0];
            for(int j = 1; j < i; ++j){
                f[i % 2][j] = triangle[i][j] + min(f[(i - 1) % 2][j], f[(i - 1) % 2][j - 1]);
            }
            //j == i
            f[i % 2][i] = f[(i - 1) % 2][i - 1] + triangle[i][i];
        }
        return ranges::min(f[(m - 1) % 2]);
    }
};