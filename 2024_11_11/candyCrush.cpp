#include <iostream>
#include <vector>
using namespace std;

/*
这个问题是实现一个简单的消除算法。

给定一个 m x n 的二维整数数组 board 代表糖果所在的方格，不同的正整数 board[i][j] 代表不同种类的糖果，如果 board[i][j] == 0 代表 (i, j) 这个位置是空的。

给定的方格是玩家移动后的游戏状态，现在需要你根据以下规则粉碎糖果，使得整个方格处于稳定状态并最终输出：

如果有三个及以上水平或者垂直相连的同种糖果，同一时间将它们粉碎，即将这些位置变成空的。
在同时粉碎掉这些糖果之后，如果有一个空的位置上方还有糖果，那么上方的糖果就会下落直到碰到下方的糖果或者底部，这些糖果都是同时下落，也不会有新的糖果从顶部出现并落下来。
通过前两步的操作，可能又会出现可以粉碎的糖果，请继续重复前面的操作。
当不存在可以粉碎的糖果，也就是状态稳定之后，请输出最终的状态。
你需要模拟上述规则并使整个方格达到稳定状态，并输出。

示例 1 :

输入: board = [[110,5,112,113,114],
               [210,211,5,213,214],
               [310,311,3,313,314],
               [410,411,412,5,414],
               [5,1,512,3,3],
               [610,4,1,613,614],
               [710,1,2,713,714],
               [810,1,2,1,1],
               [1,1,2,2,2],
               [4,1,4,4,1014]]
输出: [[0,0,0,0,0],
       [0,0,0,0,0],
       [0,0,0,0,0],
       [110,0,0,0,114],
       [210,0,0,0,214],
       [310,0,0,113,314],
       [410,0,0,213,414],
       [610,211,112,313,614],
       [710,311,412,613,714],
       [810,411,512,713,1014]]
示例 2:

输入: board = [[1,3,5,5,2],[3,4,3,3,1],[3,2,4,5,2],[2,4,4,5,5],[1,4,4,1,1]]
输出: [[1,3,0,0,0],[3,4,0,5,2],[3,2,0,3,1],[2,4,0,5,2],[1,4,3,1,1]]
*/

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int rowSize = board.size(), colSize = board[0].size();
        bool isChange = false;

        //eliminate row
        for(int row = 0; row < rowSize; ++row){
            for(int col = 0; col + 2 < colSize; ++col){
                if(board[row][col] != 0 
                    && abs(board[row][col]) == abs(board[row][col+1])
                    && abs(board[row][col]) == abs(board[row][col+2])){
                        isChange = true;
                        board[row][col] = board[row][col+1] = board[row][col+2] = -abs(board[row][col]);
                }
            }
        }
        //eliminate col
        for(int col = 0; col < colSize; ++col){
            for(int row = 0; row + 2 < rowSize; ++row){
                if(board[row][col] != 0 
                    && abs(board[row][col]) == abs(board[row+1][col]) 
                    && abs(board[row][col])== abs(board[row+2][col])){
                        isChange = true;
                        board[row][col] = board[row+1][col] = board[row+2][col] = -abs(board[row][col]);
                }
            }
        }

        //所有该消除的元素都变为了负数
        //将所有的负数都消除
        for(int col = 0; col < colSize; ++col){
            int down = rowSize - 1, upper = down;
            while(upper >= 0){
                if(board[upper][col] > 0){
                    board[down][col] = board[upper][col];
                    --down;
                }
                --upper;
            }
            while(down >= 0) board[down--][col] = 0;
        }

        return isChange ? candyCrush(board) : board;
    }
};