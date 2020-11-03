class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //排序便于跳过相同元素
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int firstnum = 0;
        //固定第一个元素后，将3数求和转换为2数求和
        while(firstnum < nums.size())
        {
            int secondnum = firstnum + 1;
            int thirdnum = nums.size() - 1;
            while(secondnum < thirdnum)
            {
                int tofind = -nums[firstnum];
                int sum = nums[secondnum] + nums[thirdnum];
                if(sum < tofind)
                    secondnum++;
                else if(tofind < sum)
                    thirdnum--;
                else
                {
                    vector<int> temp(3,0);
                    temp[0] = nums[firstnum];
                    temp[1] = nums[secondnum];
                    temp[2] = nums[thirdnum];
                    res.push_back(temp);
                    //跳过重复元素
                    while(secondnum < thirdnum && nums[secondnum] == temp[1])
                        secondnum++;
                    while(secondnum < thirdnum && nums[thirdnum] == temp[2])
                        thirdnum--;
                }
            }
            firstnum++;
            //跳过重复元素
            while(firstnum < nums.size() && nums[firstnum] == nums[firstnum-1])
                firstnum++;
        }
        return res;
    }
};