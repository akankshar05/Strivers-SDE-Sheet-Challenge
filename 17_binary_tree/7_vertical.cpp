#include <vector>
#include <set>
using namespace std;

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        TreeNode *node = t.first;
        int verti = t.second.first;
        int level = t.second.second;
        mp[verti][level].insert(node->val);
        if (node->left)
            q.push({node->left, {verti - 1, level + 1}});
        if (node->right)
            q.push({node->right, {verti + 1, level + 1}});
    }

    vector<vector<int>> ans;
    for (auto i : mp)
    {
        vector<int> ver;
        for (auto j : i.second)
        {
            for (auto k : j.second)
                ver.push_back(k);
        }
        ans.push_back(ver);
    }

    return ans;
}
}
;