// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int longestCommonSubstr (string x, string y, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        int ans = 0;
        
        for(int i = 0; i < n+1; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i < m+1; i++)dp[0][i] = 0;
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends