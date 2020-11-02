class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(res,nums,temp,0);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int>& nums,vector<int>& temp,int idx)
    {
        if(idx == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i = idx; i < nums.size(); i++)
        {
            //从idx位置开始，找出后面部分数组有多少个不同的值，这些值都将与当前值交换
            map<int,int> m;
            for(int j = idx; j < nums.size(); j++)
            {
                if(m.find(nums[i]) == m.end())
                    m.insert(pair<int,int>{j,nums[j]});
            }
            for(auto k = m.begin(); k != m.end(); k++)
            {
                swap(nums[i],nums[k->second]);
                temp.push_back(nums[i]);
                helper(res,nums,temp,idx+1);
                temp.pop_back();
            }
        }
    }
};