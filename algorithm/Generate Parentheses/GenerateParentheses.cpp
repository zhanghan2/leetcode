class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        helper(res,s,n,0);
        return res;
    }
    
    void helper(vector<string>& res,string s,int leftnum,int rightnum)
    {
        if(leftnum == 0 && rightnum == 0)
        {
            res.push_back(s);
            return;
        }
        //先添加左括号，后添加有括号，这样不会产生冗余的错误字符串
        if(leftnum > 0) helper(res,s+'(',leftnum-1,rightnum+1);
        if(rightnum > 0) helper(res,s+')',leftnum,rightnum-1);
    }
};