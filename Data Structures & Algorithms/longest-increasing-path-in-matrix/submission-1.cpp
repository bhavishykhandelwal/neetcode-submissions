class Solution {
public:
    int solve(vector<vector<int>>& matrix, int r, int c, int preVal,vector<vector<int>>&dp) {

        if(r < 0 || c < 0 ||
           r >= matrix.size() ||
           c >= matrix[0].size() ||
           matrix[r][c] <= preVal) {
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }

        int res = 1;

        res = 1 + max({
            solve(matrix, r+1, c, matrix[r][c],dp),
            solve(matrix, r-1, c, matrix[r][c],dp),
            solve(matrix, r, c+1, matrix[r][c],dp),
            solve(matrix, r, c-1, matrix[r][c],dp)
        });

        return dp[r][c]=res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int ans = 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {

                ans = max(ans,
                    solve(matrix, i, j, INT_MIN,dp));
            }
        }

        return ans;
    }
};