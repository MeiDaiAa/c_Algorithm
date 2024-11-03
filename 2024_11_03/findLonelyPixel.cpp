#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
给你一个大小为 m x n 的图像 picture ，图像由黑白像素组成，'B' 表示黑色像素，'W' 表示白色像素，请你统计并返回图像中 黑色 孤独像素的数量。

黑色孤独像素 的定义为：如果黑色像素 'B' 所在的同一行和同一列不存在其他黑色像素，那么这个黑色像素就是黑色孤独像素。


示例 1：


输入：picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
输出：3
解释：全部三个 'B' 都是黑色的孤独像素
示例 2：


输入：picture = [["B","B","B"],["B","B","W"],["B","B","B"]]
输出：0
*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row[picture.size()];
        int lie[picture[0].size()];
        memset(row, 0, sizeof(row));
        memset(lie, 0, sizeof(lie));

        for(int i = 0; i < picture.size(); ++i){
            for(int j = 0; j < picture[0].size(); ++j){
                if(picture[i][j] == 'B'){
                    ++row[i];
                    ++lie[j];
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < picture.size(); ++i){
            if(row[i] != 1) continue;
            for(int j = 0; j < picture[0].size(); ++j){
                if(lie[j] == 1 && picture[i][j] == 'B') ++ret;
            }
        }

        return ret;
    }
};