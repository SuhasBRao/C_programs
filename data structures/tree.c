#include<stdio.h>
#include<stdlib.h>
struct treeNode
{
    /* data */
    int data;
    struct treeNode *left;
    struct treeNode *right ;
};
// Below function adds a node to the root
struct treeNode *addNode(struct treeNode *root,int data){ 
    struct treeNode *temp= malloc(sizeof(struct treeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    struct treeNode *cur;
    if (root == NULL){
        root = temp;
        return root;
    }else{
        cur = root;
        while(1){
            //printf("Hi\n");
            if (data < root->data){
                if (root->left){
                    cur = cur->left;
                }else{
                    cur->left = temp;
                    break;
                }
            }
            else if (data > root->data){
                if (root->right){
                    cur = cur->right;
                }else{
                    cur->right = temp;
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    return root;
}

int preOrder(struct treeNode *root){
    if (root == NULL){
        return 0;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
    return 0;
}

int main(){
    int n;
    struct treeNode *root = NULL;
    root = addNode(root, 5);
    root = addNode(root,2);
    root  = addNode(root, 7);
    preOrder(root);
    return 0;
}

