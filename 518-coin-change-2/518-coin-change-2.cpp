class Solution {
public:
    int count(vector<int> coins,int amount,int n,vector<vector<int>> &dp){
        if(amount == 0)return 1;
        if(n == 0)return 0;
        
        if(dp[n][amount] != -1)return dp[n][amount];
        
        if(coins[n-1] <= amount){
            return dp[n][amount] = count(coins,amount,n-1,dp)+count(coins,amount-coins[n-1],n,dp);
        }
        return dp[n][amount] = count(coins,amount,n-1,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        
        int c = count(coins,amount,coins.size(),dp);
        if(c == -1)return 0;
        return c;
    }
};