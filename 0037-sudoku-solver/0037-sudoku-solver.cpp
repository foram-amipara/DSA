class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }

    bool sudokuSolver(vector<vector<char>>& board, int r, int c) {
        if (r == 9) {
            return true;
        }

        int nextR = r;
        int nextC = c + 1;
        if (c + 1 == 9) {
            nextR = r + 1;
            nextC = 0;
        }

        if (board[r][c] != '.') {
            return sudokuSolver(board, nextR, nextC);
        }

        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, r, c, dig)) {
                board[r][c] = dig;
                if (sudokuSolver(board, nextR, nextC)) {
                    return true;
                }
                board[r][c] = '.';
            }
        }

        return false;
    }

    bool isSafe(vector<vector<char>>& board, int r, int c, char dig) {
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == dig) {
                return false;
            }
        }

        for (int j = 0; j < 9; j++) {
            if (board[r][j] == dig) {
                return false;
            }
        }

        int startR = (r / 3) * 3;
        int startC = (c / 3) * 3;
        for (int i = startR; i < startR + 3; i++) {
            for (int j = startC; j < startC + 3; j++) {
                if (board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }
};