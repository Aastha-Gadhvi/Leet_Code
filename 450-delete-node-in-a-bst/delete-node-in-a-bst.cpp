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
    TreeNode* minNode(TreeNode* node){
        TreeNode* curr=node;
        while(curr && curr->left !=NULL){
            curr=curr->left;
        }
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        //if (root==NULL) return;
        if (!root) return root;
        if(key<root->val) root->left=deleteNode(root->left,key);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else{
            if(!root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }else if(!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            TreeNode* temp=minNode(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
        return root;
    }
};