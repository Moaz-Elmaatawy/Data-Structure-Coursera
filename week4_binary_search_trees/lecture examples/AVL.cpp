#include<bits/stdc++.h>

using namespace std;

class node{
public:
    int key;
    int h;
    node* parent;
    node* left;
    node* right;
};

node* Find(node *parent,int x)
{
    if(x==parent->key)
    {
        return parent;
    }
    else if(x > parent->key)
    {
        if(parent->right!=NULL)
            return Find(parent->right,x);
        return parent;
    }
    else if(x<parent->key)
    {
        if(parent->left!=NULL)
            return Find(parent->left,x);
        return parent;
    }
}

node* Next(node*n){
    if(n->right!=NULL){
        n=n->right;
        while(n->left!=NULL){n=n->left;}
        return n;
    }
    else{
        int x=n->key;
        if(n->parent==NULL){
            return n;
        }
        else{
            while((n->parent)->key <x){n=n->parent;}
            return (n->parent);
        }
    }
}


node*Insert(node*n,int x){
    node*temp=Find(n,x);
    node*newnode=new node();
    newnode->key=x;
    newnode->h=1;
    newnode->parent=temp;
    if(temp->key>x){
        temp->left=newnode;
    }
    else{
        temp->right=newnode;
    }
    return newnode;
}

void Delete(node** n){
    if((*n)->right==NULL){
        (*n)=(*n)->left;
    }
    else{
        node* x=Next(*n);
        (*n)->key=(x)->key;
        if(x->parent->right->key==x->key)
            x->parent->right=x->right;
        else
            x->parent->left=x->right;
    }
}

int height(node*n){
    if(n==NULL)
        return 0;
    else
        return n->h;
}

node* Rotate_left(node* x){
    node* p=x->parent;
    node* y=x->right;
    node* t=y->left;
    y->parent=p;
    y->left=x;
    x->right=t;
    x->parent=y;
    if(t!=NULL)t->parent=x;
    if(p!=NULL){
        if(y->key>p->key)
            p->right=y;
        else
            p->left=y;
    }

    x->h=1 +max(height(x->left),height(x->right));
    y->h=1 +max(height(y->left),height(y->right));
    return y;
}
node* Rotate_right(node* x){
    node*p=x->parent;
    node* y=x->left;
    node* t=y->right;
    y->parent=p;
    y->right=x;
    x->left=t;
    x->parent=y;
    if(t!=NULL)t->parent=x;
    if(p!=NULL){
        if(y->key>p->key)
            p->right=y;
        else
            p->left=y;
    }
    x->h=1 +max(height(x->left),height(x->right));
    y->h=1 +max(height(y->left),height(y->right));
    return y;
}
void Rebalance(node*n,node**root){
    node*c=n;
    node*p=n->parent;
    //cout<<n->key<<" ";
    if(height(n->left)>height(n->right)+1){
        cout<<" left";
        node*m=n->left;
        if(height(m->right)>height(m->left))
            n->left=Rotate_left(m);
        c=Rotate_right(n);
    }
    if(height(n->right)>height(n->left)+1){
        cout<<" right";
        node*m=n->right;
        if(height(m->left)>height(m->right))
            n->right=Rotate_right(m);
        c=Rotate_left(n);
    }
    n->h=1+max(height(n->left),height(n->right));
    if(p!=NULL){
        Rebalance(p,root);
    }
    else{
        //cout<<"key= "<<c->key<<" "<<(*no)->key<<endl;
        (*root)=c;
    }
}
void AVL_insert(node** head,int key){
    node* N=Insert(*head,key);
    Rebalance(N,head);
}

void print_in_order(node* head){
    if(head==NULL){
        return;
    }
    print_in_order(head->left);cout<<head->key<<",";
    print_in_order(head->right);
}
int main(){
    node* root=new node();
    root->key=10;
    root->h=1;
    AVL_insert(&root,20);
    AVL_insert(&root,30);
    AVL_insert(&root,40);
    AVL_insert(&root,50);
    AVL_insert(&root,60);
    AVL_insert(&root,9);
    AVL_insert(&root,8);
    AVL_insert(&root,45);
    AVL_insert(&root,5);
    AVL_insert(&root,11);

    cout<<endl<<"order\n";
    print_in_order(root);
    //cout<<root->key<<endl;
    return 0;
}
