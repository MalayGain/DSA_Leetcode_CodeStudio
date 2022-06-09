vector<int> twoSum(vector<int>& numbers, int target) {
        
        int start=0;
        int end=numbers.size()-1;
        
        vector<int> ans;
        while(start<end)
        {
            if(numbers[start]+numbers[end]>target)
            {
                end--;
            }
            else if(numbers[start]+numbers[end]<target)
            {
                start++;
            }
            else
            {
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
        }
        
        return ans;
    }
