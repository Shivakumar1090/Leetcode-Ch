// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {
        long long int dp[n+1] = {0};
        sort(S , S+m);
        dp[0] = 1;
        
        for(int i = 0; i < m; i++){
            for(int rupees = 1; rupees <= n; rupees++){
                if(S[i] <= rupees){
                    dp[rupees] += dp[rupees-S[i]];
                }
            }
        }
        
        return dp[n];
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