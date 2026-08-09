class Solution {
public:
    int solve(vector<int>&nums,int currIndex,int prevIndex,vector<vector<int>>&dp){
        int n=nums.size();
        if(currIndex>=n){
            return 0;
        }
        if(dp[prevIndex+1][currIndex]!=-1){
            return dp[prevIndex+1][currIndex];
        }
        int notTake=solve(nums,currIndex+1,prevIndex,dp);
        int take=0;
        if(prevIndex==-1||nums[currIndex]>nums[prevIndex]){
            take=1+solve(nums,currIndex+1,currIndex,dp);
        }
        return dp[prevIndex+1][currIndex]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // int count=INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(nums,0,-1,dp);
        return ans;
    }
};
