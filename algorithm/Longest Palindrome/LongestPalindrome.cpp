class Solution {
public:
    int longestPalindrome(string s) {
        //记录每个字母的出现次数
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        for(char c : s)
        {
            if(c >= 'a' && c <= 'z')
            {
                lower[c - 'a']++;
            }
            else
            {
                upper[c - 'A']++;
            }
        }
        int count = 0;
        //出现次数大于1的字母，取最接近的偶数
        for(int i = 0; i < 26; i++)
        {
            if(lower[i] > 1)
            {
                if(lower[i] % 2) count += lower[i] - 1;
                else count += lower[i];
            }
            if(upper[i] > 1)
            {
                if(upper[i] % 2) count += upper[i] - 1;
                else count += upper[i];
            }
        }
        //补充回文串中间的字母
        if(count < s.size()) count++;
        return count;
    }
};