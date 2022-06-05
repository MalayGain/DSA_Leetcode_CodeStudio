class Solution {
public:
    vector<vector<int>> ans;
    
    void permutations(vector<int> nums,vector<int> tmp)
    {
        
        if(tmp.size()==nums.size())
        {
            ans.push_back(tmp);
            return;
        }
            
        for(int i=0;i<nums.size();i++)
        {
            if(find(tmp.begin(),tmp.end(),nums[i])!=tmp.end())continue;
            
            tmp.push_back(nums[i]);
            permutations(nums,tmp);
            tmp.pop_back();
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
      
        vector<int> tmp;
        
        permutations(nums,tmp);
        
        return ans;
            
    }
};
