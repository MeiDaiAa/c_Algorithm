#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
你一个 m x n 的矩阵 mat，其中每一行的元素均符合 严格递增 。请返回 所有行中的 最小公共元素 。

如果矩阵中没有这样的公共元素，就请返回 -1。

 

示例 1：

输入：mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
输出：5
示例 2:

输入：mat = [[1,2,3],[2,3,4],[2,3,5]]
输出： 2
*/

class Solution {
public:
    //数组保存每个数出现的次数
    int smallestCommonElement(vector<vector<int>>& mat) {
        int len = mat.size();
        int num[10001] = {0};

        for(auto& v : mat){
            for(auto& i : v){
                ++num[i];
            }
        }

        for(int i = 0; i < 10001; ++i){
            if(num[i] == len) return i;
        }
        return -1;
    }
    //优化， 一旦发现出现的次数等于mat元素个数，就直接返回
    int smallestCommonElement2(vector<vector<int>>& mat) {
        int len = mat.size();
        int num[10001] = {0};

        for(auto& v : mat){
            for(auto& i : v){
                if(++num[i] == len) return i;
            }
        }
        
        return -1;
    }
    //二分查找
    int smallestCommonElement3(vector<vector<int>>& mat) {
        int len = mat.size();
        vector<int> pos(len);

        for(auto& i : mat[0]){
            bool flag = true;

            for(int idx = 1; idx < len && flag; ++idx){
                pos[idx] = lower_bound(mat[idx].begin() + pos[idx], mat[idx].end(), i) - mat[idx].begin();
                
                if(pos[idx] == mat[0].size()) return -1;

                flag = mat[idx][pos[idx]] == i;
            }
            if(flag) return i;
        }
        return -1;
    }
    //优化查找：保存mat每个数组的下标，从下标开始查找
    int smallestCommonElement4(vector<vector<int>>& mat) {
        int len = mat.size();
        vector<int> pos(len);

        for(auto& i : mat[0]){
            bool flag = true;

            for(int idx = 1; idx < len && flag; ++idx){
                pos[idx] = lower_bound(mat[idx].begin() + pos[idx], mat[idx].end(), i) - mat[idx].begin();
                
                if(pos[idx] == mat[0].size()) return -1;

                flag = mat[idx][pos[idx]] == i;
            }
            if(flag) return i;
        }
        return -1;
    }
};