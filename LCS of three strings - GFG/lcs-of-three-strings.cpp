// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends



int dp[21][21][21];
int solve(string s1,string s2,string s3,int n1,int n2,int n3)
{
     if(n1==0||n2==0||n3==0)
     {
         return 0;
     }
     if(dp[n1][n2][n3]!=-1)
     {
         return dp[n1][n2][n3];
     }
     if((s1[n1-1]==s2[n2-1])&&(s2[n2-1]==s3[n3-1]))
     {
      return  dp[n1][n2][n3]=1+solve(s1,s2,s3,n1-1,n2-1,n3-1); 
     }
     else
     {
         int a =solve(s1,s2,s3,n1-1,n2,n3);
         int b=solve(s1,s2,s3,n1,n2-1,n3);
         int c=solve(s1,s2,s3,n1,n2,n3-1);
         return dp[n1][n2][n3]=max(a,max(b,c));
     }
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp,-1,sizeof(dp));
    return solve(A,B,C,n1,n2,n3);
}