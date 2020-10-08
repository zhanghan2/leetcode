class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        //标记是否能跳到该位置
        bool arr[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            arr[i] = false;
        if(nums[0] == 0) return false;
        for(int i = 0; i < nums.size() && i <= nums[0]; i++)
            arr[i] = true;
        for(int i = 1; i < nums.size(); i++)
        {
            int step = nums[i];
            if(!arr[i])
                return false;
            if(step == 0)
                continue;
            //标记所有能跳到的地方
            for(int j = i + 1; j < nums.size() && j <= i + step; j++)
            {
                arr[j] = true;
                if(arr[nums.size()-1])
                    return true;
            }
        }
        if(arr[nums.size()-1])
                return true;
        else
            return false;
    }
};