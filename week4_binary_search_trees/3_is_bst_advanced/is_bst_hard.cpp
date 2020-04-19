#include<bits/stdc++.h>

using namespace std;
class node{
public:
    int key;
    node* left;
    node* right;
};
class solve{
    int n;int cheak;
    vector<int>key;vector<int>left;vector<int>right;vector<int>result;

public:
    node* newnode(int x){
        node* n=new node();
        n->key=x;
        return n;
    }
    void make_tree(node*root,int i){
        if(left[i]!=-1){
            root->left=newnode(key[left[i]]);
            //cout<<"left "<<root->left->key<<endl;
            make_tree(root->left,left[i]);
        }
        if(right[i]!=-1){
            root->right=newnode(key[right[i]]);
            //cout<<"right "<<root->right->key<<endl;
            make_tree(root->right,right[i]);
        }
        return;
    }
    void read(){
        cheak=0;
        cin >> n;
        key.resize(n),left.resize(n),right.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> key[i]>> left[i]>> right[i];
        }
    }
    void print_in_order(node* root){
        if(root==NULL)
            return;
        if(root->left!=NULL && root->key==root->left->key){cheak=1;}
        print_in_order(root->left);
        result.push_back(root->key);
        print_in_order(root->right);
    }
    bool IsBinarySearchTree() {
        node*root=newnode(key[0]);
        make_tree(root,0);
        print_in_order(root);
        int k=result.size();
        if(cheak)return false;
        for(int i=0;i<k-1;++i){
            if(result[i+1]<result[i])
                return false;
        }
      return true;
    }
    void out(){
        if(n==0){cout <<"CORRECT"<<endl;}
        else if(IsBinarySearchTree()) {
            cout <<"CORRECT"<<endl;}
        else{
            cout <<"INCORRECT"<<endl;
        }
    }
};

int main(){
    solve s;
    s.read();
    s.out();
  return 0;
}
