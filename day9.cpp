// Tree questions practice
#include <bits/stdc++.h>
using namespace std;

// Q1. count good nodes in given binary tree
//=> good node is a node which is greater than or equal to all the nodes in the path
//  from root to that node

/**
 Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int dfs(TreeNode *root, int maxVal)
{
    if (root == nullptr)
        return 0;
    int res = 0;
    if (root->val >= maxVal)
        res = 1;
    else
        res = 0;
    res += dfs(root->left, maxVal);
    res += dfs(root->right, maxVal);
    return res;
}
int goodNodes(TreeNode *root)
{
    return dfs(root, root->val);
}
