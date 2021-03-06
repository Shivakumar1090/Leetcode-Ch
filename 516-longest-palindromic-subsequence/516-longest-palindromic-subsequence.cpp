class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r;
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        for(int i = n-1; i >= 0; i--)r += s[i];
        
        for(int i = 0; i < n+1; i++)dp[i][0] = dp[0][i] = 0;
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                if(s[i-1] == r[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
};