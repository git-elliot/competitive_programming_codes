#include<iostream>
using namespace std;
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
    
    
    int solve(TreeNode* root, int &res){
        if(!root) return 0;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        int temp = max(root->val + max(l,r),root->val); //I'm not the answer
        int ans = max(temp, root->val + l + r); //I'm the answer
        res = max(res, ans);
        return temp;
    }

int main(){
    //TODO: input required
    maxPathSum();
}