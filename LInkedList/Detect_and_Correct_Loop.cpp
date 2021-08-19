#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Node{
    int data;
    Node* next;
};
void removeNode(Node* head,Node* loop)
{
        int loop_length=0;
        Node* ptr=loop;
        Node* itr=loop;
        //Since we are in a loop then we can calculate the length of loop by keeping one ptr fixed
        //and iterating the other till it meets the ptr again
        do
        {
            loop_length++;
            itr=itr->next;
        }
        while(ptr!=itr);
        
        //cout<<loop_length<<endl;
        itr=head;
        ptr=head;
        //after calculating the length of the loop we set one ptr to head and other 
        //ptr to k locations ahead(loop_length) because the position at which these two 
        //ptrs meet is starting location of loop
        for(int i=0;i<loop_length;i++)
        {
            ptr=ptr->next;
        }
        //For iterating till head ptr meets loop lenght ptr
        while(itr!=ptr)
        {
            itr=itr->next;
            ptr=ptr->next;
        }
        //cout<<ptr->data<<endl;
        for(int i=0;i<loop_length-1;i++)
        {
            itr=itr->next;
        }
        //Since we know the loop length and starting of loop we can iterate to the last element and set to NULL
        itr->next=NULL;
    }
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *fast=head;
        Node *slow=head;
        int flag=0;
        /*Below is the implementation of loop detection algo*/
        while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            removeNode(head,fast);
    }
void pushFront(struct Node** head,int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;

    newNode->next=*head;
    *head=newNode; 
}
void addLoop(struct Node *header){
    struct Node *itr=header;
    while(itr->next!=NULL)
    {
        itr=itr->next;
    }
    cout<<itr->data<<endl;
    itr->next=header;

}
void displayList(struct Node *header)
{
    struct Node *itr=header;
    while(itr!=NULL)
    {
        printf("%d ",itr->data);
        itr=itr->next;
    }
    printf("\n");
}
int main(){
    struct Node *header=NULL;

    pushFront(&header,1);
    pushFront(&header,2);
    pushFront(&header,445);
    pushFront(&header,64);
    pushFront(&header,23);
    pushFront(&header,5);
    addLoop(header);

    removeLoop(header);
    displayList(header);

}
