#include<bits/stdc++.h>

//vector<vector<int>> dp(1001,vector<int>(1001,-1));

int dp[1001][1001];

 int profit(vector<int> &values, vector<int> &weights,int n,int w)
 {
    
     
     if(n==0 || w==0)return  0;
     
     if(dp[n][w]!=-1)return  dp[n][w];
       
   
     if(weights[n-1]<=w)
     {
          dp[n][w] =max(values[n-1]+ profit(values,weights,n-1,w-weights[n-1]),profit(values,weights,n-1,w));
     }
     else
     {
         dp[n][w] =profit(values,weights,n-1,w);
     }
     
     
     return  dp[n][w];
 }




int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    
    memset(dp,-1,sizeof(dp));
    
    return profit(values,weights,n,w);
    
}
