class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool ispositive;
        if(x >= 0)
            ispositive = true;
        else
            ispositive = false;
        while(x)
        {
            int temp = x % 10;
            x /= 10;
            //注意防止溢出
            if(!ispositive)
            {
                if((INT_MIN / 10 > res )|| (temp < INT_MIN - res * 10))
                    return 0;
                else
                    res = res * 10 + temp;
            }
            else
            {
                if((INT_MAX / 10 < res) || (INT_MAX - res * 10 < temp))
                    return 0;
                else
                    res = res * 10 + temp;
            }
        }
        return res;
    }
};