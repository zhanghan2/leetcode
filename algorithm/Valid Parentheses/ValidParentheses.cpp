class Solution {
public:
    bool isValid(string s) {
        //使用栈
        stack<char> st;
        for(char c : s)
        {
            if(c == ')' || c == '}' || c == ']')
            {
                if(st.empty())
                    return false;
                if(c == ')')
                {
                    if(st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                else if(c == ']')
                {
                    if(st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                else
                {
                    if(st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
            }
            else
                st.push(c);
        }
        return st.empty() ? true : false;
    }
};