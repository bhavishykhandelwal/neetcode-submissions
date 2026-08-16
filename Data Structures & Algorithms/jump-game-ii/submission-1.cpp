class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return dfs(nums, 0,dp);
    }
private:
    int dfs(vector<int>& nums, int i,vector<int>&dp) {
        if (i == nums.size() - 1) {
            return 0;
        }
        if (nums[i] == 0) {
            return 1000000;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int res = 1000000;
        int end = min((int)nums.size() - 1, i + nums[i]);
        for (int j = i + 1; j<=end; ++j) {
            res = min(res, 1 + dfs(nums, j,dp));
        }

        return dp[i]=res;
    }
};