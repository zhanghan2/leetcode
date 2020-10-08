class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int arr[n2+1][n1+1];
        for(int i = 0; i <= n1; i++) arr[0][i] = i;
        for(int i = 0; i <= n2; i++) arr[i][0] = i;
        for(int i = 1; i <= n2; i++)
        {
            for(int j = 1; j <= n1; j++)
            {
                //当前字母相同时不需要变动，不同的话三种变动选择一种
                if(word1[j-1] == word2[i-1])
                    arr[i][j] = arr[i-1][j-1];
                else
                    arr[i][j] = min_num(arr[i-1][j],arr[i][j-1],arr[i-1][j-1])+1;
            }
        }
        return arr[n2][n1];
    }
    
    int min_num(int a,int b,int c)
    {
        int res = a;
        res = res < b ? res : b;
        res = res < c ? res : c;
        return res;
    }
    
};
