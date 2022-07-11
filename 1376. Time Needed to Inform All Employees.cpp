 int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
           if(i!=headID)adj[manager[i]].push_back(i);
        }
        
        queue<int> q;
        
        q.push(headID);
        
        vector<int> time(n,0);
        
        int ans=0;;
        
        while(!q.empty())
        {
            int m=q.size();
            
            
            for(int i=1;i<=m;i++)
            {
                int cur=q.front();
                
               
                q.pop();
                
                for(auto e:adj[cur])
                {
                    time[e]+=time[cur]+informTime[cur];
                    
                    ans=max(ans,time[e]);
                    q.push(e);
                }
                    
                    
                
            }
         
        }
        
        return ans;
    }
