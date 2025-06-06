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
    void fun(TreeNode* root,int lev,vector<vector<int>>&v){
        if(v.size()==lev) v.resize(lev+1);
        if(root==NULL)
        {
            v[lev].push_back(0);
            return;
        }
        if(v.size()==lev) v.resize(lev+1);
        v[lev].push_back(root->val);
        fun(root->left,lev+1,v);
        fun(root->right,lev+1,v);
    }
    bool isCompleteTree(TreeNode* root) {
        vector<vector<int>>v;
        fun(root,0,v);
        vector<int>ans;
        for(auto x:v)
        {
            for(auto y:x) ans.push_back(y);
        }
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]==0 && ans[i+1]!=0) return false;
        }
        return true;
    }
};