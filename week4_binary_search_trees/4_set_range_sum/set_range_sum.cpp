#include <cstdio>
#include<bits/stdc++.h>
// Splay tree implementation

// Vertex of a splay tree
struct Vertex {
  int key;
  // Sum of all the keys in the subtree - remember to update
  // it after each operation that changes the tree.
  long long sum;
  Vertex* left;
  Vertex* right;
  Vertex* parent;

  Vertex(int key, long long sum, Vertex* left, Vertex* right, Vertex* parent)
  : key(key), sum(sum), left(left), right(right), parent(parent) {}
};

void update(Vertex* v) {
  if (v == NULL) return;
  v->sum = v->key + (v->left != NULL ? v->left->sum : 0ll) + (v->right != NULL ? v->right->sum : 0ll);
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

// Code that uses splay tree to solve the problem

Vertex* root = NULL;


Vertex* Next(Vertex* n){
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
            return n;
        }
        else{
            while((n->parent)->key <x){n=n->parent;}
            return (n->parent);
        }
    }
}


void insert(int x) {
  Vertex* left = NULL;
  Vertex* right = NULL;
  Vertex* new_vertex = NULL;
  split(root, x, left, right);
  if (right == NULL || right->key != x) {
    new_vertex = new Vertex(x, x, NULL, NULL, NULL);
  }
  root = merge(merge(left, new_vertex), right);
}

void erase(int x) {
    //printf("DELL(%d)\n",x);
    Vertex* z=find(root,x);
    if(z!=NULL && z->key==x){
        Vertex* y=Next(z);
        if(y!=NULL){
            splay(root,y);
            find(root,x);
            if(root->right!=NULL&&root->left!=NULL){
                //printf("000000000000");
                root->right->left=root->left;
                root->left->parent=root->right;
                root->right->parent=NULL;
                root=root->right;
                update(root->left);
                update(root->right);
                update(root);

            }
            else if(root->right!=NULL&&root->left==NULL){
                //printf("1111111111111");
                root->right->parent=root->parent;
                root=root->right;

                update(root);
            }
            else if(root->left!=NULL&&root->right==NULL){
                //printf("222222222222222222");
                root->left->parent=root->parent;
                root=root->left;
                update(root);
            }
            else{
                //printf("333333333333333");
                root=NULL;
            }
        }
        else{
            //printf("outtttttttttt");
            if(z->parent==NULL){
                if(z->left!=NULL){
                    root=z->left;
                    update(root);
                }
                else
                    root=NULL;
            }
            else{
                if(z->parent->right->key==z->key){
                    z->parent->right=z->left;
                    z->left->parent=z->parent->right;
                    update(root);
                }
                else{
                    z->parent->left=z->left;
                    z->left->parent=z->parent->left;
                    update(root);
                }
            }
        }
    }
}

bool find(int x) {
    if(root==NULL||find(root,x)==NULL||find(root,x)->key!=x)
        return false;
    return true;
}
long long tree_sum(Vertex* root){
    if(root==NULL)
        return 0;
    //printf("=====%d +",root->key);
    return root->key+tree_sum(root->left)+tree_sum(root->right);
}

long long sum(int from, int to) {
  if(from>to){int temp=to;to=from;from=temp;};
  Vertex* left = NULL;
  Vertex* middle = NULL;
  Vertex* right = NULL;
  split(root, from, left, middle);
  split(middle, to +1, middle, right);
  //long long ans = tree_sum(middle);
  long long ans = 0;
  if(middle!=NULL)
    ans = middle->sum;
  middle=merge(left,middle);
  root=merge(middle,right);
  //printf("\nfrom=%d  to=%d \n",from,to);


  return ans;
}

const int MODULO = 1000000001;

int main(){
  int n;
  scanf("%d", &n);
  int last_sum_result = 0;
  for (int i = 0; i < n; i++) {
    char buffer[10];
    scanf("%s", buffer);
    char type = buffer[0];
    switch (type) {
      case '+' : {
        int x;
        scanf("%d", &x);
        insert((x + last_sum_result) % MODULO);
      } break;
      case '-' : {
        int x;
        scanf("%d", &x);
        erase((x + last_sum_result) % MODULO);
      } break;
      case '?' : {
        int x;
        scanf("%d", &x);
        printf(find((x + last_sum_result) % MODULO) ? "Found\n" : "Not found\n");
      } break;
      case 's' : {
        int l, r;
        scanf("%d %d", &l, &r);
        long long res =sum((l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO);
        printf("%lld\n", res);
        last_sum_result = int(res % MODULO);
      }
    }
  }
  return 0;
}
