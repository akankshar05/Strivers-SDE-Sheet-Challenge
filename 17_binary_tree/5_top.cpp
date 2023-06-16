//    1
// /    \
// 2    3
// /\   /\
// 4 5  6 7

// node: level  vertical
// 1: 0 0
// 2: 1, -1
// 3 : 1, 1
// 4 : 2,  -2
// 5: 2, 0
// 6 : 2,0
// 7: 2,2

// do this levelling and indexing to get the order

// level order traversal krte krte => sabse phle jo index pe aa gya
// usko hi lenge : uske baad aaye koi usi ndex pe toh wo  nhi lenge

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if (mpp.find(line) == mpp.end())
            mpp[line] = node->data;

        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
    // Your code here
}