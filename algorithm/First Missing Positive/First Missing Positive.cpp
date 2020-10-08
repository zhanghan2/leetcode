class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i = 0; i < n; i++)
        {
            //将元素的值与索引对应起来
            while(nums[i] > 0 && nums[i] <= n && nums[i] != i + 1)
            {
                //处理重复元素
                if(nums[i] == nums[nums[i]-1])
                    break;
                swap(nums[i], nums[nums[i]-1]);
            }
                
        }
        for(i = 0; i < n; i++)
        {
            if(nums[i] != i + 1)
                break;
        }
        return i + 1;
    }
};