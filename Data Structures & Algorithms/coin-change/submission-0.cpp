class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<vector<int>>& dp, int i){

        if(amount==0){
            return 0;
        }

        if(i>=coins.size()){
            return INT_MAX-1;
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int notTake = solve(coins, amount, dp, i+1);

        int take = INT_MAX-1;

        if(amount >= coins[i]){
            take = 1 + solve(coins, amount-coins[i], dp, i);
        }

        return dp[i][amount] = min(take, notTake);
    }


    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));

        int ans = solve(coins, amount, dp, 0);

        if(ans == INT_MAX-1)
            return -1;

        return ans;
    }
};