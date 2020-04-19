#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
class node{
public:
 int key ;
 node* left;
 node*right;
};

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  node *root;


public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  node* newnode(int x){
    node *n=new node();
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

  }
  void print_in_order(node* root){
    if(root==NULL)
        return;
    print_in_order(root->left);
    cout<<root->key<<" ";
    print_in_order(root->right);
  }
  void print_pre_order(node* root){
    if(root==NULL)
        return;
    cout<<root->key<<" ";
    print_pre_order(root->left);
    print_pre_order(root->right);
  }
  void print_post_order(node* root){
    if(root==NULL)
        return;
    print_post_order(root->left);
    print_post_order(root->right);
    cout<<root->key<<" ";
  }
  void in_order() {
    root=newnode(key[0]);
    make_tree(root,0);
    print_in_order(root);
    cout<<"\n";
    print_pre_order(root);
    cout<<"\n";
    print_post_order(root);
    cout<<"\n";
  }

};

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in_order();
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

