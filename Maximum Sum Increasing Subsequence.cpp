int maxIncreasingDumbbellsSum(vector<int> &nums, int n)
{
	// Write your code here
   
        
        vector<int> lis=nums;
        
        int LIS=lis[0];
        
        for(int i=n-2;i>=0;i--)
        {
            int mx=0;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    mx=max(mx,lis[j]);
                }
                
                
            }
            
            lis[i]+=mx;
                
            LIS=max(LIS,lis[i]);
        }
        
        
        return LIS;
    
}
