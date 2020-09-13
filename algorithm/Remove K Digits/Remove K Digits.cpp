#include <iostream>
#include <vector>
#include <string>

using namespace std;
string removeKdigits(string,int);
void do_once(string&);

int main()
{
    string num = "10200";
    int k = 1;
    num = removeKdigits(num, k);
    cout << num << endl;
    getchar();
    return 0;
}


string removeKdigits(string num, int k) 
{
    for(int i = 0; i < k; i++)
        do_once(num);
    return num;
}

void do_once(string& num)
{
    //字符串长度小于2，删除一个字符结果为0
    if(num.length() <= 1) 
    {
        num = "0";
        return;
    }

    //如果第二个字符为0，则应删除第一个字符
    if(num[1] == '0')
    {
        int i = 1;
        while(i < num.length() && num[i] == '0') 
            i++;
        if(i == num.length()) 
        {
            num = "0"; 
            return;
        }
        else 
            num = num.substr(i);
    }

    //如果第二个字符不为0，则应删除从左往右递增的最后一个字符
    else
    {
        int i = 0, j = 1;
        while(i < num.length() && j < num.length() && num[i] <= num[j]) 
        {
            i++; 
            j++;
        }
        num.erase(i,1);
        return;
    }
}