class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int tofind = target - nums[i];
            auto k = find(nums.begin() + i + 1, nums.end(), tofind);
            if(k != nums.end())
            {
                res.push_back(i);
                res.push_back(k - nums.begin());
                break;
            }
        }
        return res;
    }
};