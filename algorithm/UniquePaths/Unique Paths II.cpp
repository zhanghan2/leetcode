class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> arr(row,vector<int>(col));
        for(int i = 0; i < row; i++)
        {
            if(obstacleGrid[i][0] == 1)
                break;
            else
                arr[i][0] = 1;
        }
        for(int i = 0; i < col; i++)
        {
            if(obstacleGrid[0][i] == 1)
                break;
            else
                arr[0][i] = 1;
        }
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    arr[i][j] = 0;
                else
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        return arr[row-1][col-1];
    }
};