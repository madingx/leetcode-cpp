// Source : https://leetcode.com/problems/range-sum-of-bst/
// Author : Mading
// Date   : 2019-04-29

/*************************************************************************************** 
 * 938. Range Sum of BST [Easy]
 * Given the root node of a binary search tree, return the sum of values of 
 * all nodes with value between L and R (inclusive).

 * The binary search tree is guaranteed to have unique values.

 * Example 1:
 * Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
 * Output: 32

 * Example 2:
 * Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 * Output: 23

 * Note:
 * The number of nodes in the tree is at most 10000.
 * The final answer is guaranteed to be less than 2^31.
 *               
 ***************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 156 ms, faster than 96.64% of C++, 41.2 MB, less than 95.62% of C++
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)return 0;
        int s = 0;
        bool isL = ( root->val >= L);
        bool isR = ( root->val <= R);
        if(isL)
            s += rangeSumBST(root->left,L,R);
        if(isR)
            s += rangeSumBST(root->right,L,R);
        if(isL && isR)
            s += root->val;
        return s;        
    }
};