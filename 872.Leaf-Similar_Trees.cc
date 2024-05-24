#include<iostream>
#include<vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;

        dfs(root1, &leaf1);
        dfs(root2, &leaf2);

        // for(int i=0; i<leaf1.size(); i++){
        //     cout << leaf1[i] << endl;
        // }

        // for(int i=0; i<leaf2.size(); i++){
        //     cout << leaf2[i] << endl;
        // }

        return leaf1 == leaf2;
    }

    void dfs(TreeNode* root, vector<int>* leaf){
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr) leaf->push_back(root->val);

        dfs(root->left, leaf);
        dfs(root->right, leaf);
    }
};