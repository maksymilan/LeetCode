#include "all.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Max(int a,int b,int c){
    int m;
    m = a>b? a:b;
    int res;
    res = m>c? m:c;
    return res;
}
int path_diff(struct TreeNode* root,int max,int min,int* res){
    if(root == NULL)
    return 0;
    else{
        if(root->val>max)
        max = root->val;
        if(root->val<min)
        min = root->val;
        if((max-min)>*res)
        *res = max-min;
    }
    *res = Max(*res,path_diff(root->left,max,min,res),path_diff(root->right,max,min,res));
    return *res;
}
int maxAncestorDiff(struct TreeNode* root) {
    int max,min,*res;
    res = (int*)malloc(sizeof(int));
    max=root->val,min=root->val;
    *res = 0;
    int ans = path_diff(root,max,min,res);
    return ans;
}