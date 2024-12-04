#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return help(root->left, root->right);
    }
    bool help(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;

        return left->val == right->val && help(left->left, right->right) && help(left->right, right->left);
    }
};

