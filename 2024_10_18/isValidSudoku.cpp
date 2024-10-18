#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。

示例 1：
输入：board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_map<char, int>hash;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(hash[board[i][j]] == 0) hash[board[i][j]]++;
                else return false;
            }
        }
        for(int i = 0; i < 9; i++){
            unordered_map<char, int>hash;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(hash[board[j][i]] == 0) hash[board[j][i]]++;
                else return false;
            }
        }

        int j = 0, tempi = 0, tempj = 0;
        while(j <= 6){
            int i = 0;
            while(i <= 6){
                unordered_map<char, int>hash;
                tempi = i + 3, tempj = j + 3;
                for(int m = i; m < tempi; m++){
                    for(int n = j; n < tempj; n++){
                        if(board[m][n] == '.') continue;
                        if(hash[board[m][n]] == 0) hash[board[m][n]]++;
                        else return false;
                    }
                }
                i += 3;
            }
            j += 3;
        }
        return true;
    }
};


/////////////////方法二

class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //创建行，列，块 的哈希表
        //第一个数表示 当前行（列）（块）的第几个的值
        //第二个数存储 当前行（列）（块）的值（0~8：表示表中的1~9的数）
        int row[9][9] = {0};
        int col[9][9] = {0};
        int block[3][3][9] = {0};

        int idx;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') {
                    idx = board[i][j] - '0' - 1;

                    row[j][idx]++;
                    col[i][idx]++;
                    block[i/3][j/3][idx]++;

                    //如果当前行（列）（块）的值大于 1 表示当前行（列）（块）有重复的值，返回false
                    if(row[j][idx] > 1 || col[i][idx] > 1 || block[i/3][j/3][idx] > 1) return false;
                }
            }
        }
        return true;
    }
};

