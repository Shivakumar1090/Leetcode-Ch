class Solution {
public:
    int lcs(string word1,string word2,int l1,int l2 ,vector<vector<int>> &m){
        if(l1 == 0)return m[l1][l2]=l2;
        if(l2 == 0)return m[l1][l2]=l1;
        
        if(m[l1][l2] != -1)
            return m[l1][l2];
        
        if(word1[l1-1] == word2[l2-1]){
            return m[l1][l2] = lcs(word1,word2,l1-1,l2-1,m);
        }
        
        int insertC = lcs(word1,word2,l1,l2-1,m);
        int deleteC = lcs(word1,word2,l1-1,l2,m);
        int replace = lcs(word1,word2,l1-1,l2-1,m);
        
        return m[l1][l2] = 1+min({insertC , deleteC,replace});
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.length() , l2 = word2.length();
        
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        
        for(int i = 0; i < l1+1; i++){
            dp[i][0] = i;
        }
        
        for(int i = 0; i < l2+1; i++){
            dp[0][i] = i;
        }
        
        dp[0][0] = 0;
        
        for(int i = 1; i < l1+1; i++){
            for(int j = 1; j < l2+1; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insertChar = dp[i][j-1];
                    int deleteChar = dp[i-1][j];
                    int replaceChar = dp[i-1][j-1];
                    dp[i][j] = 1+min({insertChar,deleteChar,replaceChar});
                }
            }
        }
        
        return dp[l1][l2];
    }
};
