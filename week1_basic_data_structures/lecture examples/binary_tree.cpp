#include <bits/stdc++.h>

using namespace std;
class BST {
public:
    int data;
    BST* left;
    BST* right;
};

 BST* insertt(int x){
    BST *newnode=new BST();
    newnode->data=x;
    return newnode;
}
int height(BST* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int Size(BST* root){
    if(root==NULL){
        return 0;
    }
    else{
        return 1+ Size(root->left)+Size(root->right);
    }
}
void DFS_stack(BST *root){
    stack<BST*>s;
    while(!s.empty()||root!=NULL){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        cout<<root->data<<",";
        root=root->right;
    }
}
void DFS_in_order(BST *root){
    if(root==NULL){
        return;
    }
    DFS_in_order(root->left);
    cout<<root->data<<",";
    DFS_in_order(root->right);
}
void DFS_post_order(BST *root){
    if(root==NULL){
        return;
    }
    DFS_post_order(root->left);
    DFS_post_order(root->right);
    cout<<root->data<<",";
}

void DFS_pre_order(BST *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<",";
    DFS_pre_order(root->left);
    DFS_pre_order(root->right);
}
void BF(BST *root){
    if(root==NULL){
        return;
    }
    queue<BST*>q;
    q.push(root);
    while(!q.empty()){
        BST* node=q.front();
        cout<<node->data<<",";
        q.pop();
        if(node->left!=NULL){
            q.push(node->left);
        }
        if(node->right!=NULL){
            q.push(node->right);
        }
    }
}

int main(){
    BST* root=new BST();
    root->data=5;
    root->left=insertt(2);
    root->left->left=insertt(1);
    root->left->right=insertt(3);
    root->left->left->left=insertt(-5);
    root->right=insertt(10);
    root->right->left=insertt(6);
    DFS_in_order(root);
    cout<<endl;
    DFS_stack(root);
    return 0;
}
