#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_linkedlist(node* head);                // Function to creat linked list;
void display(node* head);                           // Functon to Print all data present into linked list;
void count(node* head);                             // Function to count the total numbers of node present into the linked list;
void search(node* head,int element);                // Function to search any element which are present into linked list or not;
node* addatbeg(node* head,int element);             // Function to add any node at begning of linked list;
node* addatend(node* head,int element);             // Function to add anu node at end of linked list;
node* addafter(node* head,int data,int element);    // Function to add any new node after a node;
node* addbefor(node* head,int data,int element);    // Function to add any new node befor a node;
node* addatpos(node* head,int pos,int element);     // Function to add any new node at given position;
node* del(node* head,int data);                     // Function to delete any node or data into the linked list;
node* reverse(node* head);                          // Function to reverse the node position of the linked list;

int main(){
    node* head=NULL;
    int choise,data,element,pos;
    while(1){
        
        printf("\n1.Create Single Linked List. \n2.Dispay the data. \n3.Count the nodes. \n4.Search the Element.\n5.Add at beginning.\n");
        printf("6.Add at end. \n7.Add after the node. \n8.Add befor the node. \n9.Add node at position. \n10.Delete the node. \n11.Reverse the List. \n");
        printf("12.Quit.\n");
        printf("Enter your choise.\n");
        scanf("%d",&choise);

        switch (choise)
        {
        case 1:
            head=create_linkedlist(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            count(head);
            break;
        case 4:
            printf("\nEnter the element to be searched: ");
            scanf("%d",&data);
            search(head,data);
            break;
        case 5:
            printf("\nEnter the data to be entered beginning of List: ");
            scanf("%d",&element);
            head=addatbeg(head,element);
            break;
        case 6:
            printf("\nEnter the data to be entered end of List: ");
            scanf("%d",&element);
            head=addatend(head,element);
            break;
        case 7:
            printf("\nEnter the data  after which new data has to be entered: ");
            scanf("%d",&data);
            printf("\nEnter the New data: ");
            scanf("%d",&element);
            head=addafter(head,data,element);
            break;
        case 8:
            printf("\nEnter the data  befor which new data has to be entered: ");
            scanf("%d",&data);
            printf("\nEnter the New data: ");
            scanf("%d",&element);
            head=addbefor(head,data,element);
            break;
        case 9:
            printf("\nEnter the position of new node: ");
            scanf("%d",&pos);
            printf("\nEnter the New data: ");
            scanf("%d",&element);
            head=addatpos(head,pos,element);
            break;
        case 10:
            printf("\nEnter data which you want to be deleted: ");
            scanf("%d",&data);
            head=del(head,data);
            break;
        case 11:
            head=reverse(head);
            break;
        case 12:
            exit(1);
        default:
            printf("\nWrong choise: \nPlease Enter choise again: ");
            break;
        }
    }
}
node* addatbeg(node* head,int element){
    node* node1=(node*)malloc(sizeof(node));
    node1->data=element;
    node1->next=head;
    head=node1;

    return head;
}

node* addatend(node* head,int element){
    node* tmp;
    tmp=head;
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=element;
    ptr->next=NULL;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=ptr;
    
    return head;
}

void display(node* head){
    node* tmp=head;
    if(tmp==NULL){
        printf("\nList is empty:");
        return;
    }
    printf("\nThe data present In list are: ");
    while (tmp->next!=NULL){
        printf("%d--->",tmp->data);
        tmp=tmp->next;
    }
    printf("%d--->NULL",tmp->data);
    return;
    
}

void count(node* head){
    int count=0;
    node* p=head;
    while (p!=NULL)
    {
        count++;
        p=p->next;
    }
    printf("\nThe total count or total number of node are :%d ",count);
}


void search(node* head,int element){
    int count=0;
    node* p=head;
    while (p!=NULL)
    {
        if(element==p->data){
            printf("The element %d is found at the %d node",element,count);
            return;
        }
        p=p->next;
        count++;
    
    }

    printf("\nElement was not present in list.");
    
}

node* addafter(node* head,int data,int element){
    node*p=head;
    while (p->next!=NULL){
        if(p->data==data){
            node* tmp=p->next;
            node* new=(node*)malloc(sizeof(node));
            new->data=element;
            p->next=new;
            new->next=tmp;
            printf("\n Node is iserted sucsessfully.");
            return head;
        }
        p=p->next;
    }

    printf("\n%d not present in list. ");
    return head;
    
}

node* addbefor(node* head,int data,int element){
    node* p=head;
    if(head==NULL){
        printf("\n List is Empty.");
    }
    if(p->data==data){
        node* new=(node*)malloc(sizeof(node));
        new->data=element;
        p->next=head;
        new->next=p;
        printf("\n Node is iserted sucsessfully.");
        return head;
    }
    while(p->next!=NULL){
        if(p->next->data==data){
            node* new=(node*)malloc(sizeof(node));
            new->data=element;
            new->next=p;
            printf("\n Node is iserted sucsessfully.");
            return head;
        }
    }
}

node* addatpos(node* head,int pos,int element){
    int n=0;
    node*p=head;
    node* new=(node*)malloc(sizeof(node));
    new->data=element;
    while (p!=NULL)
    {
        n++;
        if(pos==1){
            new->next=head;
            head=new;
            return head;
        }
        if(n==pos){
            
            new->next=p->next;
            p->next=new;
            return head;
        }
       
        p=p->next;

    }
    printf("\nExact position was not found. ");
    return head;
    
}

node* del(node* head,int data){
    node* p=head;
    if(head==NULL){
        printf("\nList is empty.");
        return head;
    }
    if(head->data=data){
        node* tmp=head;
        head=head->next;
        free(tmp);
        return head;
    }
    while (p!=NULL)
    {
        if(p->next->data==data){
            node* tmp;
            tmp=p->next;
            p->next=p->next->next;
            free(tmp);
            return head;
        }
        p=p->next;
    }
    printf("\nElement %d not found.");
    return head;
    
}

node* reverse(node* head){
    node *prev,*ptr,*nextnode;
    prev=NULL;
    ptr=head;
    while(ptr!=NULL){
        nextnode=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=nextnode;
    }
    head=prev;
    return head;
}

node* create_linkedlist(node* head){
    int i,n,data;
    printf("\nEnter the number of nodes :  ");
    scanf("%d",&n);
    head=NULL;
    if(n==0){
        return head;
    }
    printf("\nEnter the element to be insert: ");
    scanf("%d",&data);
    head=addatbeg(head,data);
    for (i=2;i<=n; i++)
    {
        printf("\nEnter the element to be insert: ");
        scanf("%d",&data);
        head=addatend(head,data);
    }
    return head;
    
}
