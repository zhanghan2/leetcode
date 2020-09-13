#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits);
void dfs(int row, int col, vector<string> &res, string &s, vector<string> &lib);
vector<string> res;
vector<string> lib;

int main()
{
    vector<string> v = letterCombinations("23");
    cout << v.size() << endl;
    getchar();
}

vector<string> letterCombinations(string digits)
{
    //int n = digits.size();
    string temp;
    for (auto c : digits)
    {
        if (c == '2')
            lib.push_back("abc");
        else if (c == '3')
            lib.push_back("def");
        else if (c == '4')
            lib.push_back("ghi");
        else if (c == '5')
            lib.push_back("jkl");
        else if (c == '6')
            lib.push_back("mno");
        else if (c == '7')
            lib.push_back("pqrs");
        else if (c == '8')
            lib.push_back("tuv");
        else
            lib.push_back("wxyz");
    }
    dfs(0, 0, res, temp, lib);
    return res;
}

void dfs(int row, int col, vector<string> &res, string &s, vector<string> &lib)
{
    if (s.size() == lib.size())
    {
        res.push_back(s);
        cout << s << endl;
        //s.pop_back();
        cout << "come in" << endl;
        return;
    }
    for (int i = row; i < lib.size(); i++)
    {
        col = 0;
        for (int j = col; j < lib[row].size(); j++)
        {
            s.push_back(lib[i][j]);
            dfs(i + 1, j, res, s, lib);
            s.pop_back();
        }
    }
}