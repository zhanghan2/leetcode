class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //ascii码表长度为128，可用于表示所有字符是否出现
        int arr[128];
        int lo = 0, hi = 0, res = 0, n = s.length();
        for(int i = 0; i < 128; i++)
            arr[i] = -1;
        while(hi < n)
        {
            //当前字符在前面已经出现，从前面出现的地方右边一个字符开始继续移动
            if(arr[s[hi]] >= lo)
                lo = arr[s[hi]] + 1;
            //前面没有出现，则标记此字符出现位置
            else
            {
                arr[s[hi]] = hi;
                hi++;
            }
            res = max(res, hi - lo);
        }
        res = max(res, hi - lo);
        return res;
    }
};