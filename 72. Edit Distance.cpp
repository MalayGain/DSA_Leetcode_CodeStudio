 vector<vector<int>> dp;
    int minOperations(string word1, string word2,int n,int m)
    {
        if(n==0)return m;
        
        if(m==0)return n;
        
        
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(word1[n-1]==word2[m-1])
        {
            return dp[n][m]= minOperations(word1,word2,n-1,m-1);
        }
        else
        {
            //insert, delete, replace
            return dp[n][m]=1+ min(minOperations(word1,word2,n,m-1),min(minOperations(word1,word2,n-1,m),minOperations(word1,word2,n-1,m-1)));
        }
    }
    
    
    
    int minDistance(string word1, string word2) {
        
        int n=word1.length();
        int m=word2.length();
        
          dp.resize(n+1,vector<int>(m+1,-1));
        
        
        return minOperations(word1,word2,n,m);
    }
