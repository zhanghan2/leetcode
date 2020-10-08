class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                res = helper(board, i, j, word, 0);
                if(res)
                    return true;
            }
        }
        return false;
    }

    //dfs问题
    bool helper(vector<vector<char>>& board,int i, int j, string word,int idx)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] !=                    word[idx])
            return false;
        if(board[i][j] == word[idx] && idx == word.size() - 1)
            return true;
        //已访问位置的标记与释放标记！！！
        board[i][j] = '#';
        bool flag = helper(board, i+1, j, word, idx+1) || 
                helper(board, i-1, j, word, idx+1) ||
                    helper(board, i, j+1, word, idx+1) ||
                        helper(board, i, j-1, word, idx+1);
        board[i][j] = word[idx];
        return flag;
    } 
};