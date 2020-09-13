#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>&);

int main()
{
    vector<int> nums = {1,7,4,9,2,5};
    int res = wiggleMaxLength(nums);
    cout << res << endl;
    getchar();
    return 0;
}

int wiggleMaxLength(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> v;
    v.push_back(nums[0]);
    int i = 1, j = 1;
    while(i < nums.size())
    {
        j = i;
        if(nums[j] < v.back())
            while(j < nums.size() && nums[j] <= nums[j-1]) j++;
        else if(nums[j] > v.back())
            while(j < nums.size() && nums[j] >= nums[j-1]) j++;
        else
            while(j < nums.size() && nums[j] == nums[j-1]) j++;
        i = j;
        if(nums[j-1] != v.back())
            v.push_back(nums[j-1]);
    }
    return v.size();
}