#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9];
        bool col[9][9];
        bool block[3][3][9];

        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(block, false, sizeof(block));


        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int idx = board[i][j] - '0' - 1;

                    row[j][idx] = true;
                    col[i][idx] = true;
                    block[i/3][j/3][idx] = true;
                }
            }
        }
        help(row, col, block, board);
    }

    bool help(bool row[9][9], bool col[9][9], bool block[3][3][9], vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    for(int idx = 0; idx < 9; ++idx){
                        if(row[j][idx] == false && col[i][idx] == false && block[i/3][j/3][idx] == false){
                            board[i][j] = '1' + idx;

                            row[j][idx] = true;
                            col[i][idx] = true;
                            block[i/3][j/3][idx] = true;

                            if(help(row, col, block, board)) return true;
                            
                            board[i][j] = '.';

                            row[j][idx] = false;
                            col[i][idx] = false;
                            block[i/3][j/3][idx] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};


//////////////////回溯改进/////////////
//通过pair数组记录空位的坐标,这样只需要遍历空位即可
class Solution2 {
public:
    bool row[9][9];
    bool col[9][9];
    bool block[3][3][9];
    vector<pair<int, int>> spaces;
    bool valid = false;

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(block, false, sizeof(block));

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') spaces.emplace_back(i, j);
                else{
                    int idx = board[i][j] - '0' - 1;
                    row[i][idx] = col[j][idx] = block[i/3][j/3][idx] = true;
                }
            }
        }
        dfs(board, 0);
    }
private:
    void dfs(vector<vector<char>>& board, int pos){
        if(pos == spaces.size()){
            valid = true;
            return;
        }

        auto[i, j] = spaces[pos];

        for(int idx = 0; idx < 9; idx++){
            if(!row[i][idx] && !col[j][idx] && !block[i/3][j/3][idx] && !valid){
                board[i][j] = '1' + idx;
                row[i][idx] = col[j][idx] = block[i/3][j/3][idx] = true;

                dfs(board, pos + 1);
                
                row[i][idx] = col[j][idx] = block[i/3][j/3][idx] = false;
            }
        }
    }
};




//////////////////验证方法
class Identity{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
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

                    if(row[j][idx] > 1 || col[i][idx] > 1 || block[i/3][j/3][idx] > 1) return false;
                }
            }
        }
        return true;
    }
};