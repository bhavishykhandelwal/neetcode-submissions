class Solution {
public:
    
    bool isSafe(int i, int j, vector<vector<char>>& board, char value) {

        for(int col = 0; col < 9; col++) {
            if(board[i][col] == value) return false;
        }

        for(int row = 0; row < 9; row++) {
            if(board[row][j] == value) return false;
        }

        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;

        for(int r = startRow; r < startRow + 3; r++) {
            for(int c = startCol; c < startCol + 3; c++) {
                if(board[r][c] == value) return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] != '.') {   
                    char value = board[i][j];
                    board[i][j] = '.';
                    if(!isSafe(i, j, board, value)) {
                        return false;
                    }
                    board[i][j] = value;
                }
            }
        }

        return true;
    }
};