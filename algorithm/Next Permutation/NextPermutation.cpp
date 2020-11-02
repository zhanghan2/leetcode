class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int begin = -1;
        int n = nums.size();
        //逆序排列时数字最大，找到第一个不满足条件的数字
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                begin = i;
                break;
            }
        }
        //完全逆序排列，此时为最大值
        if(begin == -1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            //找出比nums[idx]大的最低位的数字，做交换，然后排序后面的数字
            int idx = -1;
            for(int idx = n - 1; idx > begin; idx--)
            {
                if(nums[idx] > nums[begin])
                {
                    swap(nums[begin],nums[idx]);
                    break;
                }
            }
            reverse(nums.begin()+begin+1,nums.end());
        }
        return;
    }
};