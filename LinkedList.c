#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *pre;
    int info;
    struct node *next;
}node;

node* create_list(node* head);
void display(node *head);
node* addtoempty(node *head,int data);
node* addatbeg(node* head,int data);
node* addatend(node* head,int data);
node* addafter(node* head,int data,int item);
node* addbefore(node* head,int data,int item);
node* del(node* head,int data);
node* reverse(node* head);

int main(){

    int item,choice,element;
    node* head=NULL;

    while (1){
      
        printf("\n1.Create dobuly Linked List. \n2.Dispay the data.\n3.Add at beginning.\n4.Add into a empty List");
        printf("\n5.Add at end. \n6.Add after the node. \n7.Add befor the node. \n8.Delete the node. \n9.Reverse the List. \n");
        printf("10.Quit.\n");
        printf("Enter your choise.\n");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            head=create_list(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("\nEnter the data to be entered beginning of List: ");
            scanf("%d",&element);
            head=addatbeg(head,element);
            break;
        case 4:
            printf("\nEnter the element to be inseert into Empty List: ");
            scanf("%d",&element);
            head= addtoempty(head,element);
            break;
        case 5:
            printf("\nEnter the data to be entered end of List: ");
            scanf("%d",&element);
            head=addatend(head,element);
            break;
        case 6:
            printf("\nEnter the data  after which new data has to be entered: ");
            scanf("%d",&item);
            printf("\nEnter the New data: ");
            scanf("%d",&element);
            head=addafter(head,element,item);
            break;
        case 7:
            printf("\nEnter the data  befor which new data has to be entered: ");
            scanf("%d",&item);
            printf("\nEnter the New data: ");
            scanf("%d",&element);
            head=addbefore(head,element,item);
            break;
        case 8:
            printf("\nEnter data which you want to be deleted: ");
            scanf("%d",&element);
            head=del(head,element);
            break;
        case 9:
            head=reverse(head);
            break;
        case 10:
            exit(1);
        default:
            printf("\nWrong choise: \nPlease Enter choise again: ");
            break;
        }
    }
}

node* create_list(node* head){
    int i,n,data;
    printf("\nEnter the total Number of node: ");
    scanf("%d",&n);
    head=NULL;
    if(n==0){
        return head;
    }
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&data);
    head=addtoempty(head,data);
    for(i=2;i<=n;i++){
        printf("\nEnter the element to be inserted: ");
        scanf("%d",&data);
        head=addatend(head,data);
    }
    return head;
}
void display(node *head){

    node* p=head;
    if(p==NULL){
        printf("\nList is empty.");
        return;
    }
    printf("\nLIST is :");
    while (p!=NULL)
    {
        printf("%d--->",p->info);
        p=p->next;
    }
    printf("NULL\n");
    return;
    
}

node* addtoempty(node *head,int data){

    node *new=(node*)malloc(sizeof(node));
    new->info=data;
    new->pre=NULL;
    new->next=NULL;
    head=new;
    printf("\nNew node %d insert Sucssesful.",data);

    return head;
}

node* addatbeg(node* head,int data){

    node* new=(node*)malloc(sizeof(node));
    new->info=data;
    new->pre=NULL;
    new->next=head;
    head=new;
    printf("\nNew node %d insert Sucssesful.",data);

    return head;

}

node* addatend(node* head,int data){

    node* new,* p;
    new=(node*)malloc(sizeof(node));
    p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    new->info=data;
    p->next=new;
    new->next=NULL;
    new->pre=p;
    printf("\nNew node %d insert Sucssesful.",data);
    
    return head;
}

node* addafter(node* head,int data,int item){

    node *p,*new;
    new=(node*)malloc(sizeof(node));
    p=head;
    new->info=data;
    while (p!=NULL)
    {
        if(item==p->info){
            new->next=p->next;
            new->pre=p;
            if(p->next!=NULL){
                p->next->pre=new;
            }
            p->next=new;
            printf("\nNew node insert after data %d Sucssesful.",item);
            return head;
        }

        p=p->next;
    }
    printf("\n%d data not present in list.",item);
    return head;
}
node* addbefore(node* head,int data,int item){
    node *p,*new;
    if(head==NULL){
        printf("\nList is empty.");
        return head;
    }
    if(head->info==item){
        new=(node*)malloc(sizeof(node));
        new->info=data;
        new->pre=NULL;
        new->next=head;
        head->pre=new;
        head=new;
        printf("\nNew node insert before data %d Sucssesful.",item);
        return head;
    }
    p=head;
    while (p!=NULL)
    {
        if(p->info==item){
            new=(node*)malloc(sizeof(node));
            new->info=data;
            new->pre=p->pre;
            new->next=p;
            p->pre->next=new;
            p->pre=new;
            printf("\nNew node insert before data %d Sucssesful.",item);
            return head;
            
        }
        p=p->next;
    }
    printf("\n%d data is not present in this LIST.",item);
    return head;
}

node* del(node* head,int data){
    node*p;
    if (head==NULL)
    {
        printf("\nLIST is empty.");
        return head;
    }
    if (head->next==NULL)
    {
        if(head->info==data){
            p=head;
            head=NULL;
            free(p);
            printf("\nNode deleted sucssesfully.");
            return head;
        }
        else{
            printf("\nElement %d is not found.",data);
            return head;
        }
    }
    if(head->info==data){
        p=head;
        head=head->next;
        head->pre=NULL;
        free(p);
        printf("\nNode deleted sucssesfully.");
        return head;
    }
    p=head->next;
    while (p->next!=NULL)
    {
        if(p->info==data){
            p->pre->next=p->next;
            p->next->pre=p->pre;
            free(p);
            printf("\nNode deleted sucssesfully.");
            return head;
        }
        p=p->next;
    }
    if(p->info==data){
        p->pre->next=NULL;
        free(p);
        printf("\nNode deleted sucssesfully.");
        return head;
    }
    printf("\nElement %d is not found.",data);
    return head;
    
}
node* reverse(node* head){
    node *p,*q;
    p=head;
    q=p->next;
    p->next=NULL;
    p->pre=q;
    while (q!=NULL){
        q->pre=q->next;
        q->next=p;
        p=q;
        q=q->pre;
    }
    head=p;
    printf("\n Revers of List is done.");
    return head;
    
}