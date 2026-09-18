class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row_check(9), col_check(9), box_check(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char item = board[i][j];
                if (item != '.'){
                    if (row_check[i].count(item) || col_check[j].count(item) || box_check[(i / 3) * 3 + j / 3].count(item)) return false;
                    row_check[i].insert(item);
                    col_check[j].insert(item);
                    box_check[(i / 3) * 3 + j / 3].insert(item);
                }
            }
        } 
        return true;
    }
};
