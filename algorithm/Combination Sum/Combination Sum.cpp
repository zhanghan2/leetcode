class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(candidates,target,res,temp,0);
        return res;
    }

    //典型回溯问题，注意函数的几个参数！！！
    void helper(vector<int>& candidates,int target,vector<vector<int>>& res,vector<int>& temp,int idx)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i = idx; i < candidates.size() && candidates[i] <= target; i++)
        {
            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i],res,temp,i);
            temp.pop_back();
        }
    }
};