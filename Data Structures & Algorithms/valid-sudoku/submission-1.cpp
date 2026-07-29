class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int i,int j,int val){
        for(int row=0;row<9;row++){
            if(board[row][j]==val){
                return false;
            }
        }
        for(int col=0;col<9;col++){
            if(board[i][col]==val){
                return false;
            }
        }
        int row=(i/3)*3;
        int col=(j/3)*3;
        for(int x=row;x<row+3;x++){
            for(int y=col;y<col+3;y++){
                if(board[x][y]==val){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    int val=board[i][j];
                    board[i][j]='.';
                    if(!isSafe(board,i,j,val)){
                        return false;
                    }
                    board[i][j]=val;
                }
            }
        }
        return true;
    }
};
