class Solution {
public:
    int dp[13][100001];
    
    int rec(vector<int> coins,int amount,int n){
        if(n == 0)return INT_MAX-1;
        if(amount <= 0)return 0;
        
        if(dp[n][amount] != -1)return dp[n][amount];
        
        if(coins[n-1] <= amount){
            return dp[n][amount] = min(rec(coins,amount-coins[n-1],n)+1 , rec(coins,amount,n-1));
        }
        
        return dp[n][amount] = rec(coins,amount,n-1);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        // memset(dp,-1,sizeof(dp));
        
        for(int i = 0; i < coins.size()+1; i++){
            dp[i][0] = 0;
        }
        
        for(int j = 0; j < amount+1; j++){
            dp[0][j] = INT_MAX-1;
        }
        
        for(int i = 1; i < coins.size()+1; i++){
            for(int j =1; j < amount+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1 ,dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int ans = dp[coins.size()][amount];
        if(ans == INT_MAX-1)return -1;
        
        return ans;
    }
};