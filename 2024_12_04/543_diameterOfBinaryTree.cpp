class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return help(root->left) + help(root->right);
    }
    int help(TreeNode* root){
        if(root == nullptr) return 0;

        return 1 + max(help(root->left), help(root->right));
    }
};