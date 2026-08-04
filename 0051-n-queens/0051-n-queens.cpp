class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        nQueens(board, 0, result);
        return result;
    }

    void nQueens(vector<string> &board, int row, vector<vector<string>> &result) {
        int n = board.size();
        if (row == n) {
            result.push_back(board); 
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1, result);
                board[row][j] = '.';
            }
        }
    }

    bool isSafe(vector<string> &board, int row, int col) {
        int n = board.size();
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; j--, i--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};