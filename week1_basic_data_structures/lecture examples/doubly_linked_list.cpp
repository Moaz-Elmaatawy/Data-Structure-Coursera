#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data ;
    node* next;
    node* prev;
};
void print_list(node *n ){
    while(n!=NULL){
        cout<<n->data<<" ,";
        n=n->next;
    }
}

void pushBack(node** head , node** tail ,int x){
    node* newnode= new node();
    newnode->data=x;
    newnode->next=NULL;
    if((*tail)!=NULL){
        (*tail)->next=newnode;
        newnode->prev=(*tail);
        (*tail)=newnode;
    }
    else{
        (*tail)=newnode;
        (*head)=newnode;
        newnode->data=x;
    }
}

void popBack(node** head ,node** tail ){
    if(*head==*tail){
        (*head)=(*tail)=NULL;
    }
    else if(*tail!=NULL){
        (*tail)->prev->next=NULL;
        (*tail)=(*tail)->prev;
    }

}
void add_after(node* n,int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=n->next;
    n->next->prev=newnode;
    newnode->prev=n;
    n->next=newnode;

}
void add_before(node *n, int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=n;
    n->prev->next=newnode;
    newnode->prev=n->prev;
    n->prev=newnode;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    pushBack(&head,&tail,5);
    pushBack(&head,&tail,10);
    pushBack(&head,&tail,20);
    pushBack(&head,&tail,255);
    add_after(head,65);
    add_before(head->next,5553);
    add_before(head,1);
    print_list(head);
    return 0;
}
