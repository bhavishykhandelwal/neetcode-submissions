class Solution {
public:
    bool solve(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }

        int n=nums.size();
        if(i>=n){
            return false;
        }
        
        if(dp[target][i]!=-1){
            return dp[target][i];
        }
        bool notTake=solve(nums,target,i+1,dp);
        bool take=false;
        if(target>=nums[i]){
            take=solve(nums,target-nums[i],i+1,dp);
        }
        return dp[target][i]=notTake||take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        if(sum%2==0){
            return solve(nums,target,0,dp);
        }
        else{
            return false;
        }
    }
};
