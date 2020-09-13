    #include <iostream>
    #include <vector>

    using namespace std;

    vector<int> searchRange(vector<int>&, int);

    int main()
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 6;
        vector<int> res;
        res = searchRange(nums,target);
        for(auto k : res)
            cout << k << " ";
        cout << endl;
        getchar();
        return 0;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        res.push_back(-1);
        res.push_back(-1);
        int lo = 0, hi = n;

        //两次二分查找
        //找到满足要求最左边的的数
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        if(lo < n && nums[lo] == target) res[0] = lo;
        lo = 0; hi = n;
        //找到满足要求最右边的数
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        if(lo > 0 && nums[lo-1] == target) res[1] = lo - 1;
        return res;
    }