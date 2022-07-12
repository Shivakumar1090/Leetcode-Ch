// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int rec(int s[] , int m,int val,vector<vector<long long int>> &dp){
        if(val == 0)return 1;
        if(m == 0 || val < 0)return 0;
        
        if(dp[m][val] != -1)return dp[m][val];
        
        if(s[m-1] <= val){
            return dp[m][val] = rec(s,m-1,val,dp)+rec(s,m,val-s[m-1],dp);
        }
        return dp[m][val] = rec(s,m-1,val,dp);
    }
    long long int count(int s[], int m, int val) {
        // vector<vector<long long int>> dp(m+1,vector<long long int>(val+1,-1));
        
        vector<long long int> dp(val+1,0);
        dp[0] = 1;
        
        for(int i = 0; i < m; i++){
            for(int j = i; j <= val; j++){
                if(j >= s[i])
                dp[j] += dp[j-s[i]];
            }
        }
        
        return dp[val];
            // return rec(s,m,val,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends