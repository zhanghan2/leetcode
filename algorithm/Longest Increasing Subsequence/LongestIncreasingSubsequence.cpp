class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        //注意lower_bound的使用
        for(int i = 0; i < n; i++)
        {
            auto k = lower_bound(res.begin(), res.end(), nums[i]);
            if(k == res.end())
                res.push_back(nums[i]);
            else
                *k = nums[i];
        }
        return res.size();
    }
};