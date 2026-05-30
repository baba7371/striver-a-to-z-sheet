//tree practice 
#include<bits/stdc++.h>
using namespace std;

//binary tree fromation
class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data){
            val = data;
            left=right=nullptr;
        }
};

//Traversal techniques 
/*there are two mainly traversal techniques BFS(breadth first search)
and DFS(depth first search) int dfs further we have three inorder, preorder and
postorder traversal*/

//preorder traversal(root, left, right) using recursion

vector<int> preorder(TreeNode* root, vector<int>&res){
    if(root == nullptr) return res;

    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
    
    return res;
}

//inorder traversal using recursion(left, root, right)

vector<int> inorder(TreeNode* root, vector<int>&res){
    if(root == nullptr){
        return res;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);

    return res;
}

//postorder traversal using recursion(left, right, root)
vector<int> postorder(TreeNode* root, vector<int>&res){
    if(root == nullptr) return res;

    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);

    return res;
}

//inorder using iteration

vector<int> inorder(TreeNode* root){
    vector<int>inorder;
    stack<TreeNode*>st;
    TreeNode* node  = root;
    while(true){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}

//preorder traversal using iterative method

vector<int> preorder(TreeNode* root){
    vector<int>preorder;

    if(root == nullptr) return preorder;

    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->right != nullptr) st.push(root->right);
        if(root->left != nullptr) st.push(root->left);
    }
    return preorder;
}

//postorder iterative approach
vector<int> postorder(TreeNode* root){
    vector<int>postorder;
    if(root == nullptr) return postorder;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr) st1.push(root->left);
        if(root->right != nullptr) st1.push(root->right);

        while(!st2.empty()){
            postorder.push_back(st2.top() -> val);
            st2.pop();
        }
    }
    return postorder;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->left->left->val << " " << root->left->right->val << endl;    
    return 0;
}