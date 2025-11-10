#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL,*newnode,*temp;

struct node* createnode(int value){
    newnode=(struct node*)malloc(sizeof (struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

void createlist(int n){
    int value;

    for(int i=0;i<n;i++){
        printf("Enter the vaLue of node %d: ",i+1);
        scanf("%d",&value);
        newnode=createnode(value);
        if(head==NULL)
            head=newnode;
        else {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
}


void displaylist(){
    temp=head;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }

    printf("Linked List:");
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


void insertatbegin(int value){
    newnode=createnode(value);
    newnode->next=head;
    head=newnode;
    printf("Node inserted at BEGinning");

}

void insertatend(int value){
    newnode=createnode(value);
    temp=head;

    if(head==NULL){
        head=newnode;
        return;
    }

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;
    printf("Node is inserted at end.\n");
}

void insertatanyposition(int value,int pos){
    newnode=createnode(value);
    temp=head;

    if(pos==-1){
        newnode->next=head;
        head=newnode;
        return;
    }

    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("InVALID POSITION\n");
        return;
    }

    newnode->next=temp->next;
    temp->next=newnode;
    printf("NODE inserted at position %d.\n",pos);
}

int main() {
    int choice, n, value, pos;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createlist(n);

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Any Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displaylist();
            break;
        case 2:
            printf("Enter value to insert: ");
             scanf("%d", &value);
            insertatbegin(value);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertatend(value);
            break;
        case 4:
            printf("Enter position and value: ");
            scanf("%d %d", &pos, &value);
            insertatanyposition(value, pos);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}


