#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *reverse (struct node *head, int k)
{ 
    if(head==NULL)
        return NULL;
    int i=0;

    struct node *curr=head;
    struct node *prev=NULL;
    struct node *next=NULL;
    while(i<k&&curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
         ++i;
    }
    if(next!=NULL)
        head->next=reverse(next,k);
            
    return prev;
}
void pushFront(struct node** head,int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;

    newNode->next=*head;
    *head=newNode; 
}
void displayList(struct node *header)
{
    struct node *itr=header;
    while(itr!=NULL)
    {
        printf("%d ",itr->data);
        itr=itr->next;
    }
    printf("\n");
}
int main(){
    struct node *header=NULL;

    pushFront(&header,1);
    pushFront(&header,2);
    pushFront(&header,445);
    pushFront(&header,64);
    pushFront(&header,23);
    pushFront(&header,5);
    displayList(header);
    
    header=reverse(header,3);
    displayList(header);
}