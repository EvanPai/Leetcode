#include<vector>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

// key : binary tree traversal, preorder, queue,, string
/*  explain:
    To solve the problem of serializing and deserializing a binary tree, 
    we can use a preorder traversal for serialization and a queue for deserialization to maintain the order of nodes.

    Serialization
    For serialization, perform a preorder traversal (root, left, right) of the tree. 
    When encountering a NULL pointer, denote it with a special character (e.g., #). 
    Separate each value (including the NULL marker) with a delimiter (e.g., ,). 

    Deserialization
    For deserialization, use a queue to keep track of nodes' values in the order they should be reconstructed. 
    Split the serialized string by the delimiter to enqueue all values. 
    Then, recursively build the tree by dequeuing elements to form nodes, 
    using the NULL marker to identify when a subtree is empty.
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // preorder
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* helper(queue<string>& nodes){
        string val = nodes.front();
        nodes.pop();

        if(val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = helper(nodes);
        node->right = helper(nodes);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string item;
        while(getline(ss, item, ',')){
            nodes.push(item);
        }
        return helper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));