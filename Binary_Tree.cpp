/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <stack>
 using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { } //initializing the values to zero or nullptr
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode*right) : val(x), left(left), right(right) {} //overloading the constructor;
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int>v{};
        if(root==NULL){
            return v;
        }

    stack<TreeNode*> TreeNodeStack;
    TreeNodeStack.push(root);

    //pop items one by one, print it, push right child, push left child

    while(!TreeNodeStack.empty()){
        TreeNode* p_node=TreeNodeStack.top(); //point to the top of the stack
        v.push_back(p_node->val);
        TreeNodeStack.pop();

        if(p_node->right)
            TreeNodeStack.push(p_node->right);
        if(p_node->left)
            TreeNodeStack.push(p_node->left);
        }
        return v;
    }
};


int main (){




}
