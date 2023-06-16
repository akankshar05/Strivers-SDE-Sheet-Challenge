class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        map<int, vector<int>> mp;

        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second;
            if (node != NULL)
            {

                mp[line].push_back(node->val);
                if (node->left != NULL)
                {
                    q.push({node->left, line + 1});
                }
                if (node->right != NULL)
                {
                    q.push({node->right, line + 1});
                }
            }
        }

        vector<vector<int>> ans;

        for (auto i : mp)
        {
            vector<int> vec;
            for (auto j : i.second)
            {
                vec.push_back(j);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};