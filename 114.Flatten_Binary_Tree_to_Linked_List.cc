// key : 
// image explain : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/solutions/2338791/c-explained/
/*  explain:
    naive : 
        traverse the tree in preorder, and than store each node traversed in a vector, than construct a linked list using that vector.

    better : 
        use DFS, to flatten the left subtree first, and than right subtree, that result in a preorder traverse.
        in the function, store the current right subtree, and attach the left subtree to the root->right.
        and attach the stored right subtree to the bottom of the left subtree.

    time complexity : O(n)
    space complexity : O(1)
*/



// Definition for a binary tree node.
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
    void flatten(TreeNode* root) {
        if(!root) return;

        // traverse the tree in preorder
        flatten(root->left);
        flatten(root->right);

        // store the right subtree
        TreeNode* temp = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr;

        TreeNode* curr = root;
        while(curr->right) curr = curr->right;

        curr->right = temp;
    }
};