// tree practice
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

//level order traversal means bfs(breadth first search)
vector<vector<int>> bfs(TreeNode* root){
    vector<vector<int>>ans;
    if(root == nullptr) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

//find the maximum depth of given binary tree
/*root ->  1
       2       3   
            4     6
         5
         
 here depth is 4        
*/
int maxdepth(TreeNode* root){
    if(root == nullptr) return 0;

    int leftheight = maxdepth(root->left);
    int rightheight = maxdepth(root->right);

    return 1 + max(leftheight, rightheight);
}

//check if the guven binary tree is balanced or not
/*binary tree is called balanced if height of left subtree - height right subtee 
is less than equal to 1
we will implemnt this by using the height of BT function only
*/

int checkbalanced(TreeNode* root){
    if(root==nullptr)return 1;

    int leftheight = checkbalanced(root->left);
    if(leftheight == -1) return -1;

    int rightheight = checkbalanced(root->right);
    if(rightheight == -1) return -1;

    if(abs(leftheight - rightheight) > 1) return -1;
    return 1 + max(leftheight, rightheight);
}

bool isBalanced(TreeNode* root) {
        return checkbalanced(root) != -1;
}

int height(TreeNode* node, int &diameter){
    if(!node) return 0;

    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh+rh);
    return 1 + max(lh, rh);
}

int diamater(TreeNode* root){
    int diamater = 0;
    height(root, diamater);
    return diamater;
}

int maxPathDown(TreeNode* node, int &maxi){
    if(!node) return 0;

    int leftSum = max(0, maxPathDown(node->left, maxi));
    int rightSum = max(0, maxPathDown(node->right, maxi));

    maxi = max(maxi, leftSum + rightSum + node->val);

    return max(leftSum, rightSum) + node->val;
}

int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}