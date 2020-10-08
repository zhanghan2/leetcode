class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) 
            return res;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            temp.reserve(n);
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};