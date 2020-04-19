#include<bits/stdc++.h>

using namespace std;
class node{
public:
    int key;
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
    else if(x>parent->key)
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
    if(n->left==NULL&&n->right==NULL)
        return NULL;
    if(n->right!=NULL){
        n=n->right;
        while(n->left!=NULL){n=n->left;}
        return n;
    }
    else{
        int x=n->key;
        if(n->parent==NULL){
            cout<<"-1"<<endl;
            return n;
        }
        else{
            while((n->parent)->key <x){n=n->parent;}
            return (n->parent);
        }
    }
}
void Insert(node**head,int x){
    node*temp=Find(*head,x);
    node*newnode=new node();
    newnode->key=x;
    newnode->parent=temp;
    if(temp->key>x){
        temp->left=newnode;
    }
    else{
        temp->right=newnode;
    }
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

void print_in_order(node* head){
    if(head==NULL){
        return;
    }
    cout<<head->key<<",";
    print_in_order(head->left);

    print_in_order(head->right);
}
int main(){
    node* head=new node();
    node* one=new node();
    node* two=new node();
    one->key=3;
    head->key=5;
    two->key=10;
    head->left=one;
    head->right=two;
    one->parent=head;
    two->parent=head;
    Insert(&head,1);
    Insert(&head,4);
    Insert(&head,100);
    Insert(&head,9);

    print_in_order(head);
    cout<<endl<<Next(head->right->right);

    return 0;
}
