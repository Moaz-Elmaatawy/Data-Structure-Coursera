#include<bits/stdc++.h>
using namespace std;
// Vertex of a splay tree
struct Vertex {
  int key;
  char s;
  int Size;
  Vertex* left;
  Vertex* right;
  Vertex* parent;

  Vertex(int key, char s, Vertex* left, Vertex* right, Vertex* parent)
  : key(key), s(s), left(left), right(right), parent(parent) {}
};

void update(Vertex* v) {
  if (v == NULL) return;
  v->Size = 1+ (v->left != NULL ? v->left->Size : 0) + (v->right != NULL ? v->right->Size : 0);
  if (v->left != NULL) {
    v->left->parent = v;
  }
  if (v->right != NULL) {
    v->right->parent = v;
  }
}

void small_rotation(Vertex* v) {
  Vertex* parent = v->parent;
  if (parent == NULL) {
    return;
  }
  Vertex* grandparent = v->parent->parent;
  if (parent->left == v) {
    Vertex* m = v->right;
    v->right = parent;
    parent->left = m;
  } else {
    Vertex* m = v->left;
    v->left = parent;
    parent->right = m;
  }
  update(parent);
  update(v);
  v->parent = grandparent;
  if (grandparent != NULL) {
    if (grandparent->left == parent) {
      grandparent->left = v;
    } else {
      grandparent->right = v;
    }
  }
}

void big_rotation(Vertex* v) {
  if (v->parent->left == v && v->parent->parent->left == v->parent) {
    // Zig-zig
    small_rotation(v->parent);
    small_rotation(v);
  } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
    // Zig-zig
    small_rotation(v->parent);
    small_rotation(v);
  } else {
    // Zig-zag
    small_rotation(v);
    small_rotation(v);
  }
}

// Makes splay of the given vertex and makes
// it the new root.
void splay(Vertex*& root, Vertex* v) {
  if (v == NULL) return;
  while (v->parent != NULL) {
    if (v->parent->parent == NULL) {
      small_rotation(v);
      break;
    }
    big_rotation(v);
  }
  root = v;
}

// Searches for the given key in the tree with the given root
// and calls splay for the deepest visited node after that.
// If found, returns a pointer to the node with the given key.
// Otherwise, returns a pointer to the node with the smallest
// bigger key (next value in the order).
// If the key is bigger than all keys in the tree,
// returns NULL.
Vertex* find(Vertex*& root, int key) {
  Vertex* v = root;
  Vertex* last = root;
  Vertex* next = NULL;
  while (v != NULL) {
    if (v->key >= key && (next == NULL || v->key < next->key)) {
      next = v;
    }
    last = v;
    if (v->key == key) {
      break;
    }
    if (v->key < key) {
      v = v->right;
    } else {
      v = v->left;
    }
  }
  splay(root, last);
  return next;
}

void split(Vertex* root, int key, Vertex*& left, Vertex*& right) {
  right = find(root, key);
  splay(root, right);
  if (right == NULL) {
    left = root;
    return;
  }
  left = right->left;
  right->left = NULL;
  if (left != NULL) {
    left->parent = NULL;
  }
  update(left);
  update(right);
}

Vertex* merge(Vertex* left, Vertex* right) {
  if (left == NULL) return right;
  if (right == NULL) return left;
  Vertex* min_right = right;
  while (min_right->left != NULL) {
    min_right = min_right->left;
  }
  splay(right, min_right);
  right->left = left;
  update(right);
  return right;
}

Vertex* root=NULL;
void insert(int x,char s) {
  Vertex* left = NULL;
  Vertex* right = NULL;
  Vertex* new_vertex = NULL;
  split(root, x, left, right);
  if (right == NULL || right->key != x) {
    new_vertex = new Vertex(x, s, NULL, NULL, NULL);
  }
  root = merge(merge(left, new_vertex), right);
}
void print_tree(Vertex* root){
    if(root==NULL)return;
    print_tree(root->left);
    cout<<root->Size<<",";
    print_tree(root->right);
    update(root);

}
Vertex* order_stat(Vertex*root,int k){
    int s=(root != NULL ? root->Size : 0);
    if(k==s+1)
        return root;
    else if(k<s+1)
        return order_stat(root->left,k);
    else if(k >s+1)
        return order_stat(root->right,k-s-1);
}

int main() {
    string str="moaz nabil";
    for(int i=0;i<str.size();++i)
        insert(i,str[i]);

    Vertex* left=NULL;
    Vertex* right=NULL;
    Vertex* middle=NULL;
    split(root,4,left,right);
    split(root,7,middle,right);
    right=merge(left,right);
    print_tree(right);
    cout<<endl<<order_stat(right,8)->s;
    //cout<<endl<<order_stat(right,2)->s;
    return 0;
}
