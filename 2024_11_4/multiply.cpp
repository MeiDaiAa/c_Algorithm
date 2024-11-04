#include <iostream>
#include <vector>

using namespace std;

/*
给定两个 稀疏矩阵 ：大小为 m x k 的稀疏矩阵 mat1 和大小为 k x n 的稀疏矩阵 mat2 ，返回 mat1 x mat2 的结果。你可以假设乘法总是可能的。


示例 1：

输入：mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
输出：[[7,0,0],[-7,0,3]]
 示例 2:

输入：mat1 = [[0]], mat2 = [[0]]
输出：[[0]]
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int len1 = mat1.size(), len2 = mat2[0].size();
        vector<vector<int>>ret(len1, vector<int>(len2));

        for(int i = 0; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                for(int x = 0; x < mat1[0].size(); ++x){
                    if(mat1[i][x] != 0) ret[i][j] += mat1[i][x] * mat2[x][j];
                }
            }
        }
        return ret;
    }
};