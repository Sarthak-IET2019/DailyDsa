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
class Solution {
public:

   int solve(TreeNode * node,int rob,map<pair<TreeNode*,int>,int>&dp){

        if(!node) return 0;
        if(dp.find({node,rob})!=dp.end()) return dp[{node,rob}];
        
        int temp1=INT_MIN,temp2=INT_MIN;

        if(rob==0)// possible to rob the node
        temp1=max({temp1,(solve(node->left,!rob,dp)+solve(node->right,!rob,dp)+node->val),(solve(node->left,rob,dp)+solve(node->right,rob,dp))});

        else temp2= max(temp2,solve(node->left,!rob,dp)+solve(node->right,!rob,dp));

        dp[{node,rob}]=max(temp1,temp2);
        return max(temp1,temp2);
    }
    int rob(TreeNode* root) {

        map<pair<TreeNode*,int>,int>dp;
        return solve(root,0,dp);
        
    }
};