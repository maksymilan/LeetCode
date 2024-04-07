#include "all.h"
int find_max(int* array,int arraySize,int* max_index){
    int max = array[0];
    for(int i=0;i<arraySize;++i){
        if(array[i]>max){
            max = array[i];
            *max_index = i;
        }
    }
    return max;
}
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
        if(numsSize <= 0){
        return NULL;
    }
    int max_index = 0;
    int max = find_max(nums,numsSize,&max_index);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = max;
    root->left = constructMaximumBinaryTree(nums,max_index);
    root->right = constructMaximumBinaryTree(nums+max_index+1, numsSize-max_index-1);
    return root;
}
//递归函数之间慎用指针，一个通用指针在不同函数间同时使用，容易造成数据错误，比如本题如果把max_index改为一个指针，就会出现错误，但是原因未知
//向最大二叉树中插入元素
struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
    if(root == NULL){
        struct TreeNode* leaf = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        leaf->val = val;
        leaf->left = NULL;
        leaf->right = NULL;
        return leaf;
    }
    if(val > root->val){
        struct TreeNode* new_root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        new_root->val = val;
        new_root->left = root;
        new_root->right = NULL;//题目需要，必须赋值
        return new_root;
    }
    root->right = insertIntoMaxTree(root->right,val);
    return root;
}