class Solution {
public:
    int solve(vector<int>&coins,int i,int amount,vector<vector<int>>&dp){
      if(amount==0){
        return 1;
      }
      if(i>=coins.size()){
        return 0;
      }
      if(dp[i][amount]!=-1){
        return dp[i][amount];
      }
      int ans=0;
      int notTake=solve(coins,i+1,amount,dp);
      if(amount>=coins[i]){
        ans+=solve(coins,i,amount-coins[i],dp);
      }
      return dp[i][amount]=ans+notTake;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,0,amount,dp);
    }
};
