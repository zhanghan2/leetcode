class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1;
        int res = 0;
        while(lo < hi)
        {
            //计算面积
            int minnum = min(height[lo],height[hi]);
            res = max(res, minnum * (hi - lo));
            //从两边向中间逼近，宽度越来越小，如果面积增大，则只可能高度增加
            while(height[lo] <= minnum && lo < hi) lo++;
            while(height[hi] <= minnum && lo < hi) hi--;
        }
        return res;
    }
}; 