 int cameras=0;
    
 set<TreeNode*> covered;
    
    void dfs(TreeNode* root,TreeNode* par)
    {
        if(root)
        {
            dfs(root->left,root);
            dfs(root->right,root);
            
            if(par==NULL && covered.find(root)==covered.end() ||  covered.find(root->left)==covered.end() ||
               covered.find(root->right)==covered.end())
            {
                cameras++;
                
                covered.insert(root);
                 covered.insert(par);
                 covered.insert(root->left);
                covered.insert(root->right);
            }
        }
    }
    
    int minCameraCover(TreeNode* root) {
        
        
        covered.insert(NULL);
        
        dfs(root,NULL);
        
        
        
        
       return cameras ;
    }
