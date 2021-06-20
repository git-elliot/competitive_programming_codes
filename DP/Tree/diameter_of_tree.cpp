struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    int diameter(Node* root) {
    int res = 0;
    solve(root, res);
    return res;
    }
    
    
int solve(Node* root, int &res){
     if(!root) return 0;
    
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    
    int temp = 1 + max(l,r);
    int ans = max(temp, 1 + l + r);
    res = max(res,ans);
    return temp;
}

};
