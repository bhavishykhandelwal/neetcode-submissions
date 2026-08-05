class Solution {
public:
    bool isSafe(int r, int c, vector<string>& board) {

        // Check same column
        for(int i = r - 1; i >= 0; i--) {
            if(board[i][c] == 'Q')
                return false;
        }
        // Check left diagonal
        for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        // Check right diagonal
        for(int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(int n, vector<string>& board, vector<vector<string>>& ans, int r) {
        if(r == n) {
            ans.push_back(board);
            return;
        }
        for(int c = 0; c < n; c++) {
            if(isSafe(r, c, board)) {
                board[r][c] = 'Q';
                solve(n, board, ans, r + 1);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(n, board, ans, 0);

        return ans;
    }
};