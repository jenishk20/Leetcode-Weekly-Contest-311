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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        bool odd=0;
        vector<vector<int>>ans;
        map<int,vector<int>>ma;
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp;
            while(sz--)
            {
                TreeNode *curr=q.front();
                q.pop();
                
                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(odd)
                reverse(temp.begin(),temp.end());
            odd^=1;
            ma[level++]=temp;
            ans.push_back(temp);
        }
        q.push(root);
        level=0;
        while(!q.empty())
        {
            int sz=q.size();
            int idx=0;
            while(sz--)
            {
                auto ans=ma[level];
                int nn=ans.size();
                TreeNode *curr=q.front();
                q.pop();
                curr->val=ans[idx++];
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
            level++;
        }
        return root;
    }
};
