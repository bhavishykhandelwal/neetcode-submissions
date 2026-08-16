class Solution {
public:
    bool solve(vector<int>&nums,int i,vector<int>&dp){
        if(i==nums.size()-1){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int end=min((int)nums.size()-1,i+nums[i]);
        for(int j=i+1;j<=end;j++){
           if(solve(nums,j,dp)){
            return dp[i]=true;
           }
        }
        return dp[i]=false;


    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
