#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    vector <node*> v;
};
node* creat_node(int x){
    node *newnode=new node();
    newnode->data=x;
    return newnode;
}

void print_tree (node* root){
    cout<<root->data<<" ,";
    if(root!=NULL){
        for(int i=0 , n=(root->v).size() ;i<n;++i){
            print_tree(root->v[i]);
        }
    }
}
int main(){
    node* root=new node();
    int n;
    cin>>n;
    vector<int>m(n);
    for(int i=0;i<n;++i){
        cin>>m[i];
    }
    for(int i=0;i<n;++i){
        m[i]
    }
    root->data=5;
    (root->v).push_back(creat_node(4));
    (root->v).push_back(creat_node(3));
    (root->v).push_back(creat_node(2));
    ((root->v[0])->v).push_back(creat_node(77));
    ((root->v[0])->v).push_back(creat_node(88));
    ((root->v[0])->v).push_back(creat_node(99));

    print_tree(root);
    return 0;
}
