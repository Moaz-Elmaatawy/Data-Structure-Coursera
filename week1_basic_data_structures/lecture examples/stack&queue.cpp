#include <bits/stdc++.h>

using namespace std;
class node{
public:
    int data;
    node* next;

};
void push(node** head,int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
}
void pop(node** head ){
    *head=(*head)->next;
}
int top(node *head){
    if(head!= NULL){
        return head->data;
    }
}

bool Empty(node *head){
    if(head== NULL){
        return 1;
    }
    else{
        return 0;
    }
}

/////////////////////////////////////////////////////queue///////////////////
void enque(node** head,node** tail,int x){
    node* newnode=new node();
    newnode->data=x;
    if(*tail!=NULL){
        (*tail)->next=newnode;
        *tail=newnode;
    }
    else{
        *head=*tail=newnode;
    }
}

void dequeue(node** head,node** tail){
    cout<<(*head)->data<<endl;
    *head=(*head)->next;
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    enque(&head,&tail,5);
    enque(&head,&tail,6);
    enque(&head,&tail,7);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    return 0;
}
