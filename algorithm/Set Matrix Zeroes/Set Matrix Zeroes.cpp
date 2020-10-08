class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return;
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                //当前元素为0时，将相同行、列元素替换成特殊字符
                //注意其右边或者下边出现0时，不要动这个元素，之后遍历到的时候再处理
                if(matrix[i][j] == 0)
                {
                    for(int m = 0; m < row; m++)
                    {
                        if(matrix[m][j] == 0 && m > i)
                            break;
                        else
                            matrix[m][j] = '*';
                    }
                    for(int n = 0; n < col; n++)
                    {
                        if(matrix[i][n] == 0 && n > j)
                            break;
                        else
                            matrix[i][n] = '*';
                    }
                }
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == '*')
                    matrix[i][j] = 0;
        }
        return;
    }
};