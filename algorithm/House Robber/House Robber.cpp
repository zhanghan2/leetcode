#include <iostream>
#include <vector>

using namespace std;
int rob(vector<int>&);

int main()
{
    vector<int> nums = {1,2,3,1};
    int res = rob(nums);
    cout << res << endl;
    getchar();
    return 0;
}


int rob(vector<int>& nums) {
    int n = nums.size();
    if(n < 1)
        return 0;
    if(n == 1)
        return nums[0];
    int dp[n];
    dp[0] = nums[0];
    dp[1] = nums[0] < nums[1] ? nums[1] : nums[0];
    for(int i = 2; i < n; i++)
        dp[i] = (dp[i-2] + nums[i]) < dp[i-1] ? dp[i-1] : (dp[i-2] + nums[i]);
    return dp[n-1];
}