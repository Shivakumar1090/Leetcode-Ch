// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int l1 = s.length() , l2 = t.length();
        
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        
        for(int i = 0; i < l1+1; i++){
            dp[i][0] = i;
        }
        
        for(int i = 0; i < l2+1; i++){
            dp[0][i] = i;
        }
        
        for(int i = 1; i < l1+1; i++){
            for(int j = 1; j < l2+1; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert = dp[i][j-1];
                    int delet = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1+min({insert,delet,replace});
                }
            }
        }
        
        return dp[l1][l2];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends