#include <iostream>
using namespace std;
int uniquePaths(int, int);

int main()
{
    int row, col;
    int res;
    cin >> col >> row;
    res = uniquePaths(col,row);
    cout << res << endl;
    system("pause");
}


int uniquePaths(int m, int n) {
    int arr[n][m];

    //最后一行和最后一列都只有一条路径到达终点
    for(int i = 0; i < m; i++) arr[n-1][i] = 1;
    for(int i = 0; i < n; i++) arr[i][m-1] = 1;
    arr[n-1][m-1] = 1;

    //位置(i,j)处的路径数为右边、下边两个点的路径数之和
    for(int i = n - 2; i >= 0; i--)
        for(int j = m - 2; j >= 0; j--)
            arr[i][j] = arr[i+1][j] + arr[i][j+1];

    return arr[0][0];
}