class Solution {
public:
    bool solve(vector<vector<char>>& board,
               int i,
               int j,
               string& word,
               int index) {

        if (index == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (board[i][j] != word[index]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            solve(board, i + 1, j, word, index + 1) ||
            solve(board, i - 1, j, word, index + 1) ||
            solve(board, i, j + 1, word, index + 1) ||
            solve(board, i, j - 1, word, index + 1);

        board[i][j] = temp; 

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (solve(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};
