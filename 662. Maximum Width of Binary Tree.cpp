  int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, unsigned long long int>> q;
        
        
        q.push({root,0});
    
       
        unsigned long long int leftend;
        unsigned long long int rightend;
        
        int maxWidth=0;
        
        while(!q.empty())
        {
           int n=q.size();
            
            
            leftend =q.front().second;
            
            
            
            for(int i=1;i<=n;i++)
            {
               
                auto node=q.front().first;
                unsigned long long int idx=q.front().second;
                
                rightend=idx;
                
                q.pop();
                
                if(node->left)q.push({node->left,2*idx+1});
                    
                 if(node->right)q.push({node->right,2*idx+2});
                
            }
            
            maxWidth=max(maxWidth,(int)(rightend-leftend+1));
        }
        
        return maxWidth;
    }
