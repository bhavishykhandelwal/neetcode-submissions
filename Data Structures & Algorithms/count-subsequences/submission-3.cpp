class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if (t.length() > s.length()) {
            return 0;
        }
        return dfs(s, t, 0, 0,dp);
    }

private:
    int dfs(const string &s, const string &t, int i, int j,vector<vector<int>>&dp) {
        
        if (j == t.length()) {
            return 1;
        }
        if (i == s.length()) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int res = dfs(s, t, i + 1, j,dp);
        if (s[i] == t[j]) {
            res += dfs(s, t, i + 1, j + 1,dp);
        }
        return dp[i][j]= res;
    }
};