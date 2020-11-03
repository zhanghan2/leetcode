class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums,0);
        return res;
    }
    
    //以idx为首元素，对其后面的的数字作全排列
    void helper(vector<vector<int>>& res, vector<int>& nums,int idx)
    {
        if(idx == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[i],nums[idx]);
            //交换首元素后，以下一个数字为首元素，继续作全排列
            helper(res,nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
};