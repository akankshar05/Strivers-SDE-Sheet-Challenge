// preorder => root left right : here do this

// in case of right view do this : root right left

void rec(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;

    // this is first time i came across to this level
    if (res.size() == level)
        res.push_back(root->data);
    rec(root->left, level + 1, res);
    rec(root->right, level + 1, res);
}
vector<int> leftView(Node *root)
{
    vector<int> vec;
    rec(root, 0, vec);
    return vec;
    // Your code here
}