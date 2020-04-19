#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    node *next;
};

void print_list(node *n ){
    while(n!=NULL){
        cout<<n->data<<" ,";
        n=n->next;
    }
}

void pushBack(node **n,node **tail,int x){
    node *newnode=new node();
    newnode->data=x;
    if(*n==NULL){
        (*n)=newnode;
        (*tail)=newnode;
    }
    else{
        (*tail)->next=newnode;
        (*tail)=newnode;
    }
}

void popBack(node **head,node **tail){
    if((*head) ==NULL){}
    else if((*head)->next==NULL){
        (*head)=NULL;
        (*tail)=NULL;
    }
    else{
        node *n =(*head);
        while(n->next->next!=NULL){
            n=n->next;
        }
        n->next=NULL;
        (*tail)=n;
    }

}

void pushFront(node **n,node **tail,int x){
    node *newnode=new node();
    newnode->data=x;
    if((*n)==NULL){
        (*n)=newnode;
        (*tail)=newnode;
    }
    else{
        newnode->next=(*n);
        (*n)=newnode;
    }
}

void popFront (node **head,node **tail){
    if((*head)==(*tail)&& *head !=NULL ){
        (*head)=(*tail)=NULL;
    }
    else if(*head != NULL){
        *head=(*head)->next;
    }

}

void addAfter(node *n,int x){
    node *newnode=new node();
    newnode->data=x;
    newnode->next=n->next;
    n->next=newnode;
}


int main(){
    node *head=NULL;
    node *tail=NULL;
    pushBack(&head,&tail ,1);
    pushBack(&head,&tail ,2);
    pushBack(&head,&tail ,3);
    pushBack(&head,&tail ,4);
    addAfter(head->next,55);
    print_list(head);
    return 0;
}
