//level order traversal without using queue

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
struct treeNode *addNode(struct treeNode *root, int data){ 
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
//Code here
void levelOrder(struct treeNode *root, int n){

    struct treeNode **arr = malloc(n * sizeof(struct treeNode *));// array of pointers to nodes.
    struct treeNode *cur = root;
     // add frst element as root for array of pointers
    int cnt = 0; // cnt incremented each time loop runs
    arr[0] = root;
    arr[1]= NULL; // add second element as null for the dynamic array of pointers.
    while(arr){ // runs as long as there is element in the arr(array of pointers)
        cur = arr[cnt];
        
        int i = 0;
        while (arr[i]){
            i+=1; 
        }
        //printf("%d ",i);
        arr[i] = cur->left;
        arr[i+1]= cur->right;

        printf("%d ",cur->data);
        
        cnt=cnt+1;

    }

}


//
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
    n = 2;
    //root = addNode(root, 5);
    root = addNode(root,2);
    root  = addNode(root, 7);
    //root  = addNode(root, 3);
    //root  = addNode(root, 6);

    preOrder(root); 
    printf("Level order traversal of tree is: ");
    levelOrder(root,n);
    return 0;
}

