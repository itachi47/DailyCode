//https://leetcode.com/problems/cousins-in-binary-tree/

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

    pair<TreeNode*, int> dfs(TreeNode* root, int x, TreeNode* parent, int depth, pair<TreeNode*, int> &p) {
        if(!root)
            return {};
        dfs(root->left, x, root, depth+1, p);
        dfs(root->right, x, root, depth+1, p);
        if(root->val == x){
            p = make_pair(parent, depth);
        }
        return p;


    }
    bool isCousins(TreeNode* root, int x, int y) {
        ios_base::sync_with_stdio(0);
        pair<TreeNode*, int> p, pp;
        p = dfs(root, x, root, 0, p);
        cout << endl;
        pp = dfs(root, y, root, 0, pp);
        cout << p.second << " " << pp.second;
        return (p.first != pp.first and p.second == pp.second);
    }
};
