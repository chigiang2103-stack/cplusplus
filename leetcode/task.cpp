
#include<iostream>
#include<vector>
using namespace std;

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
    struct Res {
        bool isBST ;
        long long max_val;
        long long min_val;
    };
    Res sol(TreeNode* node) {
        if (node==NULL) return {true,-100000000000,100000000000};
        Res L = sol(node->left);
        Res R  = sol(node->right);

        Res ans ;
        ans.isBST = L.isBST && R.isBST && node->val > L.max_val && node->val < R.min_val ;
        ans.max_val = max((long long)(node->val) , R.max_val);
        ans.min_val = min((long long)(node->val) , L.min_val);

        return ans;

    }




     bool isValidBST(TreeNode* root) {
        return sol(root).isBST;
    }
};