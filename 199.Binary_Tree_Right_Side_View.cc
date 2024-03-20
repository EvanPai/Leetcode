#include<vector>
#include<queue>

using namespace std;
// key : binary tree, BFS
/*  explain:
    use BFS to do the level order traversal of binary tree.
    when a level is traversed, the last node will be the one we can see, so we save that node's value in a vector.

    BFS : 
        1. Use a queue
        2. put root into the queue
        3. while queue is not empty, do things
        4. put more nodes into the queue, to continue the breadth first search
*/



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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> view;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while(!nodesQueue.empty()){
            int levelSize = nodesQueue.size();

            for(int i=0; i<levelSize; i++){
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();

                // the last node of this level
                if(i == levelSize-1) view.push_back(currentNode->val);

                // BFS
                if(currentNode->left) nodesQueue.push(currentNode->left);
                if(currentNode->right) nodesQueue.push(currentNode->right);
            }
        }
        return view;
    }
};